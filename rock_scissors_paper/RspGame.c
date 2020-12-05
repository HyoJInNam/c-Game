#include"header.h"

int RandomValue()
{
	return rand() % 3;
}

const  char * RSP(const char * name, int value)
{
	const char* rsp[3] = { "Rock", "Scissors", "Paper" };
	char str[50] = { };
	strcat(str, name);
	strcat(str, " is ");
	strcat(str, rsp[value]);
	strcat(str, ".\n");
	return const_cast<const char*>(str);
}

const char* RspValueCompare3(int value)
{
	switch (value)
	{
	case 1:
		return "The player and the computer is the same.\n";
	case 2:
		return "Player Win!!\n";
	case 3:
		return "Computer Win!!\n";
	}
}