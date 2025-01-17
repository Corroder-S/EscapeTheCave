#pragma once
#ifndef CHASER_H
#define CHASER_H

#include "ennemis.h"

class ChaserEnemy : public Ennemi {
public:

	ChaserEnemy(int d, int x, int y);
	void move_Ennemi(int x_player, int y_player);

};

#endif