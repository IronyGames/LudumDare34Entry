#include "IdleState.h"
#include "cinder/gl/gl.h"
#include "Model.h"
#include "Animation2D.h"
#include "Global.h"
#include "Image.h"
#include "Metronome.h"
#include "cinder/audio/Voice.h"
#include "AudioStorage.h"
#include "ImageStorage.h"
#include "Keyboard.h"
#include "GameStateManager.h"
#include "SpriteFontManager.h"
#include "Offset2D.h"
#include "Hero.h"
#include "MobStats.h"

IdleState::IdleState(Model *m)
:GameState(m)
{
	toBattle = false;
	toPause = false;
	blinkCounter = 0;
	shopBeats = 0;
	beatFrequency = 1;

	bgDirt = new Animation2D(m->images->get("bg1.png"));
	double ratio = Global::windowSize.x / bgDirt->getImage()->getWidth();
	bgDirt->setScale(Coords2Ddouble(ratio, ratio));

	m->metronome->changeBeat(beatFrequency);
	int w = Global::windowSize.x;
	int h = Global::windowSize.y;

	hud = new Animation2D(m->images->get("hud.png"));
	int hh = h / hud->getHeight();
	hud->setScale(Coords2Ddouble(hh, hh));
	hud->setTranslation(Coords2Ddouble(w - hud->getWidth(), 0));
	
	statsOffset = new Offset2D();
	statsOffset->setTranslation(Coords2Ddouble(w - ((17*hud->getWidth())/20), ((1*hud->getHeight())/40)));
	statsOffset->setScale(Coords2Ddouble(3.0, 3.0));

	model->player->getSprites()->setScale(Coords2Ddouble(hh,hh));
	model->player->getSprites()->translate(Coords2Ddouble((2.0*w / 5.0)-75, h-100));

	shop = new Animation2D(m->images->get("shop_door.png"));
	shop->setScale(Coords2Ddouble(hh, hh));
	shop->translate(Coords2Ddouble((1.0*w / 5.0) - shop->getWidth(), 15 + h - (shop->getHeight())));
	
	beat = m->sounds->get("beat.ogg");
	heroAttack = m->sounds->get("attack.ogg");
	heroDefense = m->sounds->get("shield.ogg");
	heroHurt = m->sounds->get("hurt.ogg");
	coin = m->sounds->get("win.ogg");
}

void IdleState::update()
{
	model->metronome->update();

	if (model->metronome->hasBeatJustChanged()){
		//beat sound
		beat->start();
		
		model->player->update();
	}
	blinkCounter--;
	if (blinkCounter < 0){
		blinkCounter = 0;
	}

	if (model->input->areBothPressed()){
		toPause = true;
	}
	else if (toPause && model->input->areNonePressed()){
		heroDefense->start();
		model->states->pause();
		toPause = false;
	}
	else if (shopBeats > 0 && model->input->isLeftPressed()){
		heroDefense->start();
		model->states->shop();
		shopBeats = 0;
	}

	
	//////////////////////////////////////////////

	if (model->metronome->hasBeatJustChanged()){
		if (toBattle){
			model->states->battle();
			toBattle = false;
			shopBeats = 0;
			model->metronome->reset();
		}
		else{
			shopBeats--;
			if (shopBeats < 0){
				shopBeats = 0;
			}

			blink();
			evaluateBeat();
		}
	}
}

void IdleState::draw()
{
	if (blinkCounter > 0){
		cinder::gl::clear(cinder::Color(0.0, 0.265625, 0.0));
	}else{
		cinder::gl::clear(cinder::Color(0.0, 0.19921875, 0.19921875));
	}
	
	bgDirt->draw();
	if (shopBeats != 0){
		shop->draw();
	}
	model->player->draw();
	hud->draw();
	drawHeroStats();
}

#include <math.h>
void IdleState::evaluateBeat()
{
	int r = rand() % 100;
	if (r < 10){
		if (shopBeats == 0){
			shopBeats = beatFrequency * 4;
		}
	}
	else if (r < 35){
		toBattle = true;
	}
	else{

	}
}

void IdleState::blink()
{
	blinkCounter = model->metronome->getFramesInBeat() / 2;
}

void IdleState::drawHeroStats()
{
	MobStats *ms = model->player->getStats();

	String out = "HP ";
	out += std::to_string(ms->currentHP);
	out += "/AT ";
	out += std::to_string(ms->atk);
	out += " DE ";
	out += std::to_string(ms->def);
	out += "/WE()";
	out += " SH[]";
	out += "/PO{}";
	model->fonts->draw(statsOffset, out, "font1", false);
}

void IdleState::prepareIncomingTransition()
{
	blink();
}
