#include "chaserEnemy.h"

ChaserEnemy::ChaserEnemy(int d, int x, int y) : Ennemi(2, 5, d, x, y){
	if (!ennemi_t.loadFromFile("assets/bat_neutral_down.png")) {
		return;
	}
	ennemi_s.setTexture(ennemi_t);
	ennemi_s.setPosition(x, y);
}

void ChaserEnemy::move_Ennemi(int x_player, int y_player) {
	if (x < x_player+10) x++;
	else if (x > x_player) x--;
	if (y < y_player+10) y++;
	else if (y > y_player) y--;
}