#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	
	switchTime = 0.2;
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
	totalTime = 0.0f;
	currentImage.x = 0;
	currentImage.y = 0;
	uvRect.width = texture->getSize().x / 10.0f;
	uvRect.height = texture->getSize().y;
	uvRectM.width = texture->getSize().x / 2.0f;
	uvRectM.height = texture->getSize().y;
	temp.y = 0.0f;
	temp.x = 0.0f;
	diry = 1.0f;
	dirx = -1.0f;
	
}

Platform::~Platform()
{
}

void Platform::UpdateP(float deltaTime)
{

	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= 10)
		{
			currentImage.x = 0;
			
		}
	}
		uvRect.top = currentImage.y * uvRect.height;
		uvRect.left = currentImage.x * uvRect.width;
		body.setTextureRect(uvRect);
	
}

void Platform::UpdateM(float deltaTime)
{
	totalTime += deltaTime;
	if (totalTime >= 0.3)
	{
		totalTime - +0.3;
		if (body.getPosition().y>=520)
			diry =  -1.0f;
		if (body.getPosition().y <= 480)
			diry =   1.0f;
		temp.y += 0.00001*diry;
		if (temp.y > 0.01f)
			temp.y = 0.01;
		if (temp.y < -0.01f)
			temp.y = -0.01;
		
		if (body.getPosition().x>=1450)
			dirx =  -1.0f;
		if (body.getPosition().x <= 1350)
			dirx =   1.0f;
		temp.x += 0.00001*dirx;
		if (temp.x > 0.01f)
			temp.x = 0.01;
		if (temp.x < -0.01f)
			temp.x = -0.01;
		if (temp.x > 0)
		{
			uvRectM.left = uvRectM.width;
		}
		if (temp.x < 0)
		{
			uvRectM.left = 0;
		}
		
		body.move(temp);
	}
	body.setTextureRect(uvRectM);
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);

}
