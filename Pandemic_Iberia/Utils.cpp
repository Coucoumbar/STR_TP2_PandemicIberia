#include "Utils.h"

const std::string Utils::color_to_illness(std::string color) {
	if (color == "blue") return "Cholera";
	else if (color == "red") return "Typhus";
	else if (color == "black") return "Malaria";
	else if (color == "yellow") return "Fievre jaune";
}

const void Utils::text_color(std::string color) {
	if (color == "blue") std::cout << "\033[34m";
	else if (color == "red") std::cout << "\033[31m";
	else if (color == "black") std::cout << "\033[1;30m";
	else if (color == "yellow") std::cout << "\033[33m";
}

const void Utils::text_reset() {
	std::cout << "\x1b[0m" << "\x1b[1m";
}


const std::string Utils::index_to_color(int index) {
	switch (index)
	{
		case 0: return "blue";
		case 1: return "black";
		case 2: return "red";
		case 3: return "yellow";
	}
}