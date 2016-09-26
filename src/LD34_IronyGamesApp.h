#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;
class Controller;

class LD34_IronyGamesApp : public App {
public:
	void setup() override;
	void mouseDown(MouseEvent event) override;
	void keyDown(KeyEvent event) override;
	void keyUp(KeyEvent event) override;
	void update() override;
	void draw() override;
private:
	Controller *controller;
};