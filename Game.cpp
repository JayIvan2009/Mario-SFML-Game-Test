#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Game.h"
#include <string>

Game::Game(sf::Vector2f dimensions) {
	position = dimensions;
	score.setString(std::to_string(i));
	score.setPosition(position);
}

Game::~Game()
{
}


void Game::camera(sf::View &camera) {
	std::cout << level << std::endl;
	if (level >= 0.0 && level < 15.0) {
		camera.move(0.0f, -2.5f);
	}
	else if (level >= 15.0 && level < 30.0) {
		camera.move(0.0f, -5.0f);
	}
	else if (level >= 30.0 && level < 45.0) {
		camera.move(0.0f, -7.5f);
	}
	else if (level >= 45.0 && level < 60.0) {
		camera.move(0.0f, -10.0f);
	}
	else if (level >= 60.0 && level < 75.0) {
		camera.move(0.0f, -12.5f);
	}
	else if (level >= 75.0 && level < 90.0) {
		camera.move(0.0f, -15.0f);
	}
	level += 1.0 / 60.0;
}

void Game::scoreSystem(bool addScore) {
	if (addScore) {
		i++;
		score.setString(std::to_string(i));
	}
}