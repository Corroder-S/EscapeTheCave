#include "items.h"

Item::Item(int x, int y, int t): x(x), y(y), type(t){}

void Item::interact(Player& player) {
	if (type == 1) {
		player.setVitesse(player.getVitesse() * 1.5);
		player.setSpeedUp(true);
		std::cout << "speed" << std::endl;
	}
	if (type == 2) {
		player.setKeyCount(player.getKeyCount() + 1);
		std::cout << "key" << std::endl;
	}
}

void Item::update(float deltatime) {
	item_s.setPosition(x, y);
}

void Item::draw(RenderWindow& window) {
	window.draw(item_s);
}

Sprite* Item::getSprite() {
	return &item_s;
}

int Item::getType() {
	return type;
}