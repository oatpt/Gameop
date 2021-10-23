#include "Background.h"
Background::Background(sf::Texture* texture, float switchTime) 
{
	this->switchTime = switchTime;
	body.setSize(sf::Vector2f(texture->getSize().x, texture->getSize().y));
	body.setTexture(texture);
	body.setPosition(0.0f, 0.0f);
}

Background::~Background()
{
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(body);

}

void Background::Update(float deltaTime,float acc)
{
	if (body.getPosition().x <= -5718.54)
		body.setPosition(0.0f,0.0f);
	body.move((-300.0f - acc) * deltaTime/10.0f, 0.0f);
}