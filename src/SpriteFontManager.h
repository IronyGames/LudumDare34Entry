#pragma once
#include "Typedef.h"
class Offset2D;
class SpriteFont;
class Model;

class SpriteFontManager{
	std::map<String, SpriteFont*> fonts;
public:
	SpriteFontManager(Model *m);
	void draw(Offset2D *offset, String text, String fontName = "", bool fromCenter = false);
	char parseXMLCharacter(String c);
};