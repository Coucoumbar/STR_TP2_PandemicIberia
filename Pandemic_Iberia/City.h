#pragma once

#include <string>
#include <vector>
#include <map>

class City 
{
public:
	std::string name;
	std::string color;
	bool port;
	std::map<std::string, int> cubes;
	std::vector<std::string> neighbours;
	City();
	City(const std::string& name, const std::string& color, bool port);
	int total_cubes() const;
	int cubes_of(const std::string& couleur) const;
};

