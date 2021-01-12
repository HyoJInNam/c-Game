#pragma once

typedef struct ManagementEnemies {
	Enemy* objects;
	int max_size;
	int alived_size;

	int delay;
	int delta_time;
	int next;

	ManagementEnemies(const Enemy* object, int size);
	bool Initialize(const Enemy* object, int size);
	bool Delete();

	void Draw(Screen* screen, Player* player) const;
	void Update(const Screen * screen, Player* player);
}Enemies;