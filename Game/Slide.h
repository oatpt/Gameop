#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "Animation.h"
class Slide
{
public:
	Slide(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Slide();
	void Update(float deltaTime, bool canSlide,bool delayslide,float acc);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	sf::RectangleShape body;
	void setpositison(sf::Vector2f xy) { body.setPosition(xy); }
private:
	sf::Vector2f velocity, Lastposi;
	Animation animation;
	float speed;
	float SumTime;
	bool can;
};

