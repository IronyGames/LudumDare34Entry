#include "MonsterList.h"
#include "Monster.h"
#include "cinder/Xml.h"
#include "cinder/app/App.h"
#include "Animation2D.h"
#include "Model.h"
#include "ImageStorage.h"
#include "Logger.h"
#include "Snail.h"

Monster* MonsterList::pickMonster(unsigned int difficulty)
{
	std::vector<int> candidateId;
	for (int i = 0; i < monsters.size(); i++){
		if (monsters.at(i)->getDifficulty() <= difficulty){
			candidateId.push_back(i);
		}
	}

	if (candidateId.size()){
		Logger::logInputError("At MonsterList::pickMonster, no monsters loaded");
	}

	int candidate = candidateId.at(rand() % (candidateId.size()));

	Monster *out = monsters.at(candidate)->spawn();

	return out;
	
}

MonsterList::MonsterList(Model *m)
{
	monsters.push_back(new Snail(m));
}

