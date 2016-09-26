#include "DeathState.h"
#include "Model.h"
#include "GameStateManager.h"
#include "cinder\gl\wrapper.h"
#include "Utils.h"

DeathState::DeathState(Model *m)
:GameState(m)
{

}

void DeathState::update()
{
	model->states->toIntro();
}

void DeathState::draw()
{
	cinder::gl::clear(Utils::rgbColor(0, 0, 0));
}
