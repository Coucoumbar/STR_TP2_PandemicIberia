#pragma once

#include "City.h"
#include <set>
#include <vector>
#include <map>
#include <string>

#include "BoardMap.h"

class Board {
private :
	// Attributs et méthodes privées : à vous de décider
	BoardMap map;
	int outbreaks;

	int city_selection();
	int city_selection(int);
	void add_cubes(int, int);
	void add_cubes(int, std::string&);
	void outbreak(int);
public:
	Board();
	bool load(const std::string& file);
	void place_three_cubes();
	void infect_city();
	void place_rail();
	void shortest_path();
	void state();
	void menu();
};


