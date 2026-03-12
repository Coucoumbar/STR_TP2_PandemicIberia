#include "BoardMap.h"
#include "Utils.h"

void BoardMap::add_city(City& city) {
	int id = cities_by_id.size();
	id++;

	cities_by_color[city.color].push_back(id);
	cities_by_name[city.name] = id;
	cities_by_id[id] = &city;
}

City& BoardMap::find_city(int id) {
	return *cities_by_id.at(id);
}

City& BoardMap::find_city(std::string& name) {
	return *cities_by_id.at(cities_by_name.at(name));
}

const void BoardMap::list_cities() {
	for (int index = 0; index < cities_by_color.size(); index++)
	{
		std::string color = Utils::index_to_color(index);
		Utils::text_color(color);
		Utils::text_bold();

		std::cout << std::endl << Utils::color_to_illness(color) << std::endl;

		for (int id : cities_by_color.at(color))
		{
			City& city = find_city(id);
			std::cout << " - [" << cities_by_name.at(city.name) << "] " << city.name;
			std::cout << (city.harbor ? " (Ville portuaire) " : " ");
			std::cout << "| " << city.total_cubes() << " cubes";
			std::cout << std::endl;
		}
	}

	Utils::text_reset();
}

const void BoardMap::list_neighbours(int target) {
	City& city = find_city(target);

	for (std::string name : city.neighbours)
	{
		City& neighbour = find_city(name);

		Utils::text_color(neighbour.color);

		std::cout << " - [" << cities_by_name.at(neighbour.name) << "] " << neighbour.name;
		std::cout << (neighbour.harbor ? " (Ville portuaire) " : " ");
		std::cout << "| " << neighbour.total_cubes() << " cubes";
		std::cout << std::endl;
	}

	Utils::text_reset();
}