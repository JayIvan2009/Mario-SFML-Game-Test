#include "Particle.h"
#include <SFML/Graphics.hpp>
#include <math.h>

void Particle::update() {
	vel = acc + vel;
	pos = vel + pos;
}

float Particle::distance(float x1, float x2, float y1, float y2) {
	float dist;
	float x = x2 - x1;
	float y = y2 - y1;

	dist = sqrt((x*x) + (y*y));

	return dist;
}
