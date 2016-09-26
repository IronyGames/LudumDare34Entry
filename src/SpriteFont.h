#pragma once
class Image;
class Offset2D;
#include "Typedef.h"
#include "Animation2D.h"
class SpriteFont : public Animation2D{
public:
	SpriteFont(Image* _image, Offset2D* _offset, int _tile_width, int _tile_height, int _num_tiles, bool _loops, std::map<char, int> _characterMap);
	void draw(String text, Offset2D *offset, bool fromCenter = false);
private:
	std::map<char, int> characterMap;
	int getCharIndex(char c);
};