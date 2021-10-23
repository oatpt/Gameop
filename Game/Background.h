#pragma once
#include <SFML\Graphics.hpp>
class Background
{
public:
	Background(sf::Texture* texture,float switchTime);
	~Background();
	void Update(float deltaTime, float acc);
	void Draw(sf::RenderWindow& window);
	sf::RectangleShape body;
	sf::IntRect uvRect;
private:
	float totalTime;
	float switchTime;
	float currentx;
};

