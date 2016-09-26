#pragma once;
#include <map>
#include "Typedef.h"
class Image;

class ImageStorage{
public:
	static Image* get(const String &path);
private:
	static std::map<String, Image*> store;
};