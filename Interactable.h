#pragma once
#ifndef INTERACTABLE_H
#define INTERACTABLE_H

class Player;

class Interactable {
public:
	virtual void interact(Player& player) = 0;
};

#endif