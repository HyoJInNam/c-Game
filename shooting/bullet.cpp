#include "header.h"
#include "bullet.h"

bullet::bullet(const Player * player, const char * left_face, const char * right_face)
{
	face_size = strlen(left_face);
	this->face = (char*)malloc(sizeof(char) * face_size);

	//left
	this->left_face = (char*)malloc(sizeof(char) * face_size);
	mStrncpy_s(this->left_face, face_size, left_face, face_size);
	//right
	this->right_face = (char*)malloc(sizeof(char) * face_size);
	mStrncpy_s(this->right_face, face_size, right_face, face_size);

	Initialize(player);
}

bool bullet::Initialize(const Player * player)
{
	isActive = false;
 	mStrncpy_s(face, face_size, (player->direct <= 0) ? left_face : right_face, face_size);
	pos = player->pos;
	speed = 0.5f;
	return true;
}

bool bullet::Delete()
{
	free(left_face);
	free(right_face);
	return false;
}

void bullet::Draw(const Screen * screen, const Player * player)
{
	if (!isActive) return;
	if ((pos < 0) || (pos > screen->size - face_size)) {
		Dead();
		return;
	}
	mStrncpy_s(screen->scene + (int)pos, screen->size - (int)pos, face, face_size);
}

void bullet::Update(const Screen * screen)
{
	if (!isActive) return;

	if (*face == *left_face) {
		pos -= speed;
	}
	else if (*face == *right_face) {
		pos += speed;
	}
	else {
		// enemy¿Í Ãæµ¹
		Dead();
	}
}

void bullet::Dead()
{
	isActive = false;
}
