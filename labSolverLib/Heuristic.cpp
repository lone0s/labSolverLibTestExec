#include <tuple>
#include "Heuristic.h"

#pragma once

//voir le fichier Heuristic.h pour les détails sur ce que fait chaque heuristique

std::vector<Action> onlyLeft::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;
	if (!grid.playerHasNothingInFront()) {
		nextActions.push_back(Action::TURN_LEFT);
	}
	else {
		nextActions.push_back(Action::GO_FORWARD);
	}
	return nextActions;
}

std::vector<Action> onlyRight::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;
	if (!grid.playerHasNothingInFront()) {
		nextActions.push_back(Action::TURN_RIGHT);
	}
	else {
		nextActions.push_back(Action::GO_FORWARD);
	}
	return nextActions;
}

std::vector<Action> randomCrossroad::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;
	std::vector<Action> actions = grid.possibleRelativeActions();

	if (actions.size() == 1) {
		nextActions.push_back(actions[0]);
	}
	else {
		int random = rand() % actions.size(); // on choisit une action au hasard
		nextActions.push_back(actions[random]);
		if (actions[random] != Action::GO_FORWARD) { // on ajoute l'action GO_FORWARD si l'action choisie n'est pas GO_FORWARD
			nextActions.push_back(Action::GO_FORWARD);
		}
	}
	return nextActions;
}

std::vector<Action> chooseCrossroad::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;
	std::vector<Action> actions = grid.possibleRelativeActions();
	if (actions.size() == 1) { // si il n'y a qu'une seule action possible, on l'ajoute au vecteur nextActions

		nextActions.push_back(actions[0]);
		if (nextActions[0] != Action::GO_FORWARD) { // on ajoute l'action GO_FORWARD si l'action déjà présente n'est pas GO_FORWARD
			nextActions.push_back(Action::GO_FORWARD);
		}
	}
	else {
		std::cout << "Utilisez les flêches du clavier pour vous déplacer" << std::endl;
		Action choice = Action::INVALID;

		while (choice == Action::INVALID) {
			if (GetAsyncKeyState(VK_UP) & 0x8000) {   // touche flêche haut
				choice = Action::GO_UP;
			}
			else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {    // touche flêche gauche
				choice = Action::GO_LEFT;
			}
			else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {   // touche flêche droite
				choice = Action::GO_RIGHT;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {   // touche flêche bas
				choice = Action::GO_DOWN;
			}

			if (grid.checkAbsoluteActions(choice)) { // si l'action choisie est valide, on l'ajoute au vecteur nextActions
				nextActions.push_back(choice);
			}
			else {
				choice = Action::INVALID; // sinon, on réinitialise la variable choice
			}
		};
	}
	return nextActions;
}

std::vector<Action> chooseAll::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;

	std::cout << "Utilisez les flêches du clavier pour vous déplacer" << std::endl;

	Action choice = Action::INVALID;
	while (choice == Action::INVALID) {
		if (GetAsyncKeyState(VK_UP) & 0x8000) {   // touche flêche haut
			choice = Action::GO_UP;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {   // touche flêche gauche
			choice = Action::GO_LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {    // touche flêche droite
			choice = Action::GO_RIGHT;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {   // touche flêche bas
			choice = Action::GO_DOWN;
		}
		if (grid.checkAbsoluteActions(choice)) { // si l'action choisie est valide, on l'ajoute au vecteur nextActions
			nextActions.push_back(choice);
		}
		else {
			choice = Action::INVALID; // sinon, on réinitialise la variable choice
		}
	}

	return nextActions;
}

std::vector<Action> stairs::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;

	std::vector<Action> actions = grid.possibleRelativeActions();

	if (actions.size() == 1) { // si il n'y a qu'une seule action possible, on l'ajoute au vecteur nextActions
		nextActions.push_back(actions[0]);
	}
	else {

		int x = grid.getPlayer().getX();
		int y = grid.getPlayer().getY();

		if (x >= y) { // si le joueur est plus à droite que haut, on priorise les déplacements vers le bas puis la droite

			if (grid.checkAbsoluteActions(Action::GO_DOWN))
				nextActions.push_back(Action::GO_DOWN);
			else if (grid.checkAbsoluteActions(Action::GO_RIGHT))
				nextActions.push_back(Action::GO_RIGHT);
			else if (grid.checkAbsoluteActions(Action::GO_LEFT))
				nextActions.push_back(Action::GO_LEFT);
			else if (grid.checkAbsoluteActions(Action::GO_UP))
				nextActions.push_back(Action::GO_UP);
		}
		else { // sinon, on priorise les déplacements vers la droite puis le bas

			if (grid.checkAbsoluteActions(Action::GO_RIGHT))
				nextActions.push_back(Action::GO_RIGHT);
			else if (grid.checkAbsoluteActions(Action::GO_DOWN))
				nextActions.push_back(Action::GO_DOWN);
			else if (grid.checkAbsoluteActions(Action::GO_LEFT))
				nextActions.push_back(Action::GO_LEFT);
			else if (grid.checkAbsoluteActions(Action::GO_UP))
				nextActions.push_back(Action::GO_UP);
		}
	}
	return nextActions;
}