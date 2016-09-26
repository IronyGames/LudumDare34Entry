#pragma once
#include "Typedef.h"
#include "Animation2D.h"

class Spritesheet{
public:
	Spritesheet();
	Spritesheet(std::map<String, Animation2D> _animations);
	~Spritesheet();

	void addAnimation(String _animationName, Animation2D _animation);
	bool removeAnimation(String _animationName);
	bool setCurrentAnimation(String _animationName);
	bool setCurrentAnimationAndResetCurrentLoop(String _animationName);
	bool hasCurrentAnimationFinished();

	void update();
	void resetAllAnimationLoops();
	void resetCurrentAnimationLoop();

	Coords2Ddouble getTranslation() const;
	float getRotation() const;
	Coords2Ddouble getScale() const;
	void setTranslation(const Coords2Ddouble &_translation);
	void setRotation(const double &_rotation);
	void setScale(const Coords2Ddouble &_scale);
	void translate(const Coords2Ddouble &_translation);
	void rotate(const double &_rotation);
	void scale(const Coords2Ddouble &_scale);

	void draw(bool _fromCenter);

	String getCurrentAnimationName();
private:
	Animation2D* getCurrentAnimation();
	bool doesAnimationExist(String _animationName);
	
	String currentAnimation;
	std::map<String, Animation2D> animations;

	Offset2D *offset;
};

