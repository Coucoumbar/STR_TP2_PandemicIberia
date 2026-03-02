#pragma once

#include "City.h"
#include <set>
#include "Graph.h";

class Board {
private :
	// Attributs et méthodes privées : à vous de décider
public:
	Board();
	bool load(const std::string& file);
	void place_three_cubes();
	void infect();
	void place_rail();
	void shortest_path();
	void state();
	void menu();
};


