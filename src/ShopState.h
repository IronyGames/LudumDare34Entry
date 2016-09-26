#pragma once
#include "Typedef.h"
#include "GameState.h"

class Model;
class Inventory;
class Item;

class ShopState : public GameState{
public:
	ShopState(Model *m);
	void update();
	void draw();
	void prepareIncomingTransition();
private:
	Inventory *stock;
	void prepareStock();
	std::vector<Item*> items;
	void prepareItems(Model *m);
};