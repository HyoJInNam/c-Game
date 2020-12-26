#include "player.h"
#include "header.h"

player::player(const char * _face, int _pos)
{
	pos = _pos;
	direct = 1;
	face_size = strlen(_face);
	face = (char*)malloc(sizeof(char) * face_size);
	mStrncpy_s(face, face_size, _face, face_size);
}

bool player::Delete()
{
	free(face);
	return true;
}

void player::Input(Bullet* bullet)
{
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
			bullet->isActive = true;
			if (direct <= 0) {
				bullet->pos = pos;
				mStrncpy_s(bullet->face, bullet->face_size, bullet->left_face, bullet->face_size);

			}
			else {
				bullet->pos = pos + face_size + 1;
				mStrncpy_s(bullet->face, bullet->face_size, bullet->right_face, bullet->face_size);
			}
			
			break;

		case 'q':
			return;

		default:
			break;
		}
	}
}

void player::Draw(Screen* screen)
{
	if (pos < 0)  pos = 0;
	else if (pos > screen->size - face_size) pos = screen->size - face_size;
	mStrncpy_s(screen->scene + pos, screen->size - pos, face, face_size);
}
