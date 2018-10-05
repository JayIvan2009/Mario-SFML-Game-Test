#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>


Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture,imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(125.0f, 100.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(500.0f, 650.0f);
	body.setTexture(texture);
}


Player::~Player()
{
}

void Player::Update(float deltaTime) {
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocity.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocity.x += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump) {
		canJump = false;
		std::cout << "Jump!" << std::endl;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		if (!buffer.loadFromFile("jump.wav")) {
			std::cout << "File not found!" << std::endl;
		}
		jump.setBuffer(buffer);
		jump.play();
	}

	velocity.y += 981.0f * deltaTime;

	std::cout << velocity.y << std::endl;
	if (velocity.x == 0.0f) {
		row = 0;
	}
	else {
		row = 1;

		if (velocity.x > 0.0f) {
			faceRight = true;
		}
		else {
			faceRight = false;
		}
	}
	if (velocity.y < 0.0f) {
		row = 2;
	}
	if (!canJump && velocity.y > 0.0f) {
		row = 3;
	}

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow &window) {
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction) {
	if (direction.x < 0.0f) {
		// Collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f) {
		// Collision on the right
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f) {
		// Collision on the bottom
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f) {
		// Collision on the top
		velocity.y = 0.0f;
	}
}