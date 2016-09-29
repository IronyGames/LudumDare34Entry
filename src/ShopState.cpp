#include "ShopState.h"
#include "Model.h"
#include "GameStateManager.h"
#include "Keyboard.h"
#include "cinder\gl\wrapper.h"
#include "Inventory.h"
#include "PotionOfHealth.h"
#include "Offset2D.h"
#include "Animation2D.h"
#include "ImageStorage.h"
#include "GameState.h"
#include "Model.h"
#include "Metronome.h"
#include "AudioStorage.h"
#include "Monster.h"
#include "MobStats.h"
#include "Hero.h"

ShopState::ShopState(Model *m)
:GameState(m)
{
	beat = m->sounds->get("beat.ogg");
	stock = new Inventory(new Animation2D(m->images->get("icons.png"), new Offset2D(), 8, 16, 1, false, 14));
	prepareItems(m);
}

void ShopState::update()
{
	model->metronome->update();
	if (model->metronome->hasBeatJustChanged()){
		beat->start();
		if (model->input->isRightPressed()){
			model->states->toIdle();
		}
		if (model->input->isOnlyLeftPressed()){
			bool wasBought = model->player->buy(stock->checkSelectedItem());
			if (wasBought){
				stock->useItem();
			}
			
		}else{
			stock->selectNext();
		}
		
		
	}
	
}

void ShopState::draw()
{
	cinder::gl::clear(cinder::Color(0.9, 0.9, 0.8));
	cinder::gl::pushMatrices();
	cinder::gl::scale(2.0f, 2.0f);
	stock->drawShop();
	cinder::gl::popMatrices();
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
