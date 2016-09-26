#pragma once
class Image;
class Offset2D;
#include "Typedef.h"
class Animation2D{
public:
	Animation2D();
	Animation2D(Image* _image);
	Animation2D(String _path);
	Animation2D(Image* _image, Offset2D* _offset, int _tile_width, int _tile_height, int _num_tiles, bool _loops, int _first_tile = 0);

	const Image * getImage() const;
	Image * getImage();
	void setImage(Image *val);

	Coords2Ddouble getTranslation() const;
	float getRotation() const;
	Coords2Ddouble getScale() const;
	void setTranslation(const Coords2Ddouble &_translation);
	void setRotation(const double &_rotation);
	void setScale(const Coords2Ddouble &_scale);
	void translate(const Coords2Ddouble &_translation);
	void rotate(const double &_rotation);
	void scale(const Coords2Ddouble &_scale);

	bool update(); //returns whether the animation's finished / will loop next frame
	void draw(bool fromCenter = false);
	void drawLastFrame();

	bool hasAnimationFinished();

	bool doesLoop();
	void changeLooping(bool _loops);

	void reset();
	int getHeight();
	int getWidth();
protected:
	int tile_offset;
	int tile_width;
	int tile_height;
	int num_tiles;
	int current_frame;
	int image_columns;

	bool loops;

	Offset2D *offset;

	Image *image;
};


