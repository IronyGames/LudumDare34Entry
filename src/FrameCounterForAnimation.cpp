
#include "FrameCounterForAnimation.h"
#include <math.h>

FrameCounterForAnimation::FrameCounterForAnimation()
: FrameCounterForAnimation(0,0,0,0,0,1.0)
{

}

FrameCounterForAnimation::FrameCounterForAnimation(int _frames, int _animationSpeed, int _applicationSpeed, bool _animationLoops, double _speed /*= 1*/)
:FrameCounterForAnimation(_frames, _animationSpeed, _applicationSpeed, _animationLoops, 0, 1.0)
{

}

FrameCounterForAnimation::FrameCounterForAnimation(int _frames, int _animationSpeed, int _applicationSpeed, bool _animationLoops, int _startingFrame, double _speed /*= 1*/)
: numFrames(_frames)
, animationFPS(_animationSpeed)
, applicationFPS(_animationSpeed)
, animationLoops(_animationLoops)
, currentFrame(_startingFrame) //check if it's bigger than the number of frames
, speed(_speed)
, interFrame(0)
{
	checkIfAnimationEnded();
	aniToAppRatio = animationFPS / applicationFPS;
}

void FrameCounterForAnimation::update()
{
	interFrame += aniToAppRatio * speed;
	if (interFrame > 1){
		int advFrames = floor(interFrame);
		currentFrame += advFrames;
		interFrame -= advFrames;
		checkIfAnimationEnded();
	}
}

void FrameCounterForAnimation::addSpeed(double _speed)
{
	speed += _speed;
}

void FrameCounterForAnimation::setSpeed(double _speed)
{
	speed = _speed;
}

int FrameCounterForAnimation::getCurrentFrame()
{
	return currentFrame;
}

void FrameCounterForAnimation::checkIfAnimationEnded()
{
	if (currentFrame > numFrames){
		if (animationLoops){
			currentFrame = 0;
			//consider interFrame = 0. Right now, different frames can be chosen in every loop if
			//aniToAppRatio != 1. With interFrame = 0, the same frames would be picked in every loop. 
			//Requiring another input flag to determine this seems overengineering.
		}
		else{
			currentFrame = numFrames - 1;
		}
	}
}

void FrameCounterForAnimation::reset()
{
	currentFrame = 0;
	interFrame = 0;
}
