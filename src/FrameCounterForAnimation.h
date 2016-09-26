#pragma once
/*
*	A component for 2D or 3D animations to manage their current frames.
*	This class manages at what frame the animation currently is. It also manages
*	loops in the animation, speed-up and slowing down. With this, the animations
*	are be independent of their original frames per second, or the applications'.
*/
class FrameCounterForAnimation{
private:
	int animationFPS;
	int applicationFPS;
	int currentFrame;
	int numFrames;
	bool animationLoops;
	double speed;

	/*
	*	Buffer more precise to count inter-frame speeds.
	*	For instance, if aniToAppRatio = 1 but speed = 1.5,
	*	interFrame = 1*1.5 = 1.5, which means one frame at this update,
	*	but at the next it's interFrame = (0.5)+(1*1.5) = 2, which means
	*	2 frames to be advanced at this update.
	*	Noted is that using these speeds may not be wise, however, as
	*	the animation won't be uniform, as shown in the example.
	*/
	double interFrame;
	/*
	*	Ratio is animationFPS/applicationFPS.
	*	In other words, how many animation frames must we reproduce in
	*	a frame of the application?
	*	If animationFPS = 60fps and applicationFPS = 30fps, the ratio is 2.
	*	That means that for every frame of application, 2 of animation will
	*	pass. That means we'll miss 1 frame of animation of 2 for every frame
	*	of application, thus equaling animationFPS to applicationFPS (30fps).
	*	Since animation is the one over sampled, it makes sense to lose data.
	*	However if animationFPS = 30fps and applicationFPS = 60fps, the ratio
	*	is 1/2. That means every frame of animation will have to be drawn for
	*	two frames of animation. Since animation is under sampled, every frame
	*	has to stay longer.
	*/
	double aniToAppRatio;

	/*
	*	Checks if the current 
	*/
	void checkIfAnimationEnded();
public:
	FrameCounterForAnimation();
	FrameCounterForAnimation(int _frames, int _animationSpeed, int _applicationSpeed,
		bool _animationLoops, double _speed = 1);
	FrameCounterForAnimation(int _frames, int _animationSpeed, int _applicationSpeed,
		bool _animationLoops, int _startingFrame, double _speed = 1);

	/*
	*	Sends animation to the next frame, evaluated by the input in the constructor.
	*	Could also be called nextFrame, chosen update to stick with a 
	*	regularized vocabulary.
	*/
	void update();
	void addSpeed(double _speed);
	void setSpeed(double _speed);
	void reset();


	int getCurrentFrame();
};