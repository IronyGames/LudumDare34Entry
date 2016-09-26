#include "Logger.h"
#include "Image.h"
#include "Offset2D.h"
#include "cinder/app/App.h"
Image::Image()
: image(nullptr)
, imageSet(false)
{
}

Image::Image(const String &path)
: imageSet(true)
{
	
	image = image->create(cinder::loadImage(cinder::app::loadAsset(path)));
	image->setMagFilter(GL_NEAREST);
	image->setMinFilter(GL_NEAREST);
}

glImageRef Image::getGlImageRef() const
{
	if (!imageSet){
		Logger::logError("Image is being requested, but is not set!");
	}
	return this->image;
}


int Image::getWidth()
{
	int out = 1;

	if (imageSet){
		out = getGlImageRef()->getWidth();
	}
	else{
		Logger::logError("Image's width is being requested, but is not set!");
	}

	return out;

}

int Image::getHeight()
{
	int out = 1;

	if (imageSet){
		out = getGlImageRef()->getHeight();
	}
	else{
		Logger::logError("Image's height is being requested, but is not set!");
	}

	return out;

}

#include "cinder/gl/gl.h"
void Image::draw()
{
	cinder::gl::draw(getGlImageRef());
}
