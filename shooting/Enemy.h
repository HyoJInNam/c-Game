#pragma once

typedef struct Screen Screen;
typedef struct Player Player;

struct Enemy {
	bool isActive;
	char* face;
	int face_size;
	float pos;
	float speed;

	Enemy(const char* face, const float speed);
	bool Initialize(const char * face, const float speed);
	bool Delete();

	void Draw(Screen* screen, Player* player) const;
	void Update(const Screen * screen, Player* player);
	void Dead();
};