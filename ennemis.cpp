#include "ennemis.h"

Ennemi::Ennemi(int vie, int v, int d, int x, int y) :vie(vie), vitesse(v), direction(d), x(x), y(y) {}

int Ennemi::getVie() {
	return vie;
}
int Ennemi::getVitesse() {
	return vitesse;
}
int Ennemi::getDirection() {
	return direction;
}
int Ennemi::getX() {
	return x;
}
int Ennemi::getY() {
	return y;
}
Sprite* Ennemi::getSprite() {
	return &ennemi_s;
}

void Ennemi::draw(RenderWindow& window) {
	window.draw(ennemi_s);
}

void Ennemi::update(float deltaTime) {
	move_Ennemi();
	ennemi_s.setPosition(x, y);
}