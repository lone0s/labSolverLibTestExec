/**

* @file Heuristic.h
* @brief Fichier décrivant les différentes heuristiques utilisées pour déterminer les actions à effectuer par le joueur.
*/

#pragma once
#include "Action.h"
#include "Grid.h"

#include <stdlib.h>
#include <Windows.h>

/**
 * @class Heuristic
 * @brief Classe de base pour les heuristiques.
 * Cette classe est une classe de base pour les heuristiques.
*/
class Heuristic
{
public:
	/**
	 * @brief Fonction virtuelle pure qui doit être implémentée par les sous-classes pour déterminer les actions à effectuer.
	 * @param grid la grille de jeu.
	 * @return un vecteur d'actions à effectuer.
	 * @see onlyLeft, onlyRight, randomCrossroad, chooseAll, stairs, chooseCrossroad
	*/
	virtual std::vector<Action> getNextAction(Grid& grid) = 0;
};

/**
 * @class onlyLeft
 * @brief Heuristique qui va toujours tout droit et tourne toujours sur sa gauche quand il ne peut pas avancer.
*/
class onlyLeft : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};

/**
 * @class onlyRight
 * @brief Heuristique qui va toujours tout droit et tourne toujours sur sa droite quand il ne peut pas avancer.
*/
class onlyRight : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};

/**
 * @class randomCrossroad
 * @brief Heuristique qui choisit aléatoirement parmi les actions disponibles à une intersection.
*/
class randomCrossroad : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};

/**
 * @class chooseCrossroad
 * @brief Heuristique qui laisse l'utilisateur de choisir chaque action à une intersection.
*/
class chooseCrossroad : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};

/**
 * @class chooseAll
 * @brief Heuristique qui laisse l'utilisateur de choisir chaque action.
*/
class chooseAll : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};

/**
 * @class stairs
 * @brief Heuristique qui va le plus en ligne droite vers la sortie.
*/
class stairs : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};