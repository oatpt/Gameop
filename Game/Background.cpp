#include "Background.h"
static const float VIEW_WIDTH = 1920.0f;
static const float VIEW_HIGHT = 2200.0f;
Background::Background(sf::Texture* texture, float switchTime) 
{
	this->switchTime = switchTime;
	body.setSize(sf::Vector2f(texture->getSize().x, texture->getSize().y));
	body.setTexture(texture);
	body.setPosition(0.0f, -500.0f);
}

Background::~Background()
{
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(body);

}

void Background::Update(float deltaTime)
{
	if (body.getPosition().x <= -11437.084615)
		body.setPosition(0.0f,-500.0f);
	body.move(-0.1f, 0.0f);
}