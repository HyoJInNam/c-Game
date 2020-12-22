#include <stdlib.h>
#include "header.h"
#include "player.h"
#include "enemy.h"

enemy::enemy(const char * face)
	: isActive(true)
{
	face_size = strlen(face);
	this->face = (char*)malloc(sizeof(char) * face_size);
	mStrncpy_s(this->face, face_size, face, face_size);

	srand(rand());
	pos = (rand() % 2 ^ 1)? 0 : 80 - face_size - 1;
}

bool enemy::Delete()
{
	free(face);
	return true;
}

void enemy::Update(const Screen * screen, const Player* player)
{
	if (pos + face_size < player->pos) { 
		pos++;
	}
	else if (pos > player->pos + player->face_size) {
		pos--;
	}

	// player¿Í Ãæµ¹
	isActive = false;
}

void enemy::Draw(const Screen * screen, const Player* player)
{
	if (!isActive) return;
	if ((pos < 0) || (pos > screen->size - face_size)) return;
	mStrncpy_s(screen->scene + pos, screen->size - pos, face, face_size);
}
