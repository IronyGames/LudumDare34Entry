#include "LD34_IronyGamesApp.h"
#include "Controller.h"
#include "Global.h"

void LD34_IronyGamesApp::setup()
{
	controller = new Controller(this);
	this->setWindowSize(Global::windowSize.x, Global::windowSize.y);
	this->setFrameRate(Global::fps);
	this->setWindowPos(100, 100);
}

void LD34_IronyGamesApp::mouseDown(MouseEvent event)
{
}

void LD34_IronyGamesApp::update()
{
	controller->update();
}

void LD34_IronyGamesApp::draw()
{
	controller->draw();
}

void LD34_IronyGamesApp::keyDown(KeyEvent event)
{
	controller->onKeyDown(event.getNativeKeyCode());
}

void LD34_IronyGamesApp::keyUp(KeyEvent event)
{
	controller->onKeyUp(event.getNativeKeyCode());
}



CINDER_APP(LD34_IronyGamesApp, RendererGl)
