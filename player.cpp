#include "player.h"

Player::Player(int vie, int v, int d, int x, int y) : vie(vie), vitesse(v), direction(d), x(x), y(y) {
	if (!player_t.loadFromFile("assets/player_neutral_up.png")) {
		return;
	}
	player_s.setTexture(player_t);
	player_s.setPosition(x, y);
	player_s.scale(2, 2);
}

int Player::getVie() {
	return vie;
}
int Player::getVitesse() {
	return vitesse;
}
int Player::getDirection() {
	return direction;
}
int Player::getX() {
	return x;
}
int Player::getY() {
	return y;
}

int Player::getKeyCount() {
	return keycount;
}

bool Player::getSpeedUp() {
	return speedup;
}

Sprite* Player::getSprite() {
	return &player_s;
}

void Player::setSprite(Sprite sprite) {
	player_s = sprite;
}

void Player::setVie(int nvie) {
	vie = nvie;
}

void Player::setKeyCount(int nb) {
	keycount = nb;
}

void Player::setVitesse(int nb) {
	vitesse = nb;
}

void Player::setSpeedUp(bool b) {
	speedup = b;
}

void Player::draw(RenderWindow& window) {
	window.draw(player_s);
}

void Player::update(float deltaTime) {
	movePlayer();
	player_s.setPosition(x, y);
}

void Player::movePlayer() {
	if (Keyboard::isKeyPressed(Keyboard::Up) && y>0){
		y -= vitesse;
		direction = 1;
		if (!player_t.loadFromFile("assets/player_neutral_up.png")) {
			return;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) && x<555) {
		x += vitesse;
		direction = 2;
		if (!player_t.loadFromFile("assets/player_neutral_right.png")) {
			return;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) && y<830) {
		y+= vitesse;
		direction = 3;
		if (!player_t.loadFromFile("assets/player_neutral_down.png")) {
			return;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left)&& x>0) {
		x -= vitesse;
		direction = 4;
		if (!player_t.loadFromFile("assets/player_neutral_left.png")) {
			return;
		}
	}
}

