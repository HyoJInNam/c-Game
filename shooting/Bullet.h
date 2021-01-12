#pragma once

typedef struct Screen Screen;
typedef struct Player Player;
typedef struct ManagementEnemies Enemies;

struct Bullet {
	bool isActive;
	char* left_face;
	char* right_face;

	char* face;
	int face_size;
	float pos;
	float speed;

	Bullet(const Player * player, const char* left_face, const char * right_face, const float speed);
	bool Initialize(const Player * player, const float speed);
	bool Delete();
	void Draw(Screen* screen, Player* player) const;
	void Update(const Screen * screen, Enemies* enemies);

	void Dead();
};