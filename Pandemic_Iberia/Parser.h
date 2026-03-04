#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "City.h"

class Parser
{
private :
	const std::string FILE_NAME;
	std::ifstream file;
	
public :
	Parser(const std::string&);

	bool parse_into(std::map<std::string, City>&);

	int parse_cities(std::map<std::string, City>&);
	const bool find_cities();

	int parse_links(std::map<std::string, City>&);

	std::vector<std::string> split_line(std::string&, char);
};

