#pragma once
#include "Typedef.h"

class Offset2D{
public:
	Offset2D();
	Offset2D(const Coords2Ddouble &_translation, double _rotation, const Coords2Ddouble &_scale);

	void setTranslation(const Coords2Ddouble &_translation);

	void setRotation(const double &_rotation);

	void setScale(const Coords2Ddouble &_scale);

	void translate(const Coords2Ddouble &_translation);

	void rotate(const double &_rotation);

	void grow(const Coords2Ddouble &_scale);


	Coords2Ddouble getTranslation() const;
	double getRotation() const;
	Coords2Ddouble getScale() const;
private:
	Coords2Ddouble translation;
	double rotation;
	Coords2Ddouble scale;
};