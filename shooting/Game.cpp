
#include "Header.h"

int main() {
	Screen screen(80);

	Player player("0-0¦®", 40);
	Bullet bullet(&player, "<", ">", 0.7f);

	int enemy_count = 10;
	Enemy enemy("*-*", ">_<", 0.2f);
	Enemies enemies(&enemy, 10);


	while (true)
	{
		screen.Clear();
		player.Input(&bullet);

		enemies.Update(&screen, &player);
		player.Update(&screen);
		bullet.Update(&screen, &enemies);

		enemies.Draw(&screen, &player);
		player.Draw(&screen);
		bullet.Draw(&screen, &player);
		screen.Display();
	}

	enemies.Delete();
	player.Delete();
	bullet.Delete();
	screen.Delete();
	exit(1);
	return 0;
}