#pragma once
#ifndef CHASER_H
#define CHASER_H

#include "ennemis.h"

class ChaserEnemy : public Ennemi {
public:
	ChaserEnemy(int t, int x, int y);
	void move_Enemy(int x_player, int y_player);
	void move_Enemy();
};

#endif