
#include "header.h"
#include "management.h"

management_enemy::management_enemy(Enemy object, int size)
{
	Initialize(object, size);

	objects[0].isActive = true;
	objects[1].isActive = true;
	next = 2;

	delay = (1 / object.speed) * object.face_size * 3;
	delta_time = 0;
}

bool management_enemy::Initialize(Enemy object, int size)
{
	max_size = size;
	objects = (Enemy*)malloc(sizeof(Enemy) * max_size);
	for (int i = 0; i < max_size; i++) {
		objects[i].Initialize("*-*");
	}
	return true;
}

bool management_enemy::Delete()
{
	for (int i = 0; i < max_size; i++) {
		objects[i].Delete();
	}
	return true;
}

void management_enemy::Draw(const Screen * screen, const Player * player)
{
	for (int i = 0; i < max_size; i++) {
		objects[i].Draw(screen, player);
	}
}

void management_enemy::Update(const Screen * screen, const Player * player)
{
	if (delay <= delta_time) {
		if (next >= max_size) {
			next = 0;
		}
		objects[next++].isActive = true;
		delta_time = 0;
	}

	for (int i = 0; i < max_size; i++) {
		objects[i].Update(screen, player);
	}
	delta_time++;
}
