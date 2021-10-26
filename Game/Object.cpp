#include "Object.h"
#include <time.h>

Object::Object(sf::Texture* texture, sf::Vector2f size,int Hight, int x)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
	Randdom(Hight,x);
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
void Object::Randdom(int Hight, int x)
{
	if (Hight>7||x)
	{
		body.setPosition(2000.0f+x, 500.0f+Hight);
	}
	else
	{
		body.setPosition(2000.0f+x, 820.0f);
	}

}