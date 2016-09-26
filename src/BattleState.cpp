#include "BattleState.h"
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
#include "MonsterList.h"
#include "Monster.h"
#include "Hero.h"
#include "MobStats.h"

BattleState::BattleState(Model *m)
:IdleState(m)
, monsters(new MonsterList(m))
{

}

void BattleState::update()
{
	model->fpsCounter++;
	model->metronome->update();
	

	blinkCounter--;
	if (blinkCounter < 0){
		blinkCounter = 0;
	}

	if (model->input->areBothPressed()){
		toPause = true;
	}else if (toPause && model->input->areNonePressed()){
		heroDefense->start();
		model->states->pause();
		toPause = false;
	}else{

	}


	//////////////////////////////////////////////

	if (model->input->isRightPressed()){
		model->player->getSprites()->setCurrentAnimation("defense");
	}
	else if (model->input->isLeftPressed()){

		if (model->player->getSprites()->getCurrentAnimationName() != "attack"){
			model->player->getSprites()->setCurrentAnimation("aggressive");
		}
		else if (model->player->getSprites()->hasCurrentAnimationFinished()){
			model->player->getSprites()->setCurrentAnimation("aggressive");
		}
	}else if (model->input->areNonePressed()){
		model->player->getSprites()->setCurrentAnimation("idle");
	}

	model->player->update();

	if (model->metronome->hasBeatJustChanged()){

		beat->start();
		blink();
		currentMonster->update();

		if (model->input->isLeftPressed() && !model->input->areBothPressed()){ //hero attacks
			model->player->getSprites()->setCurrentAnimationAndResetCurrentLoop("attack");
			heroAttack->start();
			currentMonster->receiveDamage(model->player->attack(), currentMonster->isDefending());
		}

		int mdmg = currentMonster->attack();
		if (mdmg > 0){
			bool isPlayerDefending = model->input->isRightPressed();
			if (isPlayerDefending){
				heroDefense->start();
			}
			model->player->receiveDamage(mdmg, isPlayerDefending);
		}
	}

	if (currentMonster->isDead()){
		model->player->addMoney(currentMonster->getStats()->gold);
		coin->start();
		model->player->getSprites()->setCurrentAnimationAndResetCurrentLoop("idle");
		model->states->toIdle();
	}

	if (model->player->isDead()){
		model->states->death();
	}
}

void BattleState::draw()
{
	if (blinkCounter > 0){
		cinder::gl::clear(cinder::Color(0.33203125, 0.0, 0.0));
	}
	else{
		cinder::gl::clear(cinder::Color(0.0, 0.19921875, 0.19921875));
	}

	bgDirt->draw();
	currentMonster->draw();
	model->player->draw();
	hud->draw();
	drawHeroStats();
}

void BattleState::spawnMonster()
{
	currentMonster = monsters->pickMonster(model->difficulty);
}

void BattleState::prepareIncomingTransition()
{
	spawnMonster();
	blink();
}
