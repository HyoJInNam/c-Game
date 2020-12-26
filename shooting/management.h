#pragma once

typedef struct enemy Enemy;
typedef struct player Player;

typedef struct management_enemy {
	Enemy* objects;
	int max_size;
	int alived_size;

	int delay;
	int delta_time;
	int next;

	management_enemy(Enemy object, int size);
	bool Initialize(Enemy object, int size);
	bool Delete();

	void Draw(const Screen* screen, const Player* player);
	void Update(const Screen * screen, const Player* player);
}Management_enemy;