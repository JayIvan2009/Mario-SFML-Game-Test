#include <SFML/Graphics.hpp>
#include <stdio.h>

class Particle {
public:
	Particle() {
		acc = sf::Vector2f(0, 0);
		vel = sf::Vector2f(0, 0);
		pos = sf::Vector2f(0, 0);
	};
	
	void update();
	float distance(float, float, float, float);

	sf::Vector2f acc;
	sf::Vector2f vel;
	sf::Vector2f pos;

};

