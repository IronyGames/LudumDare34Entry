#include "PotionOfHealth.h"
#include "Monster.h"
#include "Offset2D.h"
#include "Model.h"
#include "ImageStorage.h"
#include "SpriteFontManager.h"

PotionOfHealth::PotionOfHealth(Model *m)
:Item("+3", 
		new Animation2D(m->images->get("icons.png"), new Offset2D(), 16, 16, 1, false, 8), 
	3, m->fonts)
, healPoints(3)
{
	
}

void PotionOfHealth::use(Monster *m)
{
	m->heal(healPoints);
}

void PotionOfHealth::drawInShop()
{
	icon->draw(false);

	String out = "";
	out += std::to_string(getPrice());
	out += "GP +";
	out += std::to_string(healPoints);
	out += "HP ";
	font->draw(new Offset2D(Coords2Ddouble(24, 0),0.0, Coords2Ddouble(1,1)), out, "font1", true);
}

void PotionOfHealth::drawInInventory()
{
	icon->draw(false);

	String out = "";
	out += "+";
	out += std::to_string(healPoints);
	out += "HP ";
	font->draw(new Offset2D(Coords2Ddouble(24, 0), 0.0, Coords2Ddouble(1, 1)), out, "font1", true);
}
