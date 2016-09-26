#pragma once
#include "Typedef.h"
class Image;
class Monster;
class Animation2D;

class Item{
public:
	Item(String _name, Animation2D *_icon, unsigned int _price);
	virtual void draw();
	virtual void equip();
	virtual void unequip();
	virtual void use(Monster *m_);
	bool isEquipped();
	unsigned int getPrice();
	String getName();
private:
	String name;
	unsigned int price;
	bool equipped;
protected:
	Animation2D *icon;
};