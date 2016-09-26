#include "PotionOfHealth.h"
#include "Monster.h"
#include "Offset2D.h"
#include "Model.h"
#include "ImageStorage.h"

PotionOfHealth::PotionOfHealth(Model *m)
:Item("+3", 
		new Animation2D(m->images->get("icons.png"), new Offset2D(), 16, 16, 1, false, 8), 
	3)
, healPoints(3)
{
	
}

void PotionOfHealth::use(Monster *m)
{
	m->heal(healPoints);
}

