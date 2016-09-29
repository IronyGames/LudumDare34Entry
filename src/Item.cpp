#include "Item.h"
#include "Monster.h"
#include "SpriteFontManager.h"
#include "Offset2D.h"

Item::Item(String _name, Animation2D *_icon, unsigned int _price, SpriteFontManager *font) : name(_name)
, icon(_icon)
, price(_price)
, font(font)
{

}

void Item::drawInInventory()
{
	icon->draw(true);
}

void Item::drawInShop()
{
	icon->draw(true);

	String out = "";
	out += std::to_string(getPrice());
	out += "GP ";
	font->draw(new Offset2D(), out, "font1", false);
}

void Item::equip()
{
	equipped = true;
}

void Item::unequip()
{
	equipped = false;
}

bool Item::isEquipped()
{
	return equipped;
}

void Item::use(Monster *m)
{

}

String Item::getName()
{
	return name;
}

unsigned int Item::getPrice()
{
	return price;
}
