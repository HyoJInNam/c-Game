#include "header.h"
#include "enemy.h"

Enemy::Enemy(const char * baseFace, const char* demagedFace, const float speed)
{
	Initialize(baseFace, demagedFace, speed);
}

bool Enemy::Initialize(const char * baseFace, const char* demagedFace, const float speed)
{
	face_size = strlen(baseFace) + 1;
	this->face = (char*)malloc(sizeof(char) * face_size);
	memset(this->face, '\0', face_size);

	this->baseFace = (char*)malloc(sizeof(char) * face_size);
	memset(this->baseFace, '\0', face_size);
	mStrncpy_s(this->baseFace, face_size - 1, baseFace, face_size - 1);

	this->demagedFace = (char*)malloc(sizeof(char) * face_size);
	memset(this->demagedFace, '\0', face_size);
	mStrncpy_s(this->demagedFace, face_size - 1, demagedFace, face_size - 1);

	isActive = false;
	isDemaged = false;
	srand(rand());
	pos = (rand() % 2 ^ 1) ? 1 : 80 - face_size - 1;
	this->speed = speed;

	delay = (1 / this->speed) * 2.5f;
	delta_time = 0;
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

	// update face
	if (isDemaged == true)
	{
		if (delay <= delta_time)
		{
			isDemaged = false;
			delta_time = 0;
		}
		mStrncpy_s(this->face, face_size - 1, demagedFace, face_size - 1);
		delta_time++;
	}
	else
	{
		mStrncpy_s(this->face, face_size - 1, baseFace, face_size - 1);
	}

	// update movement
	if (pos + face_size < player->pos) { 
		pos += speed;
	}
	else if (pos > player->pos + player->face_size) {
		pos -= speed;
	}
	else {
		// collide palyer
		this->Dead();
		//player->Dead();
	}
}

void Enemy::Dead()
{
	isActive = false;
	pos = (rand() % 2 ^ 1) ? 1 : 80 - face_size - 1;
}
