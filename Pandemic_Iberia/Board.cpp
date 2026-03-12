#include "Board.h"
#include "Parser.h"
#include "Utils.h"

Board::Board() : outbreaks(0) {}

bool Board::load(const std::string& file) {
	Parser parser{ file, map };

	return parser.process();
}

void Board::add_cubes(int target, int quantity) {
	City& city = map.find_city(target);

	city.cubes[city.color] += quantity;

	if (city.total_cubes() > 3)
	{
		std::cout << "  " << city.name << " est deja à 3 cubes -> ECLOSION!" << std::endl;
		outbreak(target);

		do
		{
			city.cubes[city.color] -= quantity;
		} while (city.total_cubes() > 3);
		
		return;
	}

	std::cout << "  - " << city.name << " +" << quantity << " -> " << city.total_cubes() << " cubes total" << std::endl;
}

void Board::add_cubes(int target, std::string& color) {
	City& city = map.find_city(target);

	city.cubes[color] += 1;

	if (city.total_cubes() > 3)
	{
		std::cout << "  " << city.name << " est deja a 3 cubes -> ECLOSION!" << std::endl;
		outbreak(target);
		city.cubes[color] -= 1;
		return;
	}

	std::cout << "  - " << city.name << " +1 -> " << city.total_cubes() << " cubes total" << std::endl;
}

void Board::outbreak(int center) {
	std::cout << "ECLOSION #" << ++outbreaks << " a " << map.find_city(center).name << std::endl;

	for (std::string target : map.find_city(center).neighbours)
	{
		if (map.find_city(target).total_cubes() < 4) add_cubes(map.find_id(target), map.find_city(center).color);
	}
}

void Board::place_three_cubes() {
	int choice = city_selection();

	if (choice == 0) return;

	add_cubes(choice, 3);
}

void Board::infect_city() {
	int choice = city_selection();

	if (choice == 0) return;

	add_cubes(choice, 1);
}

void Board::place_rail() {
	if (map.get_total_rails() == 20) {
		std::cout << "Nombre de rails maximum atteind!" << std::endl;
		return;
	}

	int first = city_selection();

	if (first == 0) return;

	int second = city_selection(first);

	if (second == 0) return;

	map.add_rail(first, second);
}

void Board::shortest_path() {

}

void Board::state() {
	std::cout << std::endl << "===== ETAT DU PLATEAU =====" << std::endl;
	std::cout << "Eclosions : " << outbreaks << "/8" << std::endl;
	std::cout << "Rails : " << map.get_total_rails() << "/20" << std::endl;
	
	for (int cpt = 1; cpt < map.get_total_cities() + 1; cpt++)
	{
		City& city = map.find_city(cpt);
		
		if (city.total_cubes() > 0)
		{
			Utils::text_color(city.color);
			std::cout << "  " << city.name;
			Utils::text_reset();
			std::cout << " : ";

			for (int i = 0; i < 4; i++)
			{
				if (city.total_cubes_of(Utils::index_to_color(i)) > 0)
				{
					Utils::text_color(Utils::index_to_color(i));
					std::cout << city.total_cubes_of(Utils::index_to_color(i)) << "x" << Utils::color_to_illness(Utils::index_to_color(i)) << " ";
				}
			}

			std::cout << std::endl;
		}
	}

	Utils::text_reset();
}

void Board::menu() {
	 while (true) {
		 if (outbreaks >= 8)
		 {
			 std::cout << std::endl << "8 ECLOSION! -> Partie termine!" << std::endl;
			 state();
			 return;
		 }


		 std::cout << "\n";
		 std::cout << "+======================================+" << std::endl;
		 std::cout << "|        PANDEMIC IBERIA -- MENU       |" << std::endl;
		 std::cout << "+======================================+" << std::endl;
		 std::cout << "| 1. Placer 3 cubes sur une ville      |" << std::endl;
		 std::cout << "| 2. Infecter une ville (+1 cube)      |" << std::endl;
		 std::cout << "| 3. Placer un rail                    |" << std::endl;
		 std::cout << "| 4. Plus court chemin                 |" << std::endl;
		 std::cout << "| 5. Afficher l'etat du plateau        |" << std::endl;
		 std::cout << "| 0. Quitter                           |" << std::endl;
		 std::cout << "+======================================+" << std::endl;
		 std::cout << "> Choix : ";
	
		 int choix;
		 if (!(std::cin >> choix)) {
		 std::cin.clear();
		 std::cin.ignore(INT_MAX, '\n');
		 continue;
		 }
	
		 switch (choix) {
		 case 1: place_three_cubes(); break;
		 case 2: infect_city(); break;
		 case 3: place_rail(); break;
		 case 4: shortest_path(); break;
		 case 5: state(); break;
		 case 0:
			 std::cout << "Au revoir !" << std::endl;
			 return;
		 default:
			 std::cout << "Choix invalide." << std::endl;
		 }
	 }
}

int Board::city_selection() {
	map.list_cities();

	int choice;

	do
	{
		std::cout << std::endl << "> Choix (0 pour annuler) : ";

		if (!(std::cin >> choice) || choice < 0 || choice > 48) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "Choix invalide!" << std::endl;
		}
		else break;
	} 
	while (true);

	return choice;
}

int Board::city_selection(int id) {
	map.list_neighbours(id);

	int choice;

	do
	{
		std::cout << std::endl << "> Choix (0 pour annuler) : ";

		if (!(std::cin >> choice) || choice < 0 || choice > 48) 
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "Choix invalide!" << std::endl;
		}
		else if (choice != 0 && !map.are_neighbours(id, choice))
		{
			std::cout << "Choix invalide!" << std::endl;
		}
		else if (choice != 0 && map.are_railed(id, choice)) 
		{
			std::cout << "Rail déjà existant!" << std::endl;
		}
		else break;
	} 
	while (true);

	return choice;
}
