#include "Header.h"
#include "Bullet.h"

Bullet::Bullet(Player * player, const char * left_face, const char * right_face, const float speed)
{
	Initialize(player, left_face, right_face, speed);
}

bool Bullet::Initialize(Player * player, const char * left_face, const char * right_face, const float speed)
{
	this->face_size = strlen(left_face) + 1;
	this->face = (char*)malloc(sizeof(char) * face_size);
	memset(this->face, '\0', face_size);

	//left
	this->left_face = (char*)malloc(sizeof(char) * face_size);
	memset(this->left_face, '\0', face_size);
	mStrncpy_s(this->left_face, face_size - 1, left_face, face_size - 1);
	//right
	this->right_face = (char*)malloc(sizeof(char) * face_size);
	memset(this->right_face, '\0', face_size);
	mStrncpy_s(this->right_face, face_size - 1, right_face, face_size - 1);

	player->Shoot(this);

	isActive = false;
	this->speed = speed;
	return true;
}

bool Bullet::Delete()
{
	free(left_face);
	free(right_face);
	free(face);
	return false;
}

void Bullet::Draw(Screen * screen, Player * player) const
{
	if (isActive == false) return;
	mStrncpy_s(screen->scene + (int)pos, screen->size - (int)pos, face, face_size - 1);
}

void Bullet::Update(const Screen * screen, const Player * player, Enemies* enemies)
{
	if (isActive == false) return;
	if (face == NULL) return;
	if ((pos < 0) || (pos > screen->size - face_size))
	{
		Dead();
		return;
	}

	// collide enemey
	for (int i = 0; i < enemies->max_size; i++)
	{
		if (enemies->objects[i].isActive &&
			enemies->objects[i].pos <= pos && enemies->objects[i].pos + enemies->objects[i].face_size - 1 >= pos)
		{
			this->Dead();
			//enemies->objects[i].Dead();
			enemies->objects[i].isDemaged = true;
			return;
		}
	}

	// update movement 
	pos += (*face == *left_face) ? negative(speed) : speed;
}

void Bullet::Dead()
{
	isActive = false;
	pos = -1;
}
