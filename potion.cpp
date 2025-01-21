#include "potion.h"

Potion::Potion(int x, int y) : Item(x, y, 1){
	if (!item_t.loadFromFile("assets/potion.png")) return;
	item_s.setTexture(item_t);
}