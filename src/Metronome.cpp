#include "Metronome.h"

Metronome::Metronome(int _bps, int _fps)
: bps(_bps)
, fps(_fps)
, fib(0)
{
	reset();
}

void Metronome::update()
{
	frameCounter++;
	if (frameCounter > fps-1){
		frameCounter = 0;
	}
}

int Metronome::getBeat()
{
	return (int)(ratio * frameCounter);	
}

void Metronome::changeBeat(unsigned int _newBPS)
{
	bps = _newBPS;
	reset();
}

void Metronome::reset()
{
	frameCounter = 0;
	ratio = (double)bps / (double)fps;
	fib = 0;
	if (bps != 0){
		fib = fps / bps;
	}
}

bool Metronome::hasBeatJustChanged()
{
	int aux = frameCounter % fib;
	bool out = false;
	if (aux == 0){
		out = true;
	}
	return out;
}

int Metronome::getFramesInBeat()
{
	return fib;
}
