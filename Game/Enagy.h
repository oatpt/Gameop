#pragma once
#include <SFML\Graphics.hpp>
class Enagy
{
public:
	Enagy(sf::Texture* texture, sf::Vector2f position);
	~Enagy();
	void Update(int score);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape body;

private:
	sf::IntRect uvRect;
	sf::Vector2f box;
};
