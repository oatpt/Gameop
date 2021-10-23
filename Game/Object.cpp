#include "Object.h"
#include <time.h>

Object::Object(sf::Texture* texture, sf::Vector2f size,float Hight)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
	Randdom(Hight);
}

Object::~Object()
{
}
void Object::Update(float speed,float deltaTime)
{
	body.move(-speed*deltaTime, 0.0f);
}

void Object::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
void Object::Randdom(float Hight)
{
	int x = rand() % 10;
	
	if (x<7)
	{
		body.setPosition(2000.0f, 820.0f);
	}
	else
	{
		body.setPosition(2000.0f, 500.0f+ Hight);
	}

}