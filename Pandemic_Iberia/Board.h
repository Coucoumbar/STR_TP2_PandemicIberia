#pragma once

#include "City.h"
#include <set>
#include <map>
#include <string>

class Board {
private :
	// Attributs et méthodes privées : à vous de décider
	std::map<std::string, City> cities;
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


