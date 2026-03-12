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
	std::vector<std::pair<int, int>> rails;

public :
	void add_city(City&);

	const int quantity();

	City& find_city(int);
	City& find_city(std::string&);

	const void list_cities();
	const void list_neighbours(int);
};

