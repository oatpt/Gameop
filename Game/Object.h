#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
class Object
{
public:
	Object(sf::Texture* texture, sf::Vector2f size,int Hight,int x);
	~Object();
	void Update( float speed, float deltaTime);
	void Draw(sf::RenderWindow& window);
	void Randdom(int Hight, int x);
	Collider GetCollider() { return Collider(body); }
	sf::RectangleShape body;
private:
	float Randcoin;
};