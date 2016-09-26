#pragma once
class Model;
class GameState{
public:
	GameState(Model *m);
	virtual void update();
	virtual void draw();
	virtual void prepareIncomingTransition();
protected:
	Model *model;
};