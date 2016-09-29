#include "Keyboard.h"
#include "KeyboardData.h"

Keyboard::Keyboard()
: kMap(new KeyboardData())
, lastState(KeyState::NONE)
{

}

Keyboard::~Keyboard()
{

}

bool Keyboard::isLeftPressed()
{
	return kMap->isLeftPressed();
}

bool Keyboard::isRightPressed()
{
	return kMap->isRightPressed();
}

bool Keyboard::areBothPressed()
{
	return (isLeftPressed() && isRightPressed());
}

bool Keyboard::areNonePressed()
{
	return !areBothPressed();
}

void Keyboard::down(int keyCode)
{
	kMap->keyDown(keyCode);
	if (areBothPressed()){
		lastState = BOTH;
	}
	else if (isOnlyLeftPressed()){
		lastState = LEFT;
	}
	else if (isOnlyRightPressed()){
		lastState = RIGHT;
	}
}

void Keyboard::up(int keyCode)
{
	kMap->keyUp(keyCode);
}

bool Keyboard::clickedEscape()
{
	return kMap->get(27);
}

bool Keyboard::wasLeftReleased()
{
	return lastState == LEFT && !isLeftPressed();
}

bool Keyboard::wasRightReleased()
{
	return lastState == RIGHT && !isRightPressed();
}

bool Keyboard::wereBothReleased()
{
	return lastState == BOTH && !areBothPressed();
}

bool Keyboard::isOnlyLeftPressed()
{
	return isLeftPressed() && !isRightPressed();
}

bool Keyboard::isOnlyRightPressed()
{
	return !isLeftPressed() && isRightPressed();
}