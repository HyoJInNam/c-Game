#include "header.h"
#include "enemy.h"

Enemy::Enemy(const char * face, const float speed)
{
	Initialize(face, speed);
}

bool Enemy::Initialize(const char * face, const float speed)
{
	isActive = false;

	face_size = strlen(face) + 1;
	this->face = (char*)malloc(sizeof(char) * face_size);
	memset(this->face, '\0', face_size);
	mStrncpy_s(this->face, face_size - 1, face, face_size - 1);

	srand(rand());
	pos = (rand() % 2 ^ 1) ? 1 : 80 - face_size - 1;
	this->speed = speed;
	return true;
}

bool Enemy::Delete()
{
	free(face);
	return true;
}

void Enemy::Draw(Screen * screen, Player* player) const
{
	if (isActive == false) return;
	mStrncpy_s(screen->scene + (int)pos, screen->size - (int)pos, face, face_size - 1);
}

void Enemy::Update(const Screen * screen, Player* player)
{
	if (isActive == false) return;
	if ((pos < 0) || (pos > screen->size - face_size)) {
		Dead();
		return;
	}

	if (pos + face_size < player->pos) { 
		pos += speed;
	}
	else if (pos > player->pos + player->face_size) {
		pos -= speed;
	}
	else {
		// player¿Í Ãæµ¹
		this->Dead();
		player->Dead();
	}
}

void Enemy::Dead()
{
	isActive = false;
	pos = (rand() % 2 ^ 1) ? 1 : 80 - face_size - 1;
}
