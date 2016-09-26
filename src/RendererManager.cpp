#include "RendererManager.h"
#include "Renderer.h"

RendererManager::RendererManager(Model *_m)
:renderers(std::vector<Renderer*>())
, m(_m)
{
	renderers.push_back(new Renderer(m));
}
RendererManager::~RendererManager()
{
	renderers.clear();
}

void RendererManager::getAvilableRenderer()
{

}

