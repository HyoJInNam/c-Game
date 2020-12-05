#include "header.h"
#include "GameFrame.h"

void Clear(char* scene) {
	memset(scene, '\0', strlen(scene));
	system("cls");
}

void Display(char * scene, const char* str)
{
	Clear(scene);
	strncpy(scene, str, strlen(str));
	printf("%s", scene);
	Sleep(1000);
}


void GameLoop(char* scene, int&  playerValue)
{
	while (true) {
		Display(scene, "Input(a or d)");
		if (_kbhit()) {
			int input = _getch();

			if (input == 27) // ESC
				break;

			if (input == (int)'a')
				Display(scene, "a�� �Է��ߴ�.\0");
			else if (input == (int)'d')
				Display(scene, "d�� �Է��ߴ�.\0");
			else
				Display(scene, "�ٸ��� �Է��ߴ�..\0");
			
		}
	}
	exit(1);
}