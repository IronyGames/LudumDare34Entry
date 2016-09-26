
#include "Offset2D.h"

Offset2D::Offset2D():
Offset2D(Coords2Ddouble(0.0, 0.0), 0.0, Coords2Ddouble(1.0, 1.0))
{

}

Offset2D::Offset2D(const Coords2Ddouble &_translation, double _rotation, const Coords2Ddouble &_scale) :
translation(_translation),
rotation(_rotation),
scale(_scale)
{

}

Coords2Ddouble Offset2D::getTranslation() const
{
	return translation;
}
void Offset2D::setTranslation(const Coords2Ddouble &_translation) {
	translation = _translation;
}

double Offset2D::getRotation() const
{
	return rotation;
}
void Offset2D::setRotation(const double &_rotation) {
	rotation = _rotation;
}

void Offset2D::translate(const Coords2Ddouble &_translation)
{
	translation += _translation;
}

void Offset2D::rotate(const double &_rotation)
{
	rotation += _rotation;
}

void Offset2D::grow(const Coords2Ddouble &_scale)
{
	scale += _scale;
}

Coords2Ddouble Offset2D::getScale() const
{
	return scale;
}

void Offset2D::setScale(const Coords2Ddouble &_scale)
{
	scale = _scale;
}
