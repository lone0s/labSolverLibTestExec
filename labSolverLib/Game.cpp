#include "Game.h"
#include <iostream>

#include <chrono>
#include <thread>
Game::Game(const std::string& file) : grid(file), cpt(0) {}

void Game::display() {
	grid.display();
}

void Game::play(Heuristic& heuristic, bool displayed) {
	while (!this->grid.isExit()) { // Tant que le joueur n'a pas atteint la sortie

		if (displayed) { // Affichage de la grille
			display();
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}


		++cpt; // Incrémentation du compteur de déplacements
		for (Action action : heuristic.getNextAction(this->grid)) { // On récupère les actions à effectuer à partir de l'heuristique
			grid.getPlayer().doAction(action); 						// On effectue chaque action que l'heuristique nous a donné
		}


		if (cpt > 1000) { // Si le compteur dépasse 1000, on demande à l'utilisateur s'il veut continuer
			std::cout << "Vous semblez être bloqué dans une boucle, voulez vous continuer ? (y/n)" << std::endl;
			char c;
			std::cin >> c;
			if (c == 'n')
				break;
			else
				cpt = 0;
		}

	}

	if (grid.isExit()) { // Si le joueur a atteint la sortie

		if (displayed) {
			display();
		}

		std::cout << "\nLe joueur a atteint la sortie! " << std::endl;

		std::cout << "Nombre de déplacements : " << (size_t)grid.getPlayer() << std::endl;

		std::cout << "\n Chemin emprunté : " << std::endl;
		grid.displayPath(); // Affichage du chemin emprunté

	}
	else
		std::cout << "Le joueur n'a pas atteint la sortie..." << std::endl;

}