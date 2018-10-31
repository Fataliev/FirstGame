#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
public:
	Player(sf::Texture image);
	~Player();

	float dx, dy;
	bool z;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;

	void update(float time);
	float getOffsetX() { return offsetX; }
	float getOffsetY() { return offsetY; }

private:
	void collision(int dir);
	float offsetX = 0, offsetY = 0;

};

