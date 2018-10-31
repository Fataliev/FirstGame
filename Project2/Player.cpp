#include "Player.h"
#include "Configure.h"


Player::Player(sf::Texture image)
{
	sprite.setTexture(image);
	rect = FloatRect(2 * 32, 2 * 32, 40, 50); // ��������� ��������� ������ (��� 40 � 50 ������ ��������� � ��������)
	dx = dy = 0.1;
	z = false;//��� �� �����
	currentFrame = 0;
}


Player::~Player()
{
}

void Player::setMap(Map *mapArgument) {

	mapPrivatePtr = mapArgument;
}



void Player::update(float time)
{

	rect.left += dx * time;//���������� X
	collision(0);//������������ �� �

	if (!onGround) dy = dy + 0.0005*time;
	rect.top += dy * time;//�� ���� ���������� �
	onGround = false;
	collision(1);





	currentFrame += 0.005*time; //�������� ��������
	// ����� ��� ��� �� ������������� �������� �� ����� � ������ 
	if (dy == 0) {

		if (dx > 0) {
			if (currentFrame > 6) currentFrame -= 6;//���������� ������
			sprite.setTextureRect(IntRect(40 * int(currentFrame), 244, 40, 50));
		}

		if (dx < 0)
		{
			if (currentFrame > 6) currentFrame -= 6;//���������� ������
			sprite.setTextureRect(IntRect(40 * int(currentFrame) + 40, 244, -40, 50));
		}
		if (dx == 0)
		{
			sprite.setTextureRect(IntRect(0, 191, 40, 50));
		}
	};


	if (dy < 0) {

		if (dx > 0)
		{
			if (currentFrame > 3) currentFrame -= 3;//���������� ������
			sprite.setTextureRect(IntRect(35 * int(currentFrame), 525, 40, 50));
		}
		if (dx < 0)
		{
			if (currentFrame > 3) currentFrame -= 3;//���������� ������
			sprite.setTextureRect(IntRect(35 * int(currentFrame) + 40, 525, -40, 50));
		}
		if (dx == 0)
		{
			sprite.setTextureRect(IntRect(0, 1590, 45, 55));//������������ ������
		}

	};

	if (dy > 0) {

		if (dx > 0)
		{
			sprite.setTextureRect(IntRect(0, 1310, 45, 50));
		}
		if (dx < 0)
		{
			sprite.setTextureRect(IntRect(45, 1310, -45, 50));
		}
		if (dx == 0)
		{
			sprite.setTextureRect(IntRect(0, 1370, 40, 55));//������������ ������� 
		}
	};


	if (z == true)
	{
		if ((dy == 0) && (dx == 0)) sprite.setTextureRect(IntRect(0, 1430, 40, 40));
	};

	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);


	// �1�������� 
	dx = 0;
	z = false;


	if (rect.left > (Configure::get()->getWindowWidth() / 2)) offsetX = rect.left - (Configure::get()->getWindowWidth() / 2);//���� ������� � ���� �����, �� ����� �� ���������

	if (rect.top < (680)) offsetY = rect.top - Configure::get()->getWindowHeight() / 2; //���� ��� �� �� ��� �� ��������

}

void Player::collision(int dir)//������� �������������� ��������� � �����
{
	//for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
	//	for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
	//	{
	//		if (tileMap[i][j] == 'B')
	//		{
	//			if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
	//			if ((dx < 0) && (dir == 0)) rect.left = j * 32 + 32;
	//			if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;   onGround = true; }
	//			if ((dy < 0) && (dir == 1)) { rect.top = i * 32 + 32;   dy = 0; }
	//		}

	//		if (tileMap[i][j] == '0')
	//		{
	//			tileMap[i][j] = ' ';
	//		}

	//	}

}