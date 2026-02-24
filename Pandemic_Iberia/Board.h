#pragma once

#include "City.h"
#include <set>

class Board {
	// Attributs et méthodes privées : à vous de décider
public:
	Board();
	bool load(const std::string& file);
	void action_place_three_cubes();
	void action_infect();
	void action_place_rail();
	void action_shortest_path();
	void state();
	void menu();
};


