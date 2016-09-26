#pragma once
#include <vector>
#include <map>
class KeyboardData{
public:
	KeyboardData();
	~KeyboardData();
	bool isLeftPressed();
	bool isRightPressed();
	void keyDown(int keyCode);
	void keyUp(int keyCode);
	bool get(int key);
private:
	std::vector<int> lefts;
	std::vector<int> rights;
	std::map<int, bool> keyMap;
};