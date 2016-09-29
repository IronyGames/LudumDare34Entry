#pragma once
#include <vector>
class KeyboardData;
class Keyboard{
public:
	Keyboard();
	~Keyboard();
	bool isLeftPressed();
	bool isRightPressed();
	bool isOnlyLeftPressed();
	bool isOnlyRightPressed();
	bool areBothPressed();

	bool wasLeftReleased();
	bool wasRightReleased();
	bool wereBothReleased();

	bool areNonePressed();

	bool clickedEscape();

	void down(int keyCode);
	void up(int keyCode);
private:
	KeyboardData *kMap;

	enum KeyState{
		LEFT = 0,
		RIGHT,
		BOTH,
		NONE
	};

	KeyState lastState;
};