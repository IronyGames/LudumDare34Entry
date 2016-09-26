#pragma once
#include "Typedef.h"
class Monster;
class Model;
class MonsterList{
public:
	MonsterList(Model *m);
	Monster* pickMonster(unsigned int difficulty);
private:
	std::vector<Monster*> monsters;
};