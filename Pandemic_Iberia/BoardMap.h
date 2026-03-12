#pragma once

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <utility>

#include "City.h"

class BoardMap
{
private :
	std::map<int, City*> cities_by_id;
	std::map<std::string, int> cities_by_name;
	std::map<std::string, std::vector<int>> cities_by_color;
	std::vector<int> cities_with_harbor;
	std::vector<std::pair<int, int>> rails;

public :
	void add_city(City&);
	void add_rail(int, int);

	const int get_total_rails();
	const int get_total_cities();

	City& find_city(int);
	City& find_city(std::string&);
	const int find_id(std::string&);

	const void list_cities();
	const void list_neighbours(int);

	const bool are_neighbours(int, int);
	const bool are_railed(int, int);
};

