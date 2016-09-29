#pragma once
#include "Typedef.h"

class Renderer;
class Model;
class RendererManager{
private:
	std::vector<Renderer*> renderers;
	Model *m;
public:
	RendererManager(Model *_m);
	~RendererManager();
	Renderer* getAvailableRenderer();
};