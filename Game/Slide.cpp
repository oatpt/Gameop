#include "Slide.h"
static const float VIEW_WIDTH = 1920.0f;
Slide::Slide(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	body.setSize(sf::Vector2f(200.0f, 160.0f));
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);
	body.setTexture(texture);
	body.setPosition(100.0f, 1500.0f);
}

Slide::~Slide()
{
}

void Slide::Draw(sf::RenderWindow& window)
{
	window.draw(body);

}

void Slide::Update(float deltaTime,bool canSlide,bool delayslide,float acc)
{
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && body.getPosition().x > body.getOrigin().x && canSlide)
		velocity.x -= (speed + acc);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && body.getPosition().x < VIEW_WIDTH - body.getOrigin().x * 2.2f)
		velocity.x += (speed + acc);
	if (!canSlide&&!delayslide&&can)
	{
		body.setPosition(GetPosition().x, 900.0f- body.getSize().y / 2.0f);
		//printf("GO\n");
		SumTime = 0;
		can = false;
	}
	if (!can)
	{
		SumTime += deltaTime;
		//printf("%f\n", SumTime);
		if (SumTime > 1.0)
		{
			can = true;
			body.setPosition(GetPosition().x, GetPosition().y + 1000);
		}
	}
	

	animation.Update(0, deltaTime);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}
