#include "wall.h"

Wall::Wall(int x, int y, int sx, int sy) : x(x), y(y), sizex(sx), sizey(sy) {
	wall_rect.setSize(Vector2f(sizex, sizey));
	wall_rect.setPosition(Vector2f(x, y));
	wall_rect.setFillColor(Color::White);
	if (!wall_t.loadFromFile("assets/wall.png")) {
		return;
	}
	wall_rect.setTexture(&wall_t);
}