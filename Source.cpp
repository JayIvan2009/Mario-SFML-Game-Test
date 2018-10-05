#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "Game.h"
#include "Menu.h"
#include "Collider.h"
#include "Platform.h"
#include "Animation.h"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1750), "Mario Jumper");
	sf::View camera;
	sf::Texture playerTexture, platformTexture;
	sf::Clock clock;
	sf::Music music;

	playerTexture.loadFromFile("mario.png");
	platformTexture.loadFromFile("brick.png");
	
	if (!music.openFromFile("mario.wav")) {
		return -1;
	}
	music.play();

	sf::Vector2f dimensions(window.getSize().x, window.getSize().y);
	Game game(dimensions);
	Menu menu(window.getSize().x, window.getSize().y);
	Platform floor(&platformTexture, sf::Vector2f(window.getSize().x, 200.0f), sf::Vector2f(500, 900));

	Player player(&playerTexture, sf::Vector2u(4, 4), 0.1f, 600.0f, 300.0f);

	sf::Vector2f position(800.0f, 600.0f);
	std::vector<Platform> platforms;

	for (int i = 0; i < 1000; i++) {
		platforms.push_back(Platform(&platformTexture, sf::Vector2f(325.0f, 35.0f), sf::Vector2f(position.x - rand() % 600, position.y)));
		position.y -= 300.0f;
	}


	float deltaTime = 0.0f;

	window.setFramerateLimit(60);
	camera.reset(sf::FloatRect(0, 0, 1000, 1000));

	static bool startGame = false;
	static bool startCamera = false;

	bool addScore = false;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			switch (event.type) {
				case sf::Event::KeyReleased:

				switch (event.key.code) {
					case sf::Keyboard::Enter:
						switch (menu.getPressedItem()) {
						case 0:
							std::cout << "Game has been started" << std::endl;
							startGame = true;
							startCamera = true;
							menu.close(window);
							break;
						case 1:
							std::cout << "High Scores has been pressed" << std::endl;
							menu.close(window);
							break;
						case 2:
							std::cout << "Exit has been pressed" << std::endl;
							menu.close(window);
							window.close();
							break;
						}
					case sf::Keyboard::W:
						menu.MoveUp();
						break;
					case sf::Keyboard::S:
						menu.MoveDown();
						break;
				}
			}
		}

		player.Update(deltaTime);

		sf::Vector2f direction;

		if (floor.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) {
			player.OnCollision(direction);
		}

		for (Platform &platform : platforms) {
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) {
				player.OnCollision(direction);
				addScore = true;
				game.scoreSystem(addScore);
			}
		}

		window.clear();
		menu.draw(window);

		if (startGame) {
			//window.draw(player);
			//window.draw(floor);
			//game.startGame(platforms, window);
			for (Platform &platform : platforms) {
				platform.Draw(window);
			}
			game.scoreSystem(addScore);
		} 
		if (startCamera) {
			game.camera(camera);
		}

		//game.move(player, event);

		floor.Draw(window);
		player.Draw(window);
		window.setView(camera);
		window.display();
	}

	return 0;
}