/**

* @file Heuristic.h
* @brief Fichier d�crivant les diff�rentes heuristiques utilis�es pour d�terminer les actions � effectuer par le joueur.
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
	 * @brief Fonction virtuelle pure qui doit �tre impl�ment�e par les sous-classes pour d�terminer les actions � effectuer.
	 * @param grid la grille de jeu.
	 * @return un vecteur d'actions � effectuer.
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
 * @brief Heuristique qui choisit al�atoirement parmi les actions disponibles � une intersection.
*/
class randomCrossroad : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};

/**
 * @class chooseCrossroad
 * @brief Heuristique qui laisse l'utilisateur de choisir chaque action � une intersection.
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