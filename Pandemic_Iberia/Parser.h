#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "City.h"
#include "BoardMap.h"

class Parser
{
private :
	const std::string FILE_NAME;
	std::ifstream file;

	BoardMap& target;
	
public :
	Parser(const std::string&, BoardMap&);

	bool process();

	int parse_cities();
	const bool find_cities();

	int parse_links();

	std::vector<std::string> split_line(std::string&, char);
};

