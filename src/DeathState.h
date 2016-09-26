#pragma once
#include "Typedef.h"
#include "GameState.h"

class Model;
class DeathState : public GameState{
public:
	DeathState(Model *m);
	void update();
	void draw();
};