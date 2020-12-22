
#include "header.h"

int main() {
	Screen screen(80);
	Player player("0-0¦®", 40);
	int enemy_count = 10;
	Enemy* enemy = (Enemy*)malloc(sizeof(Enemy) * enemy_count);
	for (int i = 0; i < enemy_count; i++) {
		enemy[i].Initialize("*-*");
	}

	while (true) {
		screen.Clear();
		player.Input();
		for (int i = 0; i < enemy_count; i++) {
			enemy[i].Update(&screen, &player);
			enemy[i].Draw(&screen, &player);
		}
		player.Draw(&screen);
		screen.Display();
	}

	for (int i = 0; i < enemy_count; i++) {
		enemy[i].Delete();
	}
	player.Delete();
	screen.Delete();
	exit(1);
	return 0;
}