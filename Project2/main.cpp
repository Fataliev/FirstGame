#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include "Configure.h"

using namespace sf;


// ����� ������������������� ����� � ������ �� ������ �� �������������� 
/* ������� ���
	Player player(......)
	Map map(............)

	player.setMap(.......)
	map.setPlayer(........)
*/




int main()
{

	RenderWindow window(VideoMode(Configure::get()->getWindowWidth(), Configure::get()->getWindowHeight()), "window for fang!");

	sf::Texture t; //������� ��������
	t.loadFromFile("fang.png"); // ��������� �������� �� �����
	t.getSize ();

	float currentFrame = 0;

	Player player(t);
	Map map(&window, &player);
	

	Clock clock;

	

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); // ���� ��������� ����� � �������������
		clock.restart();

		time = time / 100;//����������� �������� ����(��� �� ���� ���������� �� ������� � �� � ���������� ) 

		if (time > 20) time = 20;

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			player.dx = -0.1;

		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			player.dx = 0.1;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (player.onGround) { player.dy = -0.35; player.onGround = false; }
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (player.onGround) { player.z = true; }
		}

		window.clear(Color::White);
		player.update(time);
		map.update(time);

		




		window.draw(player.sprite);
		window.display();
	}

	return 0;
}