#pragma once

#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "City.h"

class BoardMap
{
private :
	std::map<int, City*> cities_by_id;
	std::map<std::string, int> cities_by_name;
	std::map<std::string, std::vector<int>> cities_by_color;

public :
	void add_city(City&);

	const int quantity();

	City& find_city(int);
	City& find_city(std::string&);

	void list_cities();
	void list_neighbours();
};

