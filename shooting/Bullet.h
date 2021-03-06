#pragma once

typedef struct Screen Screen;
typedef struct Player Player;
typedef struct ManagementEnemies Enemies;

struct Bullet {
	int face_size;
	char* face;
	char* left_face;
	char* right_face;

	bool isActive;
	float pos;
	float speed;

	Bullet(Player * player, const char* left_face, const char * right_face, const float speed);
	bool Initialize(Player * player, const char * left_face, const char * right_face, const float speed);
	bool Delete();
	void Draw(Screen* screen, Player* player) const;
	void Update(const Screen * screen, const Player * player, Enemies* enemies);

	void Dead();
};