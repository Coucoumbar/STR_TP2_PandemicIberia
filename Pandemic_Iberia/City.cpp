#include "City.h"

City::City(const std::string& name, const std::string& color, bool harbor) : name(name), color(color), harbor(harbor) {}
City::City() {}

void City::display() {
	std::cout << name << ";" << color << ";" << harbor << std::endl;
}