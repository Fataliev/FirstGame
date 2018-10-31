#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
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

	void setMap (Map *mapArgument);


	void update(float time);
	float getOffsetX() { return offsetX; }
	float getOffsetY() { return offsetY; }

private:
	void collision(int dir);
	float offsetX = 0;
	float offsetY = 0;
	Map *mapPrivatePtr = nullptr;
};

