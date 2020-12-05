#include "header.h"

void Clear(char* scene) {
	memset(scene, '\0', strlen(scene));
	system("cls");
}

void Display(char * scene, const char* str)
{
	Clear(scene);
	strncpy(scene, str, strlen(str));
	printf("%s", scene);
	Sleep(2 * 1000);
}


void GameLoop(char* scene, int&  playerValue)
{
	Initialize(scene, playerValue);
	while (true) {
		Display(scene, "Input(0.Rock, 1.Scissors, 2.Paper, ... exit");
		if (_kbhit()) {
			//playerValue = _getch() - 48;
			playerValue = Input(_getch());
			if (Gameend(scene, playerValue)) break;
			Playgame(scene, playerValue);
		}
	}
	exit(1);
}