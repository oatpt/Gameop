#include "Enagy.h"

Enagy::Enagy(sf::Texture* texture, sf::Vector2f position)
{

	body.setSize(sf::Vector2f(150.0f, 100.0f));
	body.setOrigin(sf::Vector2f(150.0f, 100.0f) / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
	box.x = texture->getSize().x;
	box.y = texture->getSize().y;
}

Enagy::~Enagy()
{

}

void Enagy::Update(int score)
{
	uvRect.left = box.x / 5.0f * score ;
	uvRect.top = 0;
	uvRect.height = box.y;
	uvRect.width = box.x / 5.0f;
	body.setTextureRect(uvRect);
}

void Enagy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
