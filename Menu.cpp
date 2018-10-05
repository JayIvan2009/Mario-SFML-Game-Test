#include "Menu.h"
#include <iostream>


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("mario.ttf")) {
		std::cout << "Can't find font!" << std::endl;
	}

	menu[0].setFont(font);
	menu[0].setCharacterSize(50);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2 - 55, height - 1400));

	menu[1].setFont(font);
	menu[1].setCharacterSize(50);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("High Scores");
	menu[1].setPosition(sf::Vector2f(width / 2 - 160, height - 1300));

	menu[2].setFont(font);
	menu[2].setCharacterSize(50);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2 - 55, height - 1200));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window) {
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
};

void Menu::MoveDown() {
	if (selectedItemIndex + 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
};

void Menu::close(sf::RenderWindow &window) {
	menu[0].setFillColor(sf::Color::Black);
	menu[1].setFillColor(sf::Color::Black);
	menu[2].setFillColor(sf::Color::Black);
}