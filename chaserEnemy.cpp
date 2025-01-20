#include "chaserEnemy.h"

ChaserEnemy::ChaserEnemy(int d, int x, int y) : Ennemi(2, 2, d, x, y, 1){
	if (!ennemi_t.loadFromFile("assets/bat_neutral_down.png")) {
		return;
	}
	ennemi_s.setTexture(ennemi_t);
	ennemi_s.setPosition(x, y);
}

void ChaserEnemy::move_Enemy(int x_player, int y_player) {
	Vector2f d = Vector2f(x_player, y_player) - getPosition();
	float distance = hypot(d.x, d.y);
	if (distance > 1) {
		d = d / distance;
		setPosition(d * 3.f);
	}
	ennemi_s.setPosition(getPosition());
}

void ChaserEnemy::move_Enemy() {

}