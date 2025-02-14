#pragma once
#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include "player.h"

class Interactable {
public:
	virtual void interact(Player& player) = 0;
};

#endif