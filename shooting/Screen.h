#pragma once

struct Screen {
	int size;
	char* scene;

	Screen(int size);
	bool Delete();

	void Clear();
	void Display();
};