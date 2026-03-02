#include "Parser.h"

Parser::Parser(const std::string& file_name) : FILE_NAME(file_name), file({ FILE_NAME }) {}

void Parser::parse_into() {
	parse_cities();
	parse_links();

	for (auto t : cities)
	{
		t.second.display();
	}
}

void Parser::parse_cities() {
	if (!find_cities()) throw new std::runtime_error("No city found in the file");

	std::string line;

	while (std::getline(file, line))
	{
		if (line == "LIENS") break;

		std::vector<std::string> values = split_line(line, ';');

		City temp{ values[0], values[1], (values[2] == "0") ? false : true };

		cities[temp.name] = temp;
	}
}

const bool Parser::find_cities() {
	std::string line;

	while (std::getline(file, line))
	{
		if (line == "VILLES") return true;
	}

	return false;
}

void Parser::parse_links() {
	std::string line;

	while (std::getline(file, line))
	{
		if (line[0] != '#')
		{
			std::vector<std::string> values = split_line(line, ';');

			cities.at(values[0]).neighbours.push_back(values[1]);
			cities.at(values[1]).neighbours.push_back(values[0]);
		}
	}
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