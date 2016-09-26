#pragma once
#include "Typedef.h"
#include "IdleState.h"

class Model;
class MonsterList;
class Monster;
class BattleState : public IdleState{
public:
	BattleState(Model *m);
	void update();
	void draw();
	void spawnMonster();
	void prepareIncomingTransition();
private:
	Animation2D *enemy;
	MonsterList *monsters;
	Monster *currentMonster;
};