#include "IntroState.h"
#include "Model.h"
#include "Keyboard.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/gl.h"
#include "Image.h"
#include "Global.h"
#include "Offset2D.h"
#include "GameStateManager.h"
#include "Animation2D.h"
#include "SpriteFontManager.h"
#include "Hero.h"
#include "ImageStorage.h"

IntroState::IntroState( Model *m )
:GameState(m)
{
	toIdle = false;
	introText = "Dancing()/     dungeon";
	currentKeyboard = KeyboardIcons::EMPTY;	

	bg = new Animation2D("./../assets/introBG.png");
	double ratio = Global::windowSize.x / bg->getImage()->getWidth();
	bg->setScale(Coords2Ddouble(ratio, ratio));

	fontOffset = new Offset2D();
	//fontOffset->setTranslation(Coords2Ddouble(Global::windowSize.x/3, Global::windowSize.y/4));
	fontOffset->setTranslation(Coords2Ddouble(Global::windowSize.x/10, Global::windowSize.y/9));
	fontOffset->setScale(Coords2Ddouble(8.5, 8.5));
	


	Coords2Ddouble kt(Global::windowSize.x / 2.0, 4.0*Global::windowSize.y / 5.0);
	//Coords2Ddouble kt(0,0);
	Coords2Ddouble ks = Coords2Ddouble(5.0,5.0);
	/*Offset2D ko = Offset2D(kt, 0, ks);*/

	keyboards[KeyboardIcons::EMPTY] = new Animation2D("./../assets/keyboardIcon_Empty.png");
	keyboards[KeyboardIcons::EMPTY]->setTranslation(kt);
	keyboards[KeyboardIcons::EMPTY]->setScale(ks);
	keyboards[KeyboardIcons::LEFT] = new Animation2D("./../assets/keyboardIcon_Left.png");
	keyboards[KeyboardIcons::LEFT]->setTranslation(kt);
	keyboards[KeyboardIcons::LEFT]->setScale(ks);
	keyboards[KeyboardIcons::RIGHT] = new Animation2D("./../assets/keyboardIcon_Right.png");
	keyboards[KeyboardIcons::RIGHT]->setTranslation(kt);
	keyboards[KeyboardIcons::RIGHT]->setScale(ks);
	keyboards[KeyboardIcons::BOTH] = new Animation2D("./../assets/keyboardIcon_Both.png");
	keyboards[KeyboardIcons::BOTH]->setTranslation(kt);
	keyboards[KeyboardIcons::BOTH]->setScale(ks);
}

void IntroState::update()
{
	if (toIdle && model->input->wereBothReleased()){
		toIdle = false;
		model->states->toIdle();
	}
	else if (model->input->areBothPressed()){
		currentKeyboard = KeyboardIcons::BOTH;
		toIdle = true;
	}
	else if (model->input->isLeftPressed()){
		currentKeyboard = KeyboardIcons::LEFT;
	}
	else if (model->input->isRightPressed()){
		currentKeyboard = KeyboardIcons::RIGHT;
	}
	else{
		currentKeyboard = KeyboardIcons::EMPTY;
	}
	
}

void IntroState::draw()
{
	cinder::gl::clear(cinder::Color(1, 0.9, 0.9));

	bg->draw(false);
	model->fonts->draw(fontOffset, introText, "font1", false);
	
	keyboards[currentKeyboard]->draw(true);
}

void IntroState::prepareIncomingTransition()
{
	model->player->reset();
}

