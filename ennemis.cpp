#include "ennemis.h"

Ennemi::Ennemi(int vie, int v, int d, int x, int y, int t) :vie(vie), vitesse(v), direction(d), x(x), y(y), type(t) {}

int Ennemi::getType() {
	return type;
}

Vector2f Ennemi::getPosition() {
	return Vector2f(x, y);
}

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

void Ennemi::setPosition(Vector2f pos) {
	position = pos;
}

void Ennemi::draw(RenderWindow& window) {
	window.draw(ennemi_s);
}

void Ennemi::update(float deltaTime) {
	ennemi_s.setPosition(x, y);
}