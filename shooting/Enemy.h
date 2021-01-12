#pragma once

typedef struct Screen Screen;
typedef struct Player Player;

struct Enemy {
	int face_size;
	char* face;
	char* baseFace;
	char* demagedFace;

	bool isActive;
	bool isDemaged;
	float pos;
	float speed;

	int delay;
	int delta_time;

	Enemy(const char* baseFace, const char* demagedFace, const float speed);
	bool Initialize(const char * baseFace, const char* demagedFace, const float speed);
	bool Delete();

	void Draw(Screen* screen, Player* player) const;
	void Update(const Screen * screen, Player* player);
	void Dead();
};