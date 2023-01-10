/**
* @file Game.h
* @brief Ce fichier contient la définition de la classe Game qui représente une partie de jeu.
* Il gère les opérations de jeu telles que l'affichage de la grille et le choix des déplacements.
*/

#pragma once
#include "Grid.h"

#include "Heuristic.h"

/**
* @class Game
* @brief Represente une partie de jeu
*/
class Game
{
    Grid grid;
    size_t cpt;
public:

    /**
    * @brief Constructeur de la classe Game
    * @param file fichier contenant les données de la grille de jeu
    */
    Game(const std::string& file);

    /**
    * @brief Affiche la grille courante dans la console
    */
    void display();

    /**
    * @brief Résoud le labyrinth à l'aide de l'heuristique donnée
    * @param heuristic Heuristique à suivre pour résouudre le labyrinth
    * @param displayed Affiche ou non la grille à chaque étape
    */
    void play(Heuristic& heuristic, bool displayed = false);
};
