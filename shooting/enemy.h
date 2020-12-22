#pragma once

typedef struct player Player;

typedef struct enemy {
	bool isActive;
	char* face;
	int face_size;
	float pos;
	float speed;

	enemy(const char* face);
	bool Initialize(const char* face);
	bool Delete();

	void Draw(const Screen* screen, const Player* player);
	void Update(const Screen * screen, const Player* player);
}Enemy;