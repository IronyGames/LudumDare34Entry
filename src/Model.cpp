#include "Model.h"
#include "GameStateManager.h"
#include "Keyboard.h"
#include "ImageStorage.h"
#include "Metronome.h"
#include "AudioStorage.h"
#include "Global.h"
#include "LD34_IronyGamesApp.h"
#include "SpriteFontManager.h"
#include "Hero.h"
#include "Animation2D.h"
#include "PotionOfHealth.h"

Model::Model(LD34_IronyGamesApp *_app)
: input(new Keyboard())
, images(new ImageStorage())
, sounds(new AudioStorage())
, metronome(new Metronome(0, Global::fps))
, app(_app)
, difficulty(3)
, fpsCounter(0)
{
	fonts = new SpriteFontManager(this);
	player = new Hero(this);
	player->obtain(new PotionOfHealth(this));
	states = new GameStateManager(this);
}