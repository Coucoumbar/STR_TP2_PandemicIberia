#include "City.h"

City::City() {}
City::City(const std::string& name, const std::string& color, bool harbor) : name(name), color(color), harbor(harbor) {}

int City::total_cubes() const {
	int cpt = 0;

	for (auto values : cubes)
	{
		cpt += values.second;
	}

	return cpt;
}

int City::total_cubes_of(const std::string& color) const {
	return cubes.at(color);
}

void City::display() {
	std::cout << name << ";" << color << ";" << harbor << std::endl;
}