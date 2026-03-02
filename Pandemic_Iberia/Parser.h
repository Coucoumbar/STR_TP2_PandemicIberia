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
	std::map<std::string, City> cities;
	
public :
	Parser(const std::string&);

	void parse_into();

	void parse_cities();
	const bool find_cities();

	void parse_links();
	const bool find_links();

	std::vector<std::string> split_line(std::string&, char);
};

