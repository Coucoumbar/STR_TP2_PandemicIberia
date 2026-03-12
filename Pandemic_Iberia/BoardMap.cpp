#include "BoardMap.h"
#include "Utils.h"

void BoardMap::add_city(City& city) {
	int id = cities_by_id.size();
	id++;

	cities_by_color[city.color].push_back(id);
	cities_by_name[city.name] = id;
	cities_by_id[id] = &city;
	if (city.harbor) cities_with_harbor.push_back(id);
}

void BoardMap::add_rail(int first, int second) {
	rails.push_back({first, second});
	std::cout << "  " << find_city(first).name << " <-> " << find_city(second).name;
	std::cout << " (" << rails.size() << "/20)" << std::endl;
}

const int BoardMap::get_total_cities() {
	return cities_by_id.size();
}

const int BoardMap::get_total_rails() {
	return rails.size();
}

City& BoardMap::find_city(int id) {
	return *cities_by_id.at(id);
}

City& BoardMap::find_city(std::string& name) {
	return *cities_by_id.at(cities_by_name.at(name));
}

const int BoardMap::find_id(std::string& name) {
	return cities_by_name.at(name);
}

const void BoardMap::list_cities() {
	for (int index = 0; index < cities_by_color.size(); index++)
	{
		std::string color = Utils::index_to_color(index);
		Utils::text_color(color);

		std::cout << std::endl << Utils::color_to_illness(color) << std::endl;

		for (int id : cities_by_color.at(color))
		{
			City& city = find_city(id);
			std::cout << " - [" << cities_by_name.at(city.name) << "] " << city.name;
			std::cout << (city.harbor ? " [Port] " : " ");
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
		std::cout << (are_railed(target, cities_by_name.at(neighbour.name)) ? " [Rail]" : "");
		std::cout << std::endl;
	}

	Utils::text_reset();
}

const bool BoardMap::are_neighbours(int first, int second) {
	for (std::string neighbour : find_city(first).neighbours)
	{
		if (find_city(second).name == neighbour) return true;
	}

	return false;
}

const bool BoardMap::are_railed(int first, int second) {
	for (std::pair<int, int> rail : rails)
	{
		if ((rail.first == first || rail.first == second) && (rail.second == first || rail.second == second)) return true;
	}

	return false;
}