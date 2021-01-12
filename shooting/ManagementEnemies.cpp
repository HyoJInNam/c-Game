
#include "Header.h"
#include "ManagementEnemies.h"

ManagementEnemies::ManagementEnemies(const Enemy* object, int size)
{
	Initialize(object, size);

	objects[0].isActive = true;
	objects[1].isActive = true;
	next = 2;

	delay = (1 / object->speed) * object->face_size * 3;
	delta_time = 0;
}

bool ManagementEnemies::Initialize(const Enemy* object, int size)
{
	max_size = size;
	objects = (Enemy*)malloc(sizeof(Enemy) * max_size);
	for (int i = 0; i < max_size; i++)
	{
		objects[i].Initialize(object->face, object->speed);
	}
	return true;
}

bool ManagementEnemies::Delete()
{
	for (int i = 0; i < max_size; i++)
	{
		objects[i].Delete();
	}
	free(objects);
	return true;
}

void ManagementEnemies::Draw(Screen * screen, Player * player) const
{
	for (int i = 0; i < max_size; i++)
	{
		objects[i].Draw(screen, player);
	}
}

void ManagementEnemies::Update(const Screen * screen, Player * player)
{
	if (delay <= delta_time)
	{
		if (next >= max_size)
		{
			next = 0;
		}
		objects[next++].isActive = true;
		delta_time = 0;
	}

	for (int i = 0; i < max_size; i++)
	{
		objects[i].Update(screen, player);
	}
	delta_time++;
}
