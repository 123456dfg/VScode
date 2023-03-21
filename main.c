#include "func.h"
#include "struct.h"
#include"init_golbalvar.h"

int main() {
	setplayername(&player);
	menu();
	system("cls");
	gamehelp();
	while(1) {
		system("cls");
		printBoard(player);
		move(&player,&map);
	}
	return 0;
}
