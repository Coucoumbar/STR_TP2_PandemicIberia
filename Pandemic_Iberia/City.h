#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

class City 
{
public:
	std::string name;
	std::string color;
	bool harbor;
	std::map<std::string, int> cubes;
	std::vector<std::string> neighbours;

	City();
	City(const std::string& name, const std::string& color, bool harbor);

	int total_cubes() const;
	int total_cubes_of(const std::string& color) const;

	//Test
	void display();
};

