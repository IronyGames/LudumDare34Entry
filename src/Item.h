#pragma once
#include "Typedef.h"
class Image;
class Monster;
class Animation2D;
class SpriteFontManager;

class Item{
public:
	Item(String _name, Animation2D *_icon, unsigned int _price, SpriteFontManager *font);
	virtual void drawInInventory();
	virtual void drawInShop();
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
	SpriteFontManager *font;
	Animation2D *icon;
};