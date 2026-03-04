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

	std::map<std::string, City>& target;
	std::map<std::string, std::vector<std::string&>>& filter;
	
public :
	Parser(const std::string&, std::map<std::string, City>&, std::map<std::string, std::vector<std::string&>>&);

	bool process();

	int parse_cities();
	const bool find_cities();

	int parse_links();

	std::vector<std::string> split_line(std::string&, char);
};

