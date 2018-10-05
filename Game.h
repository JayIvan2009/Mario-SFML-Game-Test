#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

class Game
{
public:
	Game(sf::Vector2f dimensions);
	~Game();

	void camera(sf::View &camera);
	void scoreSystem(bool score);

private:
	float level = 0.0;
	sf::Text score;
	sf::Vector2f position;
	int i = 0;
};

