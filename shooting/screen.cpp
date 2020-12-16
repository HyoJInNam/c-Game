#include "screen.h"
#include "header.h"

screen::screen(int _size)
{
	size = _size;
	scene = (char*)malloc(size * sizeof(char));
	Clear();
}

bool screen::Delete()
{
	free(scene);
	return true;
}

void screen::Clear()
{
	memset(scene, ' ', size);
	scene[size] = '\0';
}

void screen::Display()
{
	printf("%s\r", scene);
	Sleep(66);
}