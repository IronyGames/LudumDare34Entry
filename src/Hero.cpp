#include "Hero.h"
#include "Monster.h"
#include "Animation2D.h"
#include "MobStats.h"
#include "Inventory.h"
#include "SpriteSheet.h"
#include "Model.h"
#include "ImageStorage.h"
#include "Offset2D.h"

Hero::Hero(int _maxHP, int _currentHP, int _atk, int _def, int _gold)
:Monster("Hero", _maxHP, _currentHP, _atk, _def, _gold, "")
,inventory(new Inventory())
{
}

Hero::Hero(Model *m)
:Hero(10, 10, 2, 1, 0)
{

	Image *i = m->images->get("hero2.png");
	Spritesheet s = Spritesheet();
	s.addAnimation("idle", Animation2D(i, new Offset2D(), 32, 32, 6, true, 0));
	s.addAnimation("aggressive", Animation2D(i, new Offset2D(), 32, 32, 6, false, 6));
	s.addAnimation("attack", Animation2D(i, new Offset2D(), 32, 32, 4, false, 11));
	s.addAnimation("defense", Animation2D(i, new Offset2D(), 32, 32, 3, false, 17));

	setSpritesheet(s);
	
}

void Hero::move()
{

}

void Hero::equip()
{

}

void Hero::defend()
{

}

unsigned int Hero::attack()
{
	return stats->atk;
}

void Hero::use()
{

}

void Hero::draw()
{
	sprites.draw(true);
	inventory->drawInventory();
}

void Hero::update()
{
	sprites.update();
}

unsigned int Hero::receiveDamage(int _dmg, bool wasDefending /*= false*/)
{
	int def = stats->def;
	if (wasDefending){
		def *= 3;
		//TODO, factor the shield in
	}
	int fdmg = (_dmg - def);
	if (fdmg < 0){
		fdmg = 0;
	}
	stats->currentHP -= fdmg;
	if (stats->currentHP < 0){
		stats->currentHP = 0;
	}
	return fdmg;
}

void Hero::addMoney(int pieces)
{
	stats->gold += pieces;
}

void Hero::reset()
{
	stats->gold = 0;
	fullHeal();
	inventory->empty();
	//TODO give standard items & equip again
}

void Hero::obtain(Item *i)
{
	inventory->addItem(i);
}
