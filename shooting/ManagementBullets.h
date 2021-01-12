#pragma once

typedef struct Screen Screen;
typedef struct Player Player;
typedef struct Bullet Bullet;
typedef struct ManagementEnemies Enemies;

/*
typedef struct ManagementBullets {
	Bullet* objects;
	int max_size;
	int alived_size;

	int delay;
	int delta_time;
	int next;

	ManagementBullets(const Bullet* object, int size);
	bool Initialize(const Bullet* object, int size);
	bool Delete();

	void Draw(Screen* screen, Player* player) const;
	void Update(const Screen * screen, const Player* player, Enemies* enemies);
}Bullets;
*/