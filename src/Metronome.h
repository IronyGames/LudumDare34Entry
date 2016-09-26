class Metronome{
private:
	unsigned int bps;
	unsigned int fps;
	double ratio;
	unsigned int frameCounter;
	unsigned int fib;
public:
	Metronome(int _bps, int _fps);
	void update();
	int getBeat();
	void changeBeat(unsigned int _newBPS);
	void reset();
	bool hasBeatJustChanged();
	int getFramesInBeat();
}; 