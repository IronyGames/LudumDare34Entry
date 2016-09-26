#pragma once
class Model;
class LD34_IronyGamesApp;

class Controller{
public:
	Controller(LD34_IronyGamesApp *_app);
	~Controller();
	void update();
	void draw();
	void onKeyDown(int keyCode);
	void onKeyUp(int keyCode);
private:
	Model *model;
};