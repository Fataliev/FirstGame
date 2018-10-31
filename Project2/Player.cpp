#include "Player.h"
#include "Configure.h"


Player::Player(sf::Texture image)
{
	sprite.setTexture(image);
	rect = FloatRect(2 * 32, 2 * 32, 40, 50); // начальное положение игрока (где 40 и 50 размер персанажа в картинке)
	dx = dy = 0.1;
	z = false;//это не нужно
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

	rect.left += dx * time;//координаты X
	collision(0);//столкновение по Х

	if (!onGround) dy = dy + 0.0005*time;
	rect.top += dy * time;//по сути координата У
	onGround = false;
	collision(1);





	currentFrame += 0.005*time; //скорость анимации
	// нужно еще как то неподвижность поделить на левую и правую 
	if (dy == 0) {

		if (dx > 0) {
			if (currentFrame > 6) currentFrame -= 6;//количество кадров
			sprite.setTextureRect(IntRect(40 * int(currentFrame), 244, 40, 50));
		}

		if (dx < 0)
		{
			if (currentFrame > 6) currentFrame -= 6;//количество кадров
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
			if (currentFrame > 3) currentFrame -= 3;//количество кадров
			sprite.setTextureRect(IntRect(35 * int(currentFrame), 525, 40, 50));
		}
		if (dx < 0)
		{
			if (currentFrame > 3) currentFrame -= 3;//количество кадров
			sprite.setTextureRect(IntRect(35 * int(currentFrame) + 40, 525, -40, 50));
		}
		if (dx == 0)
		{
			sprite.setTextureRect(IntRect(0, 1590, 45, 55));//вертикальный прыжок
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
			sprite.setTextureRect(IntRect(0, 1370, 40, 55));//вертикальное падение 
		}
	};


	if (z == true)
	{
		if ((dy == 0) && (dx == 0)) sprite.setTextureRect(IntRect(0, 1430, 40, 40));
	};

	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);


	// о1бнуление 
	dx = 0;
	z = false;


	if (rect.left > (Configure::get()->getWindowWidth() / 2)) offsetX = rect.left - (Configure::get()->getWindowWidth() / 2);//если подошли к краю слева, то карта не двигается

	if (rect.top < (680)) offsetY = rect.top - Configure::get()->getWindowHeight() / 2; //Надо как то на что то поделить

}

void Player::collision(int dir)//функция взаимодействия персонажа с миром
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