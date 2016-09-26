#pragma once
#include "Typedef.h"
class Offset2D;
class Image{
private:
	glImageRef image;
	bool imageSet;
	
public:
	Image();
	Image(const String &path);

	glImageRef getGlImageRef() const;
	int getWidth();
	int getHeight();
	void draw();
};