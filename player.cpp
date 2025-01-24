#include "player.h"

Player::Player(int vie, int v, int d, int x, int y) : vie(vie), vitesse(v), direction(d), x(x), y(y) {
	if (!player_t.loadFromFile("assets/player_neutral_up.png")) {
		return;
	}
	player_s.setTexture(player_t);
	player_s.setPosition(x, y);
	player_s.scale(1, 1);
	keycount = 0;
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

void Player::setPosition(int nx, int ny) {
	x = nx;
	y = ny;
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
	int animateint = animate.getElapsedTime().asMilliseconds();

	if (Keyboard::isKeyPressed(Keyboard::Up)){
		y -= vitesse;
		direction = 1;
		if (i1 > 4) i1 = 1;
		if (!player_t.loadFromFile("assets/player_running" + std::to_string(i1)+ "_up.png")) {
			return;
		}
		if (animateint > 200) {
			i1 += 1;
			animate.restart();
		}
	}
	
	else if (Keyboard::isKeyPressed(Keyboard::Right)) {
		x += vitesse;
		direction = 2;
		if (i2 > 4) i2 = 1;
		if (!player_t.loadFromFile("assets/player_running" + std::to_string(i2) + "_right.png")) {
			return;
		}
		if (animateint > 200) {
			i2 += 1;
			animate.restart();
		}
	}
	

	else if (Keyboard::isKeyPressed(Keyboard::Down)) {
		y+= vitesse;
		direction = 3;
		if (i3 > 4) i3 = 1;
		if (!player_t.loadFromFile("assets/player_running" + std::to_string(i3) + "_down.png")) {
			return;
		}
		if (animateint > 200) {
			i3 += 1;
			animate.restart();
		}
	}
	

	else if (Keyboard::isKeyPressed(Keyboard::Left)) {
		x -= vitesse;
		direction = 4;
		if (i4 > 4) i4 = 1;
		if (!player_t.loadFromFile("assets/player_running" + std::to_string(i4) + "_left.png")) {
			return;
		}
		if (animateint > 200) {
			i4 += 1;
			animate.restart();
		}
		
	}


	else if (direction == 1) {
		if (!player_t.loadFromFile("assets/player_neutral_up.png")) {
			return;
		}
	}

	else if (direction == 2) {
		if (!player_t.loadFromFile("assets/player_neutral_right.png")) {
			return;
		}
	}

	else if (direction == 3) {
		if (!player_t.loadFromFile("assets/player_neutral_down.png")) {
			return;
		}
	}

	else if (direction == 4) {
		if (!player_t.loadFromFile("assets/player_neutral_left.png")) {
			return;
		}
	}
}

