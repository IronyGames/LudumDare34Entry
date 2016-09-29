#pragma once
#include <vector>
class Item;
class Offset2D;
class Animation2D;

class Inventory{
private:
	std::vector<Item*> items;
	int getSelected();
	int selected;
	Animation2D *selectedIcon;
	unsigned int size;
public:
	Inventory(Animation2D *selectIcon, unsigned int size = 1000);
	bool addItem(Item* newItem);
	Item* useItem();
	void equip();
	void selectNext();

	Item* checkSelectedItem();
	
	void drawInventory();
	void drawShop();
	void empty();
	void drawInventoryInSelection();
	Offset2D *statsOffset;
};