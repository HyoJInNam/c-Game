#include "header.h"
#include "enemy.h"

enemy::enemy(const char * face)
{
	Initialize(face);
}

bool enemy::Initialize(const char * face)
{
	isActive = false;

	face_size = strlen(face);
	this->face = (char*)malloc(sizeof(char) * face_size);
	mStrncpy_s(this->face, face_size, face, face_size);

	srand(rand());
	pos = (rand() % 2 ^ 1) ? 1 : 80 - face_size - 1;
	speed = 0.2f;
	return true;
}

bool enemy::Delete()
{
	free(face);
	return true;
}

void enemy::Draw(const Screen * screen, const Player* player)
{
	if (!isActive) return;
	if ((pos < 0) || (pos > screen->size - face_size)) {
		Dead();
		return;
	}
	mStrncpy_s(screen->scene + (int)pos, screen->size - (int)pos, face, face_size);
}

void enemy::Update(const Screen * screen, const Player* player)
{
	if (!isActive) return;
	
	if (pos + face_size < player->pos) { 
		pos += speed;
	}
	else if (pos > player->pos + player->face_size) {
		pos -= speed;
	}
	else {
		// player¿Í Ãæµ¹
		Dead();
	}
}

void enemy::Dead()
{
	isActive = false;
	pos = (rand() % 2 ^ 1) ? 1 : 80 - face_size - 1;
}
