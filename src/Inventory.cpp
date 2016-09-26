#include "Inventory.h"
#include "Item.h"
#include "Offset2D.h"
#include "cinder\gl\GlslProg.h"
#include "Global.h"

Inventory::Inventory()
: selected(0)
{
	statsOffset = new Offset2D();
	statsOffset->setTranslation(Coords2Ddouble(Global::windowSize.x*0.8, Global::windowSize.y*0.4));
	statsOffset->setScale(Coords2Ddouble(3.0, 3.0));
}

void Inventory::addItem(Item* newItem)
{
	items.push_back(newItem);
}

Item* Inventory::useItem(int index)
{
	Item* out = items.at(index);
	items.erase(items.begin()+index-1);
	return out;
}

void Inventory::equip()
{
	items.at(selected)->equip();
}

int Inventory::getSelected()
{
	return selected;
}

void Inventory::drawInventory()
{
	cinder::gl::pushMatrices();
	for (int i = 0; i < items.size(); i++){

	}
	cinder::gl::popMatrices();
	//draw bg
	//draw selected bg
	//draw items
}

void Inventory::empty()
{
	items.empty();
}

void Inventory::drawShop()
{
	cinder::gl::pushMatrices();
	cinder::gl::translate(100, 0);
	for (int i = 0; i < items.size(); i++){
		cinder::gl::translate(0, 20);
		items.at(i)->draw();
	}
	cinder::gl::popMatrices();
}
