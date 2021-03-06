#pragma once

typedef struct Screen Screen;
typedef struct Bullet Bullet;

struct Player {
	char* face;
	int face_size;

	bool isActive;
	int pos;
	int direct;

	Player(const char* face, int pos);
	bool Delete();

	void Input(Bullet* bullet);
	void Update(const Screen* screen);
	void Draw(Screen* screen) const;

	void Dead();
	void Shoot(Bullet * bullet);
};