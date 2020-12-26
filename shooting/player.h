#pragma once
#include "header.h"

typedef struct bullet Bullet;

typedef struct player {
	char* face;
	int face_size;
	int pos;
	int direct;

	player(const char* face, int pos);
	bool Delete();

	void Input(Bullet* bullet);
	void Draw(Screen* screen);
}Player;