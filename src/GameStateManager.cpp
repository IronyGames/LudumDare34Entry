#include "GameStateManager.h"
#include "GameState.h"
#include "BattleState.h"
#include "DeathState.h"
#include "IntroState.h"
#include "PauseState.h"
#include "ShopState.h"
#include "WinState.h"
#include "IdleState.h"
#include "Model.h"

GameStateManager::GameStateManager( Model *m )
{
	stateMap["intro"] = new IntroState(m);
	stateMap["pause"] = new PauseState(m);
	stateMap["win"] = new WinState(m);
	stateMap["death"] = new DeathState(m);
	stateMap["shop"] = new ShopState(m);
	stateMap["battle"] = new BattleState(m);
	stateMap["idle"] = new IdleState(m);
	lastState = "";
	currentState = "intro";
}

GameStateManager::~GameStateManager()
{
	auto it = stateMap.begin();
	while (it != stateMap.end()){
		delete (*it).second;
		it++;
	}
}

bool GameStateManager::toIntro()
{
	bool changed = changeState("intro");
	return changed;
}

bool GameStateManager::pause()
{
	return changeState("pause");
}

bool GameStateManager::unPause()
{
	if (lastState == ""){
		return false;
	}
	currentState = lastState;
	return true;
}

bool GameStateManager::win()
{
	return changeState("win");
}

bool GameStateManager::death()
{
	return changeState("death");
}

bool GameStateManager::shop()
{
	bool changed = changeState("shop");
	return changed;
}

bool GameStateManager::battle()
{
	bool changed = changeState("battle");
	return changed;
}

GameState* GameStateManager::getCurrentState()
{
	return stateMap[currentState];
}

GameState* GameStateManager::getLastState()
{
	return stateMap[lastState];
}

bool GameStateManager::changeState(String stateKey)
{
	if (stateMap.find(stateKey) == stateMap.end()) {
		return false;
	}
	lastState = currentState;
	currentState = stateKey;
	(getCurrentState())->prepareIncomingTransition();
	return true;
}

bool GameStateManager::toIdle()
{
	bool changed = changeState("idle");
	if (changed){
		(getCurrentState())->prepareIncomingTransition();
	}
	return changed;
}
