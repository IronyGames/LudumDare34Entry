#include "Inventory.h"
#include "Item.h"
#include "Offset2D.h"
#include "cinder\gl\GlslProg.h"
#include "Global.h"
#include "Animation2D.h"

Inventory::Inventory(Animation2D *selectIcon, unsigned int size /*=-1000*/)
: selected(0), selectedIcon(selectIcon), size(size)
{
	statsOffset = new Offset2D();
	statsOffset->setTranslation(Coords2Ddouble(Global::windowSize.x*0.8, Global::windowSize.y*0.4));
	statsOffset->setScale(Coords2Ddouble(3.0, 3.0));
}

bool Inventory::addItem(Item* newItem)
{
	if (items.size() <= size){
		items.push_back(newItem);
		return true;
	}
	return false;
}

Item* Inventory::useItem()
{
	Item* out = items.at(getSelected());
	items.erase(items.begin() + getSelected());
	selected--;
	if (selected < 0){
		selected = 0;
	}
	return out;
}

void Inventory::equip()
{
	items.at(selected)->equip();
}

void Inventory::selectNext()
{
	selected++;
	if (selected >= items.size()){
		selected = 0;
	}
}


int Inventory::getSelected()
{
	return selected;
}

void Inventory::drawInventory()
{
	/*cinder::gl::pushMatrices();
	for (int i = 0; i < items.size(); i++){

	}
	cinder::gl::popMatrices();
	//draw bg
	//draw selected bg
	//draw items*/

	cinder::gl::pushMatrices();
	
	for (int i = 0; i < items.size(); i++){
		items.at(i)->drawInInventory();
		cinder::gl::translate(0, 20);
		/*if (i == selected){
			cinder::gl::pushMatrices();
			cinder::gl::translate(-16, 0);
			selectedIcon->draw(false);
			cinder::gl::popMatrices();
		}*/
	}
	cinder::gl::popMatrices();
}

void Inventory::drawInventoryInSelection()
{
	cinder::gl::pushMatrices();

	for (int i = 0; i < items.size(); i++){
		items.at(i)->drawInInventory();
		cinder::gl::translate(0, 20);
		if (i == selected){
			cinder::gl::pushMatrices();
			cinder::gl::translate(-10, -20);
			selectedIcon->draw(false);
			cinder::gl::popMatrices();
		}
	}
	cinder::gl::popMatrices();

}


void Inventory::empty()
{
	items.empty();
	items.clear();
}

void Inventory::drawShop()
{
	cinder::gl::pushMatrices();
	cinder::gl::translate(100, 0);
	for (int i = 0; i < items.size(); i++){
		cinder::gl::translate(0, 20);
		items.at(i)->drawInShop();
		if (i == selected){
			cinder::gl::pushMatrices();
			cinder::gl::translate(-16, 0);
			selectedIcon->draw(false);
			cinder::gl::popMatrices();
		}
	}
	cinder::gl::popMatrices();
}

Item* Inventory::checkSelectedItem()
{
	return items.at(getSelected());
}
