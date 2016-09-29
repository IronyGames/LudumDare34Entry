#pragma once
class Model;
class Animation2D;
class Hero; 

class Renderer{
public:
	Renderer(Model *_m);
	void renderAnimation2D(Animation2D *animation);
	void renderHero(Hero *hero);

private:
	Model *m;
};