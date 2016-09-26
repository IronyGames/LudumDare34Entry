#pragma once
#include "Item.h"
class Model;
class Monster;

class PotionOfHealth : public Item{
public:
	PotionOfHealth(Model *m);
	void use(Monster *m);
private:
	int healPoints;
};