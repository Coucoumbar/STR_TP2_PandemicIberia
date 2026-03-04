#pragma once

#include "City.h"
#include <set>
#include <vector>
#include <map>
#include <string>

class Board {
private :
	// Attributs et méthodes privées : à vous de décider
	std::map<std::string, City> cities;
	std::map<std::string, std::vector<std::string&>> filtered_cities;

	std::string& list_cities();
	std::string& list_neighbours(const std::string&);
	void outbreak(const std::string&);
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


