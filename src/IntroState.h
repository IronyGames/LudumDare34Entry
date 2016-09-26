#pragma once
#include "Typedef.h"
#include "GameState.h"

class Model;
class Animation2D;
class Offset2D;
class IntroState : public GameState{
public:
	IntroState(Model *m);
	void update();
	void draw();
	void prepareIncomingTransition();
private:
	enum KeyboardIcons{
		EMPTY = 0,
		LEFT,
		RIGHT,
		BOTH
	};
	Offset2D *fontOffset;
	Animation2D* bg;
	std::map<KeyboardIcons, Animation2D*> keyboards;
	String introText;
	
	bool toIdle;
	KeyboardIcons currentKeyboard;
};