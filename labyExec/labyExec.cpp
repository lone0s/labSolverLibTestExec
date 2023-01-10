#include <iostream>
#include <string>
#include <filesystem>
#include "Game.h"


int main(int argc, char* argv[]) {
	std::string fileName;
	bool fileNameIsGiven = false;
	std::string testFilesPath = "../../labyz/";;
	
	if (argc > 2 || argc < 1) {
		std::cout << "Beaucoup trop d'arguments, j'ai pas ete concu pour gerer ca moi.\n";
		return EXIT_FAILURE;
	}
	else if (argc == 2)
	{
		fileName = argv[1];
		fileNameIsGiven = true;
	}
	//else
	//{
	//	std::string testFilesPath = "../labyz/";
	//}
		bool fileLoaded = false;
		Game* game = nullptr;

		std::vector<std::string> heuristicNames{
		"onlyRight",
		"onlyLeft",
		"chooseCrossroad",
		"randomCrossroad",
		"stairsstairs",
		"chooseAll"
		};
		size_t heuristicIndex = 0;
		bool heuristicChosen = false;
		std::string heuristicIndexStr;

		bool forcedDisplay = false;
		bool display = false;

		Heuristic* h = nullptr;


		//Header CLI
		std::cout << "  __  __                                               \n"
			" |  \\/  |                                  _       _   \n"
			" | \\  / |   __ _   ____   ___            _| |_   _| |_ \n"
			" | |\\/| |  / _` | |_  /  / _ \\          |_   _| |_   _|\n"
			" | |  | | | (_| |  / /  |  __/            |_|     |_|  \n"
			" |_|  |_|  \\__,_| /___|  \\___|                         \n"
			"                                ______                 \n"
			"                               |______|                \n";

		std::cout << "    --------------------------------------    \n\n";
		std::cout << "Welcome to the Labyrinth Solver !\n\n";


		//Choix du labyrinte
		if (!fileNameIsGiven) {
			std::cout << "Quel est le nom du fichier que vous souhaitez resoudre ?\n\n ";
			while (!fileLoaded)
			{
				try {
					std::cin >> fileName;
					game = new Game(testFilesPath + fileName);
					fileLoaded = true;

				}
				catch (std::exception& e) {
					std::cout << "\nCouldn't open the file, are you sure you've imported in the TestFiles folder?\n\n";
					std::cout << "Current files in the TestFiles folder:\n";
					try {
						for (const auto& entry : std::filesystem::directory_iterator(testFilesPath))
							std::cout << "    - " << entry.path() << std::endl;
						std::cout << std::endl;
					}
					catch (std::exception& e) {
						std::cout << "Pas pu ouvrir le repertoire de fichiers tests, revoir la variable testFilesPath dans le labyExec.cpp !\n\n";
						break;
						return EXIT_FAILURE;
					}
				}
			}
		}
		else if (fileNameIsGiven) {
			try {
				game = new Game(testFilesPath + fileName);
			}
			catch (std::exception& e) {
				std::cerr << "\nJe n'ai pas pu ouvrir le fichier, etes vous sur d'avoir renseigne le bon nom et d'avoir mis le fichier dans le repertoire TestFiles?\n\n";
				return EXIT_FAILURE;
			}
		}

		//Choix de l'heuristique
		std::cout << "\nVeuillez entrer le numero d'index de l'heuristique voulue :\n";
		size_t cpt = 0;
		for (std::string name : heuristicNames)
		{
			std::cout << "    - " << cpt << " | " << name << std::endl;
			cpt++;
		}
		while (true) {
			try
			{
				std::cin >> heuristicIndexStr;
				heuristicIndex = std::stoi(heuristicIndexStr);
				if (heuristicIndex >= heuristicNames.size() || heuristicIndex < 0)
					throw std::exception();
				break;
			}
			catch (const std::exception&)
			{
				std::cout << "\nHeuristique non reconnue, veuillez reessayer\n";
			}
		}


		//Init de l'heuristique
		switch (heuristicIndex) {
		case 0:
			h = new onlyRight();
			break;
		case 1:
			h = new onlyLeft();
			break;
		case 2:
			h = new chooseCrossroad();
			forcedDisplay = true;
			break;
		case 3:
			h = new randomCrossroad();
			break;
		case 4:
			h = new stairs();
			break;
		case 5:
			h = new chooseAll();
			forcedDisplay = true;
			break;
		default:
			break;
		}

		//Gestion de l'affichage
		if (!h)
			throw std::invalid_argument("Heuristique null, je dois mettre un terme a mon execution :((\n");

		if (!forcedDisplay) {
			while (true) {
				std::cout << "\nVoulez vous afficher l'execution de l'heuristique ? (y/n)\n";
				try {
					char c;
					std::cin >> c;
					c == 'y' ? display = true : c == 'n' ? display = false : throw std::exception();
					break;
				}
				catch (const std::exception& e)
				{
					std::cout << "\nValeur non reconnue, veuillez réessayer (sensible à la casse)\n";
				}
			}
		}
		
		forcedDisplay ? display = forcedDisplay : display;

		try {
			game->play(*h, display);
		}
		catch (std::exception& e)
		{
			std::cerr << "Game broke :// \nshutting down.\n";
		}


		//Deleters for used news
		delete game;
		delete h;
	return 0;
}