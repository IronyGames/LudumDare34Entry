#include "Utils.h"

ciColor Utils::rgbColor(double r, double g, double b)
{
	double max = 256;
	return ciColor(r / max, g / max, b / max);
}

ciColor Utils::hexColor(String hex)
{
	return ciColor();
}
