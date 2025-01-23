#include "door.h"

Door::Door(int x, int y, int sx, int sy) : x(x), y(y), sizex(sx), sizey(sy) {
	door_rect.setSize(Vector2f(sizex, sizey));
	door_rect.setPosition(Vector2f(x, y));
	door_rect.setFillColor(Color::White);
	if (!door_t.loadFromFile("assets/door.png")) {
		return;
	}
	door_rect.setTexture(&door_t);
}