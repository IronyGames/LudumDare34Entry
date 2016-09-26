#pragma once
class GameStateManager;
class Keyboard;
class ImageStorage;
class AudioStorage;
class Metronome;
class LD34_IronyGamesApp;
class SpriteFontManager;
class Hero;

class Model{
public:
	Model(LD34_IronyGamesApp *_app);
	GameStateManager* states;
	Keyboard *input;
	ImageStorage *images;
	AudioStorage *sounds;
	Metronome *metronome;
	LD34_IronyGamesApp *app;
	SpriteFontManager *fonts;
	Hero *player;
	unsigned int difficulty, fpsCounter;
};

