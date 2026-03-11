#include "Utils.h"

const std::string Utils::color_to_illness(std::string color) {
	if (color == "blue") return "Cholera";
	else if (color == "red") return "Typhus";
	else if (color == "black") return "Malaria";
	else if (color == "yellow") return "Fievre jaune";
}

const void Utils::text_color(std::string color) {
	if (color == "blue") std::cout << "\x1b[34m";
	else if (color == "red") std::cout << "\x1b[31m";
	else if (color == "black") std::cout << "\x1b[1;30m";
	else if (color == "yellow") std::cout << "\x1b[33m";
}

const void Utils::text_bold() {
	std::cout << "\033[1m";
}


const void Utils::text_reset() {
	std::cout << "\x1b[0m";
}


const std::string Utils::index_to_color(int index) {
	switch (index)
	{
		case 0: return "blue";
		case 1: return "red";
		case 2: return "black";
		case 3: return "yellow";
	}
}