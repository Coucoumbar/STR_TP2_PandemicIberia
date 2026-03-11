#pragma once

#include <iostream>
#include <string>

class Utils
{
private :
	Utils();
public :
	static const std::string color_to_illness(std::string);
	static const std::string index_to_color(int);
	static const void text_color(std::string);
	static const void text_bold();
	static const void text_reset();
};

