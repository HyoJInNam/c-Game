#include"header.h"


void Initialize(char * scene, int& playerValue)
{
	// initialize
	srand(3);
	memset(scene, '\0', strlen(scene));
	playerValue = 0;
}

int Input(int value)
{
	if (value - 48 >= 0 && value - 48 <= 2)
		return value - 48;
	else
		return -1;
}

void Playgame(char * scene, int& playerValue)
{
	char temp[50] = { 0, };
	memset(temp, '\0', strlen(temp));
	if (playerValue < 0 || playerValue > 2) {
		Display(scene, "Please re-enter...");
		return;
	}
	Display(scene, RSP(temp, "player", playerValue));

	//computer
	int computerValue = RandomValue();
	memset(temp, '\0', strlen(temp));
	Display(scene, RSP(temp, "computer", computerValue));

	//game
	Display(scene, RspValueCompare3((playerValue - computerValue + 3) % 3));
}

bool Gameend(char * scene, int& playerValue)
{
	// game over & game clear
	if (playerValue == -1) {
		Display(scene, ("Stop playing RSP Game!"));
		return true;
	}
	return false;
}


int RandomValue()
{
	return rand() % 3;
}

const char * RSP(char * temp, const char * name, int value)
{
	const char* rsp[3] = { "Rock", "Scissors", "Paper" };
	strncpy(temp, name, strlen(name));
	strncat(temp, " is ", 4);
	strncat(temp, rsp[value], strlen(rsp[value]));
	strncat(temp, ".", 2);
	return const_cast<const char*>(temp);
}

const char* RspValueCompare3(int value)
{
	switch (value)
	{
	case 0:
		return "The player and the computer is the same.";
	case 1:
		return "Computer Win!!";
	case 2:
		return "Player Win!!";
	}
}