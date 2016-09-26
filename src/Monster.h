#pragma once
#include "Typedef.h"
#include "Spritesheet.h"
class MobStats;
class Inventory;
class Model;
class Monster{
private:
	String actions;
	int currentAction;
protected:
	int difficulty;
	MobStats *stats;
	Inventory *inventory;
	Spritesheet sprites;
	String name;
	Monster();
	Monster(String _name, int _maxHP, int _currentHP, int _atk, int _def, int _gold, Spritesheet _sprites, String _actions, int _difficulty = 1);
	Monster(String _name, int _maxHP, int _currentHP, int _atk, int _def, int _gold, String _actions, int _difficulty = 1);
	void setSpritesheet(Spritesheet _sprites);
public:
	Monster(Model *m);
	
	int getDifficulty();
	virtual void update();
	virtual void draw();
	virtual unsigned int attack();
	bool isDefending();
	Monster* spawn();
	MobStats* getStats();
	Spritesheet* getSprites();
	virtual unsigned int receiveDamage(int _dmg, bool wasDefending = false);
	bool isDead();
	virtual void heal(int heal);
	virtual void fullHeal();
};