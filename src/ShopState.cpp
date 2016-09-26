#include "ShopState.h"
#include "Model.h"
#include "GameStateManager.h"
#include "Keyboard.h"
#include "cinder\gl\wrapper.h"
#include "Inventory.h"
#include "PotionOfHealth.h"

ShopState::ShopState(Model *m)
:GameState(m)
, stock(new Inventory())
{
	prepareItems(m);
}

void ShopState::update()
{
	if (model->input->wasRightReleased()){
		model->states->toIdle();
	}
}

void ShopState::draw()
{
	cinder::gl::clear(cinder::Color(0.9, 0.9, 0.8));
	stock->drawShop();
}

void ShopState::prepareIncomingTransition()
{
	prepareStock();
}

void ShopState::prepareStock()
{
	stock->empty();
	for (int i = 0; i < items.size(); i++){
		int quantity = rand() % 4;
		for (int j = 0; j < quantity; j++){
			stock->addItem(items.at(i));
		}
	}
}

void ShopState::prepareItems(Model *m)
{
	items.push_back(new PotionOfHealth(m));
	items.push_back(new PotionOfHealth(m));
	items.push_back(new PotionOfHealth(m));
	items.push_back(new PotionOfHealth(m));
}
