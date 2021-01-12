
#include "Header.h"
#include "Screen.h"

Screen::Screen(int _size)
{
	size = _size;
	scene = (char*)malloc(size * sizeof(char));
	Clear();
}

bool Screen::Delete()
{
	free(scene);
	return true;
}

void Screen::Clear()
{
	memset(scene, ' ', size);
	scene[size] = '\0';
}

void Screen::Display()
{
	printf("%s\r", scene);
	Sleep(66);
}