#pragma once
#include "Typedef.h"
#include "GameState.h"

class Model;
class WinState : public GameState{
public:
	WinState(Model *m);
};