
#include "header.h"
#include "management.h"

int main() {
	Screen screen(80);
	Player player("0-0¦®", 40);

	int enemy_count = 10;
	Enemy enemy("*-*");
	management_enemy enemies(enemy, 10);

	Bullet bullet(&player, "<", ">");

	while (true) {
		screen.Clear();
		player.Input(&bullet);

		enemies.Update(&screen, &player);
		bullet.Update(&screen);

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