#pragma once
#include "Typedef.h"

class GameState;
class Model;
class GameStateManager{
public:
	GameStateManager(Model *m);
	~GameStateManager();
	bool toIntro();
	bool pause();
	bool unPause();
	bool win();
	bool death();
	bool shop();
	bool battle();
	bool toIdle();

	GameState* getCurrentState();
	GameState* getLastState();
private:
	std::map<String, GameState*> stateMap;
	String currentState;
	String lastState;

	
	bool changeState(String stateKey);
};