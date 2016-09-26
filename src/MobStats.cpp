#include "MobStats.h"
MobStats::MobStats()
:MobStats(1,1,1,1,0)
{

}

MobStats::MobStats(int _maxHP, int _currentHP, int _atk, int _def, int _gold)
: maxHP(_maxHP)
, currentHP(_currentHP)
, atk(_atk)
, def(_def)
, gold(_gold)
{

}

bool MobStats::isDead()
{
	return currentHP == 0;
}

