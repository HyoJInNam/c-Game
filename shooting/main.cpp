
#include "header.h"

int main() {
	Screen screen(80);
	Player player("0-0¦®", 70);

	while (true) {
		screen.Clear();
		player.Input();
		player.Draw(&screen);
		screen.Display();
	}
	exit(1);
	return 0;
}