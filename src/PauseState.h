#pragma once
#include "Typedef.h"
#include "GameState.h"

class Animation2D;
class Model;
class PauseState : public GameState{
public:
	PauseState(Model *m);
	void update();
	void draw();
private:
	Animation2D *pause;
};