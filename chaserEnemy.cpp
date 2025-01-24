#include "chaserEnemy.h"

ChaserEnemy::ChaserEnemy(int t, int x, int y) : Ennemi(2, 2, x, y, 1){
	if (!ennemi_t.loadFromFile("assets/bat_neutral_down.png")) {
		return;
	}
	ennemi_s.setTexture(ennemi_t);
	ennemi_s.setPosition(x, y);
}

void ChaserEnemy::move_Enemy(int x_player, int y_player){
	Vector2f playerPosition = Vector2f(x_player, y_player);
	Vector2f chaserPos = ennemi_s.getPosition();
	Vector2f distance = playerPosition - chaserPos;
	float magnitude = std::sqrtf(distance.x * distance.x + distance.y * distance.y);

	if (magnitude > 0) {
		distance /= magnitude;
		chaserPos += distance * (float(vitesse));
		x = chaserPos.x;
		y = chaserPos.y;
	}
}

void ChaserEnemy::move_Enemy() {
	
}