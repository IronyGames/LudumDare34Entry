#pragma once
class Model;
class Animation2D;

class Renderer{
public:
	Renderer(Model *_m);
	void renderAnimation2D(Animation2D *animation);
private:
	Model *m;
};