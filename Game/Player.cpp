#include "Player.h"
#include <stdio.h>
static const float VIEW_WIDTH = 1920.0f;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHight):
	animation(texture,imageCount,switchTime)
{
	this->speed = speed;
	this->jumpHight = jumpHight;
	row = 0;

	body.setSize(sf::Vector2f(160.0f, 200.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(100.0f, 920.0f - body.getSize().y / 2.0f);
	body.setTexture(texture);
	delay = false;
}
Player::~Player()
{

}


void Player::Update(float deltaTime,float acc)
{
	velocity.x = 0.0f;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&body.getPosition().x>body.getOrigin().x&& canSlide)
		velocity.x -= (speed + acc) ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && body.getPosition().x < VIEW_WIDTH-body.getOrigin().x*2.2f)
		velocity.x += (speed + acc) ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&canJump && canSlide)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHight);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && canJump && canSlide)
	{
		canSlide = false;
		body.setPosition(GetPosition().x, GetPosition().y + 1000);
		//printf("GO\n");
		SumTime = 0;
	}
	if (!canSlide&&!delayslide)
	{
		SumTime += deltaTime;
		//printf("%f\n", SumTime);
		if (SumTime > 1.0)
		{
			delayslide = true;
			delay = 0.0f;
			body.setPosition(GetPosition().x, 920.0f - body.getSize().y / 2.0f);
		}
	}
	if (delayslide)
	{
		delay += deltaTime;
		
		if (delay > 0.2)
		{
			canSlide = true;
			delayslide = false;
		}
	}
	velocity.y += 981.0f * deltaTime;

	row = 0;
	animation.Update(row, deltaTime);
	body.setTextureRect(animation.uvRect);
	body.move(velocity*deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollosion(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
	}

	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		velocity.y = 0.0f;
		canJump = true;
	}

	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f;
	}
}

bool Player::slide()
{
	return canSlide;
}

bool Player::delays()
{
	return delayslide;
}
