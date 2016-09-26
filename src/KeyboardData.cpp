#include "KeyboardData.h"

KeyboardData::KeyboardData()
{
	lefts = std::vector<int>({49,50,51,52,53,
								81,87,69,82,84,113,119,101,114,116,
								65,97,83,115,68,100,70,102,71,103,
								90,122,88,120,67,99,86,118,66,98
								});
	rights = std::vector<int>({ 54,55,56,57,48,
								89,121,85,117,73,105,79,111,80,112,
								72,104,74,106,75,107,76,108,
								77,109,78,110
								});
}

KeyboardData::~KeyboardData()
{

}

void KeyboardData::keyDown(int keyCode)
{
	keyMap[keyCode] = true;
}

void KeyboardData::keyUp(int keyCode)
{
	keyMap[keyCode] = false;
}

bool KeyboardData::isLeftPressed()
{
	auto it = lefts.begin();
	while (it != lefts.end()){
		if (keyMap[*it] == true){
			return true;
		}
		it++;
	}
	return false;
}

bool KeyboardData::isRightPressed()
{
	auto it = rights.begin();
	while (it != rights.end()){
		if (keyMap[*it] == true){
			return true;
		}
		it++;
	}
	return false;
}

bool KeyboardData::get(int key)
{
	return keyMap[key];
}
