#include "Typedef.h"
#include "Animation2D.h"
#include "cinder/gl/gl.h"
#include "Offset2D.h"
#include "Image.h"

Animation2D::Animation2D()
:Animation2D(new Image(), new Offset2D(), 1, 1, 60, false)
{
}


Animation2D::Animation2D(Image* _image)
: Animation2D(_image, new Offset2D(), _image->getWidth(), _image->getHeight(), 1, false)
{

}


Animation2D::Animation2D(String _path)
: Animation2D(new Image(_path), new Offset2D(), 1, 1, 60, false)
{
	tile_width = image->getWidth();
	tile_height = image->getHeight();
	num_tiles = 1;
}


Animation2D::Animation2D(Image* _image, Offset2D* _offset, int _tile_width, int _tile_height, int _num_tiles, bool _loops, int _first_tile /*= 0*/)
: image(_image)
, tile_width(_tile_width)
, tile_height(_tile_height)
, num_tiles(_num_tiles)
, current_frame(0)
, offset(_offset)
, loops(_loops)
, tile_offset(_first_tile)
{
	image_columns = (image->getWidth() / _tile_width);
}

const Image * Animation2D::getImage() const { 
	return image; 
}

Image * Animation2D::getImage() { 
	return image; 
}

void Animation2D::setImage(Image * val) { 
	image = val; 
}

bool Animation2D::update()
{
	current_frame+=1;
	if (current_frame >= num_tiles){
		if (doesLoop()){
			current_frame = 0;
		}
		else{
			current_frame = num_tiles - 1;
		}
		return true;
	}
	return false;
}

void Animation2D::draw( bool fromCenter /*= false*/ )
{

	int w = ((current_frame + tile_offset) % image_columns) * tile_width;
	int h = ((current_frame + tile_offset) / image_columns) * tile_height;
	int px = (float)tile_width / 2.0f;
	int py = (float)tile_height / 2.0f;
	

	cinder::Area sub(
		w,				h, 
		w+tile_width,	h+tile_height
		);

	cinder::Rectf pos(
		(-px), (-py), 
		( px), ( py) 
	);
	
	Coords2Ddouble center = offset->getTranslation();
	if (!fromCenter){
		Coords2Ddouble centerDifference = (offset->getScale() * Coords2Ddouble(tile_width, tile_height));
		centerDifference /= 2;
		center += centerDifference;
	}
	

	cinder::gl::pushMatrices();
		cinder::gl::translate(center);
		/*cinder::gl::translate(offset->getTranslation());*/
		cinder::gl::rotate(offset->getRotation());
		cinder::gl::scale(offset->getScale());
		//image->draw();
		cinder::gl::draw(image->getGlImageRef(), sub, pos);
	cinder::gl::popMatrices();
	
	/*
	ORIGINAL CODE
	---------------------------------------------
	int row = current_frame / image_columns;
	int column = current_frame % image_columns;

	cinder::Area sub(
		column		*tile_width,
		row			*tile_height,
		(column + 1)*tile_width,
		(row + 1)	*tile_height);

	cinder::Rectf pos(
		(-(float)tile_width / 2.0f),
		(-(float)tile_height / 2.0f),
		((float)tile_width / 2.0f),
		((float)tile_height / 2.0f)
		);
	*/
}

void Animation2D::drawLastFrame()
{
	int aux = current_frame;
	current_frame = num_tiles - 1;
	draw();
	current_frame = aux;
}

void Animation2D::setTranslation(const Coords2Ddouble &_translation) {
	offset->setTranslation(_translation);
}

void Animation2D::setRotation(const double &_rotation) {
	offset->setRotation(_rotation);
}

void Animation2D::setScale(const Coords2Ddouble &_scale)
{
	offset->setScale(_scale);
}

void Animation2D::translate(const Coords2Ddouble &_translation)
{
	offset->setTranslation(_translation);
}

void Animation2D::rotate(const double &_rotation)
{
	offset->rotate(_rotation);
}

void Animation2D::scale(const Coords2Ddouble &_scale)
{
	offset->grow(_scale);
}

bool Animation2D::doesLoop()
{
	return loops;
}

void Animation2D::changeLooping(bool _loops)
{
	_loops = _loops;
}


Coords2Ddouble Animation2D::getTranslation() const
{
	return offset->getTranslation();
}

float Animation2D::getRotation() const
{
	return offset->getRotation();
}

Coords2Ddouble Animation2D::getScale() const
{
	return offset->getScale();
}


void Animation2D::reset()
{
	current_frame = 0;
}

int Animation2D::getHeight()
{
	return image->getHeight() * offset->getScale().y;
}

int Animation2D::getWidth()
{
	return image->getWidth() * offset->getScale().x;
}

bool Animation2D::hasAnimationFinished()
{
	return (!doesLoop()) && (current_frame == num_tiles - 1);
}
