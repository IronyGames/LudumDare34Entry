#include "PauseState.h"
#include "Model.h"
#include "Animation2D.h"
#include "IdleState.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "cinder\gl\gl.h"
#include "Global.h"
#include "Keyboard.h"
#include "Model.h"
#include "Metronome.h"
#include "Inventory.h"
#include "Hero.h"
#include "Offset2D.h"

PauseState::PauseState(Model *m)
:IdleState(m)
{
	pause = new Animation2D("./../assets/pause.png");
	pause->setTranslation(Coords2Ddouble(Global::windowSize.x / 2 - (pause->getWidth() * 10,
		Global::windowSize.y / 2 - (pause->getHeight() * 10))));
	pause->setScale(Coords2Ddouble(10, 10));
}

void PauseState::update()
{
	model->metronome->update();
	if (model->metronome->hasBeatJustChanged()){
		model->player->getInventory()->selectNext();
		if (model->input->wasLeftReleased()){
			model->player->use();
		}
	}
	else if (model->input->isOnlyRightPressed()){
		model->states->unPause();
	}
}

void PauseState::draw()
{
	model->states->getLastState()->draw();

	cinder::gl::pushMatrices();
	pause->draw();
	drawHeroInventory();
	cinder::gl::popMatrices();
}

void PauseState::drawHeroInventory()
{
	cinder::gl::pushMatrices();
	cinder::gl::translate(statsOffset->getTranslation());
	cinder::gl::translate(Global::windowSize.x / 100.0, Global::windowSize.y / 5.0);
	cinder::gl::scale(statsOffset->getScale());
	model->player->getInventory()->drawInventoryInSelection();
	cinder::gl::popMatrices();
}
