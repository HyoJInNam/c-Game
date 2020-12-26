#pragma once

typedef struct player Player;

typedef struct bullet {
	bool isActive;
	char* left_face;
	char* right_face;

	char* face;
	int face_size;
	float pos;
	float speed;

	bullet(const Player * player, const char* left_face, const char * right_face);
	bool Initialize(const Player * player);
	bool Delete();
	void Draw(const Screen* screen, const Player* player);
	void Update(const Screen * screen);

	void Dead();
}Bullet;