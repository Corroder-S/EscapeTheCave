#include "key.h"

Key::Key(int x, int y) : Item(x, y, 2) {
	if (!item_t.loadFromFile("assets/key.png")) return;
	item_s.setTexture(item_t);
}