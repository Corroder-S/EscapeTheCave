#include "patrollingEnemy.h"


PatrollingEnemy::PatrollingEnemy(int xd, int yd, int xa, int ya, int d, int x, int y) : xd(xd), yd(yd), xa(xa), ya(ya), Ennemi(5, 2, d, x, y, 2){
	if (!ennemi_t.loadFromFile("assets/skeleton_neutral_down.png")) {
		return;
	}
	ennemi_s.setTexture(ennemi_t);
	ennemi_s.setPosition(x, y);
}

void PatrollingEnemy::move_Enemy() {
    int checkint = check.getElapsedTime().asSeconds();

    if (std::abs(x - xa) < vitesse) x = xa;
    else if (x < xa) x += vitesse;
    else if (x > xa) x -= vitesse;

    if (std::abs(y - ya) < vitesse) y = ya;
    else if (y < ya) y += vitesse;
    else if (y > ya) y -= vitesse;


    if (x == xa && y == ya && checkint > 1) {
        check.restart();
        std::swap(xd, xa);
        std::swap(yd, ya);
    }

    ennemi_s.setPosition(x, y);
}


void PatrollingEnemy::move_Enemy(int x_player, int y_player) {

}