#pragma once
#include <SFML\Graphics.hpp>
class Score
{
public:
	Score(sf::Texture* texture, sf::Vector2f position);
	~Score();
	void Update(int score);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape body;

private:
	sf::IntRect uvRect;
	sf::Vector2f box;
};
