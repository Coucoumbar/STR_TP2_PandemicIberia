#include "Board.h"
#include <iostream>
#include <climits>
#include "Parser.h"
#ifdef _WIN32
#include <windows.h>
#endif

int main(int argc, char* argv[]) {
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif
	std::string fichier = "board.txt";
	if (argc > 1) fichier = argv[1];
	Board board;
	if (!board.load(fichier)) return 1;
	board.menu();
	return 0;
}
