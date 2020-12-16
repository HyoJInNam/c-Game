#pragma once

typedef struct screen {
	int size;
	char* scene;

	screen(int size);
	bool Delete();

	void Clear();
	void Display();
}Screen;