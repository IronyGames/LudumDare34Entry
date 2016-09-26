#pragma once
#include <vector>
class Item;
class Offset2D;

class Inventory{
private:
	std::vector<Item*> items;
	int getSelected();
public:
	Inventory();
	void addItem(Item* newItem);
	Item* useItem(int index);
	void equip();
	int selected;
	
	void drawInventory();
	void drawShop();
	void empty();
	Offset2D *statsOffset;
};