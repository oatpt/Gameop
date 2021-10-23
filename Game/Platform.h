#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
class Platform
{
public:
	Platform(sf::Texture* texture,sf::Vector2f size,sf::Vector2f position);
	~Platform();

	void Draw(sf::RenderWindow& window);
	void UpdateP(float deltaTime);
	void UpdateM(float deltaTime);
	Collider GetCollider() { return Collider(body); }
	sf::RectangleShape body;
	sf::IntRect uvRect;
	sf::IntRect uvRectM;
private:
	float totalTime;
	float switchTime;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	sf::Texture* texture;
	sf::Vector2f temp;
	float diry, dirx;
};


