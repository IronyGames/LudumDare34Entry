#include "Snail.h"
#include "Offset2D.h"
#include "Model.h"
#include "ImageStorage.h"

Snail::Snail(Model *m)
:Monster("Snail", 5, 5, 2, 0, 5, "NDNA", 1)
{
	Image *i = m->images->get("monster_snail.png");
	Spritesheet s = Spritesheet();
	s.addAnimation("idle", Animation2D(i));
	s.addAnimation("aggressive", Animation2D(i));
	s.addAnimation("attack", Animation2D(i));
	s.addAnimation("defense", Animation2D(i));

	setSpritesheet(s);
}