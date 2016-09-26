#pragma once
#include "Typedef.h"
#include "GameState.h"
#include "cinder/Color.h"

class Model;
class Animation2D;
class Offset2D;
class IdleState : public GameState{
public:
	IdleState(Model *m);
	virtual void update();
	virtual void draw();
protected:
	Animation2D *hud, *shop;
	Animation2D *bgDirt;

	ciVoicePointer beat, heroAttack, heroDefense, heroHurt, coin;
	int blinkCounter;
	bool toPause;
	int beatFrequency;
	bool toBattle;

	virtual void blink();
	virtual void drawHeroStats();
	virtual void prepareIncomingTransition();
	Offset2D *statsOffset;
private:
	void evaluateBeat();
	int shopBeats;
};