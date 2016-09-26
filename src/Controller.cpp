#include "Controller.h"
#include "Model.h"
#include "Keyboard.h"
#include "GameStateManager.h"
#include "GameState.h"
#include "cinder/Color.h"
#include "cinder/gl/gl.h"
#include "LD34_IronyGamesApp.h"

Controller::Controller( LD34_IronyGamesApp *_app ) 
:model(new Model(_app))
{
	model->states->shop();
// 	model->states->toIdle();
// 	model->states->battle();
}

Controller::~Controller()
{
	delete model;
}

void Controller::update()
{
	model->states->getCurrentState()->update();
}

void Controller::draw()
{
	model->states->getCurrentState()->draw();
}

void Controller::onKeyDown(int keyCode)
{
	model->input->down(keyCode);
}

void Controller::onKeyUp(int keyCode)
{
	model->input->up(keyCode);
}
