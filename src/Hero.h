#pragma once
#include "Monster.h"
class Model;
class Inventory;
class Item;

class Hero : public	Monster{

public:
	Hero(Model *m);
	void move();
	void equip();
	void defend();
	unsigned int attack();
	void use();
	void obtain(Item *i);
	void draw();
	void update();
	unsigned int receiveDamage(int _dmg, bool wasDefending = false);
	void addMoney(int pieces);
	void reset();
private:
	Hero(int _maxHP, int _currentHP, int _atk, int _def, int _gold);
	void setSpriteSheet();
	Inventory *inventory;
};