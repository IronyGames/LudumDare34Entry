#include "Item.h"
#include "Monster.h"

Item::Item(String _name, Animation2D *_icon, unsigned int _price) : name(_name)
, icon(_icon)
, price(_price)
{

}

void Item::draw()
{
	//draw icon
	//draw name
	icon->draw(true);
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
