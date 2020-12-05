#include "header.h"

void Clear(char* scene, int len) {
	for (int i = 0; scene[i] != NULL; i++) {
		scene[i] = ' ';
	}
	system("cls");
}

void Display(char * scene, int len, const char* str)
{
	Clear(scene, len);
	for (int i = 0; i < strlen(str); i++) {
		scene[i] = str[i];
	}
	printf("%s", scene);
	Sleep(2 * 1000);
}


void Initialize(char * scene, int len)
{
	// initialize
	playerValue = 0;
}

bool Input_scanf(char * scene, int len, int& playerValue)
{
	Display(scene, len, "Input(0.Exit, 1.Rock , 2.Scissors, 3.Paper):");
	scanf("%d", &playerValue);
	return true;
}

void Playgame(char * scene, int len, int& playerValue)
{
	// player
	Display(scene, len, RSP("player", playerValue));

	if (playerValue < 1 || playerValue > 3) {
		Display(scene, len, "Please re-enter...\n");
		return;
	}

	//computer
	int computer = RandomValue();
	Display(scene, len, RSP("computer", computer));

	//game
	Display(scene, len, RspValueCompare3((playerValue - computer + 3) % 3) + 1);
}

bool Gameend(char * scene, int len, int& playerValue)
{
	// game over & game clear
	if (playerValue == 0) {
		Display(scene, len, ("Stop playing RSP Game!\n"));
		return true;
	}
	return false;
}

void GameLoop(char* scene, int len, int playerValue)
{
	Initialize(scene, len, playerValue);

	while (Input(scene, len, playerValue)) {
		if (Gameend(scene, len, playerValue)) break;
		Playgame(scene, len, playerValue);
	}
}
