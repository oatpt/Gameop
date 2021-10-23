#include "Death.h"
#include <stdio.h>
Death::Death(sf::Texture* texture, sf::Vector2f size, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
	currentImage.y = 0;
}

Death::~Death()
{
}

void Death::Update(float deltaTime,float speed,bool fall)
{
	
	
	if (end == 1)
	{
		totalTime += deltaTime;
		if (totalTime >= switchTime)
		{
			totalTime -= switchTime;
			currentImage.x++;

			if (currentImage.x >= imageCount.x)
			{
				currentImage.x = 0;
				end = 0;
			}
		}
		uvRect.top = currentImage.y * uvRect.height;
		uvRect.left = currentImage.x * uvRect.width;
		body.setTextureRect(uvRect);
	}
	if (end == 0)
	{	
		currentImage.x = imageCount.x-1;
		uvRect.top = currentImage.y * uvRect.height;
		uvRect.left = currentImage.x * uvRect.width;
		body.setTextureRect(uvRect);
	}
	
	if (body.getPosition().y < 820.0f)
		velocity += 0.981f * deltaTime;
	else
		velocity = 0.0f;
	body.move(-speed * deltaTime, velocity);
	if (body.getPosition().y > 820.0f)
		body.setPosition(sf::Vector2f(body.getPosition().x, 820.0f));
	
	
}

void Death::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Death::getend(bool end)
{
	this->end = end;
}
