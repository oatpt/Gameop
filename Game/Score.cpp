#include "Score.h"

Score::Score(sf::Texture* texture, sf::Vector2f position)
{
	
	body.setSize(sf::Vector2f(50.0f, 100.0f));
	body.setOrigin(sf::Vector2f(50.0f, 100.0f) / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
	box.x = texture->getSize().x;
	box.y = texture->getSize().y;
}

Score::~Score()
{

}

void Score::Update(int score)
{
	if(score>=1&& score <= 9)
		uvRect.left = box.x / 10.0f * (score-1);
	else if(score == 0)
		uvRect.left = box.x / 10.0f * 9.0f;
	uvRect.top = 0;
	uvRect.height = box.y;
	uvRect.width = box.x/10.0f;
	body.setTextureRect(uvRect);
}

/*void Score::UpdateE(int score)
{
	if (score >= 1 && score <= 9)
		uvRect.left = box.x / 10.0f * (score - 1);
	else if (score == 0)
		uvRect.left = box.x / 10.0f * 9.0f;
	uvRect.top = 0;
	uvRect.height = box.y;
	uvRect.width = box.x / 10.0f;
	body.setTextureRect(uvRect);
}*/

void Score::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
