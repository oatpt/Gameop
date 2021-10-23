#pragma once
#include <SFML\Graphics.hpp>
class Death
{
public:
	Death(sf::Texture* texture, sf::Vector2f size, sf::Vector2u imageCount, float switchTime);
	~Death();
	void Update(float deltaTime, float speed, bool fall);
	void Draw(sf::RenderWindow& window);
	void getend(bool end);
	sf::RectangleShape body;
	void setpositison(sf::Vector2f xy) { body.setPosition(xy); }
	void reset() { 
		currentImage.x = 0.0f; 
		velocity = 0.0f;
	}
public:
	sf::IntRect uvRect;
	bool end = false;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float velocity;
	float totalTime;
	float switchTime;
};


