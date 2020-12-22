#include "player.h"
#include "header.h"

player::player(const char * _face, int _pos)
{
	pos = _pos;
	face_size = strlen(_face);
	face = (char*)malloc(sizeof(char) * face_size);
	mStrncpy_s(face, face_size, _face, face_size);
}

bool player::Delete()
{
	free(face);
	return true;
}

void player::Input()
{
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			pos--;
			mStrncpy_s(face, face_size, "¦¯0-0", face_size);
			break;

		case 'd':
			pos++;
			mStrncpy_s(face, face_size, "0-0¦®", face_size);
			break;

		case ' ':

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
