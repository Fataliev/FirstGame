#include "Map.h"
#include <iostream>

Map::Map(RenderWindow *windowArgPtr)
{
	windowPrivatePtr = windowArgPtr;
}


Map::~Map()
{
}



void Map::setPlayer(Player *playerArgument) {

	playerPrivatePtr = playerArgument;
}


void Map::update(float time) {
	RectangleShape rectangle(Vector2f(32, 32));
	for (int i = 0; i < tileMapHeight; i++)// описание значение символов карты в листинге 
		for (int j = 0; j < tileMapWidth; j++)
		{
			if (tileMap[i][j] == 'B')  rectangle.setFillColor(Color::Black);

			if (tileMap[i][j] == '0') rectangle.setFillColor(Color::Green);

			if (tileMap[i][j] == ' ') continue;

			rectangle.setPosition(j * 32 - playerPrivatePtr->getOffsetX(), i * 32 - playerPrivatePtr->getOffsetY());
			windowPrivatePtr->draw(rectangle);
		}

}