#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
class Object
{
public:
	Object(sf::Texture* texture, sf::Vector2f size,float Hight);
	~Object();
	void Update( float speed, float deltaTime);
	void Draw(sf::RenderWindow& window);
	void Randdom(float Hight);
	Collider GetCollider() { return Collider(body); }
	sf::RectangleShape body;
private:
	float Randcoin;
};