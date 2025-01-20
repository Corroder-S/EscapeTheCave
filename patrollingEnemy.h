#pragma once
#ifndef PATROLLING_H
#define PATROLLING_H

#include "ennemis.h"
#include "ctime"

class PatrollingEnemy : public Ennemi {
public:

	int xd, yd, xa, ya;

	PatrollingEnemy(int xd, int yd, int xa, int ya, int d, int x, int y);
	void move_Enemy();
	void move_Enemy(int x_player, int y_player);
};


#endif 
