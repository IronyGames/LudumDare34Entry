#include "Spritesheet.h"
#include "Logger.h"
#include "Offset2D.h"
#include "cinder\gl\wrapper.h"

Spritesheet::Spritesheet()
:Spritesheet(std::map<String, Animation2D>())
{
	
}

Spritesheet::Spritesheet(std::map<String, Animation2D> _animations)
: animations(_animations)
, currentAnimation("idle")
, offset(new Offset2D())
{
	
}

Spritesheet::~Spritesheet()
{
	animations.clear();
}

bool Spritesheet::setCurrentAnimation(String _animationName)
{
	if (!doesAnimationExist(_animationName)){
		Logger::logError("At Spritesheet::setCurrentAnimation, animation not found: " + _animationName);
		return false;
	}

	currentAnimation = _animationName;
}

bool Spritesheet::setCurrentAnimationAndResetCurrentLoop(String _animationName)
{
	bool isSet = setCurrentAnimation(_animationName);
	if (!isSet){
		return false;
	}
	resetCurrentAnimationLoop();
	return true;
}

Animation2D* Spritesheet::getCurrentAnimation()
{
	if (!doesAnimationExist(currentAnimation)){
		Logger::logError("At Spritesheet::getCurrentAnimation, animation not found: " + currentAnimation);
		return new Animation2D();
	}

	return &(animations.at(currentAnimation));
}

void Spritesheet::update()
{
	animations.at(currentAnimation).update();
}

void Spritesheet::resetAllAnimationLoops()
{
	for (auto it = animations.begin(); it != animations.end(); it++){
		it->second.reset();
	}
}

void Spritesheet::addAnimation(String _animationName, Animation2D _animation)
{
	if (doesAnimationExist(_animationName)){
		Logger::logWarning("At Spritesheet::addAnimation, animation found: " + currentAnimation + ", will be overwritten");
	}

	animations[_animationName] = _animation;

	if (animations.size() == 1){ //only animation, let's set this one as current
		setCurrentAnimation(_animationName);
	}
}

bool Spritesheet::removeAnimation(String _animationName)
{
	if (doesAnimationExist(_animationName)){
		Logger::logError("At Spritesheet::removeAnimation, animation not found: " + currentAnimation);
		return false;
	}

	animations.erase(_animationName);
}

bool Spritesheet::doesAnimationExist(String _animationName)
{
	return animations.find(_animationName) != animations.end();
}


void Spritesheet::setTranslation(const Coords2Ddouble &_translation) {
	offset->setTranslation(_translation);
}

void Spritesheet::setRotation(const double &_rotation) {
	offset->setRotation(_rotation);
}

void Spritesheet::setScale(const Coords2Ddouble &_scale)
{
	offset->setScale(_scale);
}

void Spritesheet::translate(const Coords2Ddouble &_translation)
{
	offset->setTranslation(_translation);
}

void Spritesheet::rotate(const double &_rotation)
{
	offset->rotate(_rotation);
}

void Spritesheet::scale(const Coords2Ddouble &_scale)
{
	offset->grow(_scale);
}

Coords2Ddouble Spritesheet::getTranslation() const
{
	return offset->getTranslation();
}

float Spritesheet::getRotation() const
{
	return offset->getRotation();
}

Coords2Ddouble Spritesheet::getScale() const
{
	return offset->getScale();
}

void Spritesheet::resetCurrentAnimationLoop()
{
	getCurrentAnimation()->reset();
}

void Spritesheet::draw(bool _fromCenter)
{
	cinder::gl::pushMatrices();
	cinder::gl::translate(offset->getTranslation());
	cinder::gl::rotate(offset->getRotation());
	cinder::gl::scale(offset->getScale());
	getCurrentAnimation()->draw(_fromCenter);
	cinder::gl::popMatrices();
}

bool Spritesheet::hasCurrentAnimationFinished()
{
	return getCurrentAnimation()->hasAnimationFinished();
}

String Spritesheet::getCurrentAnimationName()
{
	return currentAnimation;
}
