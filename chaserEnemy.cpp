#include "chaserEnemy.h"

ChaserEnemy::ChaserEnemy(int d, int x, int y) : Ennemi(2, 2, d, x, y, 1){
	if (!ennemi_t.loadFromFile("assets/bat_neutral_down.png")) {
		return;
	}
	ennemi_s.setTexture(ennemi_t);
	ennemi_s.setPosition(x, y);
}

void ChaserEnemy::move_Enemy(int x_player, int y_player){
	Vector2f playerPosition = Vector2f(x_player, y_player);
	Vector2f chaserPos = ennemi_s.getPosition();
	Vector2f direction = playerPosition - chaserPos;
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (distance > 0) {
		direction /= distance;
		chaserPos += direction * float(vitesse);
		ennemi_s.setPosition(chaserPos);
	}
	std::cout << ennemi_s.getPosition().x << ' ' << ennemi_s.getPosition().y << std::endl;
}

void ChaserEnemy::move_Enemy() {

}