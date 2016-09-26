#pragma once
class MobStats{
public:
	int maxHP;
	int currentHP;
	int atk;
	int def;
	int gold;
	MobStats();
	MobStats(int _maxHP, int _currentHP, int _atk, int _def, int _gold);
	bool isDead();
};