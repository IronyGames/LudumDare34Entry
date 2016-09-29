#pragma once
#include "Typedef.h"
#include "IdleState.h"

class Animation2D;
class Model;
class PauseState : public IdleState{
public:
	PauseState(Model *m);
	void update();
	void draw();
	void drawHeroInventory();
private:
	Animation2D *pause;
};