#include "Parser.h"

Parser::Parser(const std::string& file_name) : FILE_NAME(file_name), file({ FILE_NAME }) {}

bool Parser::parse_into(std::map<std::string, City>& cities) {
	int cpt = 0;
	bool success = true;

	std::cout << "Chargement des villes... ";

	try
	{
		cpt = parse_cities(cities);
		std::cout << cpt << " villes chargées!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Erreur lors du chargement des villes : " << e.what() << std::endl;
		success = false;
	}

	std::cout << std::endl << "Chargement des liens... ";

	try
	{
		cpt = parse_links(cities);
		std::cout << cpt << " liens chargées!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Erreur lors du chargement des liens : " << e.what() << std::endl;
		success = false;
	}

	return success;
}

int Parser::parse_cities(std::map<std::string, City>& cities) {
	if (!find_cities()) throw new std::runtime_error("No city found in the file");

	std::string line;
	int cpt = 0;

	while (std::getline(file, line))
	{
		if (line == "LIENS") break;

		std::vector<std::string> values = split_line(line, ';');

		City temp{ values[0], values[1], (values[2] == "0") ? false : true };

		cities[temp.name] = temp;

		cpt++;
	}

	return cpt;
}

const bool Parser::find_cities() {
	std::string line;

	while (std::getline(file, line))
	{
		if (line == "VILLES") return true;
	}

	return false;
}

int Parser::parse_links(std::map<std::string, City>& cities) {
	std::string line;
	int cpt = 0;

	while (std::getline(file, line))
	{
		if (line[0] != '#')
		{
			std::vector<std::string> values = split_line(line, ';');

			cities.at(values[0]).neighbours.push_back(values[1]);
			cities.at(values[1]).neighbours.push_back(values[0]);
			cpt++;
		}
	}

	return cpt;
}

std::vector<std::string> Parser::split_line(std::string& line, char delimiter) {
	std::vector<std::string> content;

	std::string temp_value;

	for (char character : line)
	{
		if (character == ';')
		{
			content.push_back(temp_value);
			temp_value = "";
		}
		else
		{
			temp_value += character;
		}
	}

	if (temp_value != "") content.push_back(temp_value);

	return content;
}