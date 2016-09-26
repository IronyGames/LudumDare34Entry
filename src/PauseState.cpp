#include "PauseState.h"
#include "Model.h"
#include "Animation2D.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "cinder\gl\gl.h"
#include "Global.h"
#include "Keyboard.h"

PauseState::PauseState(Model *m)
:GameState(m)
{
	pause = new Animation2D("./../assets/pause.png");
	pause->setTranslation(Coords2Ddouble(Global::windowSize.x / 2 - (pause->getWidth() * 10,
		Global::windowSize.y / 2 - (pause->getHeight() * 10))));
	pause->setScale(Coords2Ddouble(10, 10));
}

void PauseState::update()
{
	if (model->input->isRightPressed()){
	}
	else if (model->input->wasRightReleased()){
		model->states->unPause();
	}
}

void PauseState::draw()
{
	model->states->getLastState()->draw();

	cinder::gl::pushMatrices();
	pause->draw();
	cinder::gl::popMatrices();
}
