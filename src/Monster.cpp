#include "Monster.h"
#include "MobStats.h"
#include "Animation2D.h"
#include "Global.h"
#include "Spritesheet.h"

Monster::Monster(String _name, int _maxHP, int _currentHP, int _atk, int _def, int _gold, Spritesheet _sprites, String _actions, int _difficulty /*= 1*/)
: stats(new MobStats(_maxHP, _currentHP, _atk, _def, _gold))
, sprites(_sprites)
, name(_name)
, actions(_actions)
, currentAction(-1)
, difficulty(_difficulty)
{
	sprites.setScale(Coords2Ddouble(5.0, 5.0));
	sprites.setTranslation(Global::windowSize*3.0 / 5.0);
}

Monster::Monster(Model *m)
{

}

Monster::Monster()
{

}

Monster::Monster(String _name, int _maxHP, int _currentHP, int _atk, int _def, int _gold, String _actions, int _difficulty /*= 1*/)
:Monster(_name, _maxHP, _currentHP, _atk, _def, _gold, Spritesheet(), _actions, _difficulty)
{

}

void Monster::update()
{
	currentAction++;
	if (currentAction >= actions.size()){
		currentAction = 0;
	}
}

void Monster::draw()
{
	sprites.draw(true);
}

unsigned int Monster::attack()
{
	char ac = actions.at(currentAction);
	if (ac == 'A'){
		return stats->atk;
	}
	return 0;
}

Monster* Monster::spawn()
{
	int ngold = stats->gold * ((double)(rand() % 100)) / 50.0;
	Monster *out = new Monster(name, stats->maxHP, stats->maxHP, stats->atk, stats->def, ngold, sprites, actions);
	return out;
}

MobStats* Monster::getStats()
{
	return stats;
}

unsigned int Monster::receiveDamage(int _dmg, bool wasDefending /*= false*/)
{
	int def = stats->def;
	if (wasDefending){
		def *= 2;
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

bool Monster::isDead()
{
	return stats->currentHP == 0;
}

bool Monster::isDefending()
{
	char ac = actions.at(currentAction);
	if (ac == 'D'){
		return true;
	}
	return false;
}

void Monster::heal(int heal)
{
	stats->currentHP += heal;
	if (stats->currentHP > stats->maxHP){
		stats->currentHP = stats->maxHP;
	}
}

void Monster::fullHeal()
{
	stats->currentHP = stats->maxHP;
}

void Monster::setSpritesheet(Spritesheet _sprites)
{
	sprites = _sprites;
}

int Monster::getDifficulty()
{
	return difficulty;
}

Spritesheet* Monster::getSprites()
{
	return &sprites;
}
