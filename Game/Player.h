#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Slide.h"
class Player
{
public:
	Player(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed ,float jumpHight);
	~Player();

	void Update(float deltaTime,float acc);
	void Draw(sf::RenderWindow& window);
	void OnCollosion(sf::Vector2f direction);
	bool slide();
	bool delays();
	void setpositison(sf::Vector2f xy) { body.setPosition(xy); }
	sf::Vector2f GetPosition() {return body.getPosition();}
	Collider GetCollider() { return Collider(body); }
	sf::RectangleShape body;
private:
	
	Animation animation;
	unsigned int row;
	float speed;

	sf::Vector2f velocity, Lastposi;
	bool canJump;
	float jumpHight;
	bool canSlide, delayslide;
	float SumTime;
	float delay;
};

