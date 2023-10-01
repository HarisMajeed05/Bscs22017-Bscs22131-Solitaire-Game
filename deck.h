#pragma once
#include <vector>
#include<iostream>
#include "pile.h"
#include "card.h"
#include "borrowPile.h"
#include "stockPile.h"
#include "foundationPile.h"
#include "rules.h"
class deck {
private:
	vector<card> cards;
public:
	deck();
	void shuffle();
	void reset();
	vector<pile*> getPiles();
	~deck();
};