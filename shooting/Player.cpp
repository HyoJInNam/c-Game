
#include "Header.h"
#include "Player.h"

Player::Player(const char * face, int pos)
{
	isActive = true;
	this->pos = pos;
	direct = 1;

	this->face_size = strlen(face) + 1;
	this->face = (char*)malloc(sizeof(char) * face_size);
	memset(this->face, '\0', face_size);
	mStrncpy_s(this->face, face_size - 1, face, face_size - 1);
}

bool Player::Delete()
{
	free(face);
	return true;
}

void Player::Input(Bullet* bullet)
{
	if (isActive == false) return;
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			pos--;
			direct = 0;
			mStrncpy_s(face, face_size, "¦¯0-0", face_size);
			break;

		case 'd':
			pos++;
			direct = 1;
			mStrncpy_s(face, face_size, "0-0¦®", face_size);
			break;

		case ' ':
			Shoot(bullet);
			break;

		case 'q':
			return;

		default:
			break;
		}
	}
}

void Player::Update(const Screen * screen)
{
	if (pos < 0)  pos = 0;
	else if (pos > screen->size - face_size) pos = screen->size - face_size;
}

void Player::Draw(Screen* screen) const
{
	if (isActive == false) return;
	mStrncpy_s(screen->scene + pos, screen->size - pos, face, face_size - 1);
}

void Player::Dead()
{
	isActive = false;
}

void Player::Shoot(Bullet * bullet)
{
	bullet->isActive = true;

	if (direct <= 0)
	{
		bullet->pos = pos;
		mStrncpy_s(bullet->face, bullet->face_size, bullet->left_face, bullet->face_size);
	}
	else
	{
		bullet->pos = pos + face_size + 1;
		mStrncpy_s(bullet->face, bullet->face_size, bullet->right_face, bullet->face_size);
	}
}