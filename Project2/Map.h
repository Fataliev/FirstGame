#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;

class Map
{

public:
	Map(RenderWindow *window, Player *playerArgument);
	~Map();
	void update(float time);


	int tileMapHeight = 30;
	int tileMapWidth = 70;

	RenderWindow *windowPrivatePtr = nullptr;
	Player *playerPrivatePtr = nullptr;

	sf::String tileMap[30] = {
		/*
		"BBBBBBBBB0BBBBBBBBB0BBBBBBBBB0BBBBBBBBB0",
		"B                                      B",
		"B                                      B",
		"B                  0        B          B",
		"B                  0                   B",
		"B                  0          BBB      B",
		"B                                B     B",
		"BBB                              B     B",
		"B              BB                BB    B",
		"B     B        BB                      B",
		"B    B         BB         BB           B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		*/
			"BBBBBBBBB0BBBBBBBBB0BBBBBBBBB0BBBBBBBBB0BBBBBBBBB0BBBBBBBBB0BBBBBBBBB0",
			"B                                                                    B",
			"BB                                                                   B",
			"B                                                                    B",
			"B                                                                    B",
			"BBBB  BBB                                                            B",
			"B           B                                                       B ",
			"B                                                                  B  ",
			"B                                                                 B   ",
			"B            B                                                   B    ",
			"B          B                                                    B     ",
			"B         B                                                    B      ",
			"B        B                                                    B       ",
			"B    B                                                       B        ",
			"B     B                                                     B         ",
			"B      B                                                   B          ",
			"BB      B                                                 B           ",
			"B B        B                                             B            ",
			"B  B     0                                              B            B",
			"B  B                                                   B              ",
			"B   B                                                 B               ",
			"B    B                                               B                ",
			"B     B                                             B                 ",
			"B      B                                           B                  ",
			"B       B                                         B                   ",
			"B        B                                       B                    ",
			"B         B                                     B                     ",
			"B          B                                   B                      ",
			"B           B        0                        B                      B",
			"BBBBBBBBBBBBBBBBBBB0BBBBBBBBB0BBBBBBBBB0BBBBBBBBB0BBBBBBBBB0BBBBBBBBB0",

	};


	



};





