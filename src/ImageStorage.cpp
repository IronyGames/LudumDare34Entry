#include "ImageStorage.h"
#include "Image.h"

std::map<String, Image*> ImageStorage::store = std::map<String, Image*>();

Image* ImageStorage::get(const String &path)
{
	auto it = store.find(path);

	if (it == store.end()){//doesn't exist, so load it.
		store[path] = new Image(path);
	}

	return store.at(path);
}
