#include "Board.h"
#include "Parser.h"

Board::Board() {}

bool Board::load(const std::string& file) {
	Parser parser{ file, cities, filtered_cities };

	return parser.process();
}

//std::string Board::list_cities() {
//	for (size_t i = 0; i < length; i++)
//	{
//
//	}
//}

void Board::place_three_cubes() {

}

void Board::infect_city() {

}

void Board::place_rail() {

}

void Board::shortest_path() {

}

void Board::state() {

}

void Board::menu() {
	 while (true) {
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
