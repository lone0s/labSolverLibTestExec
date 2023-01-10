/**
* @file Game.h
* @brief Ce fichier contient la d�finition de la classe Game qui repr�sente une partie de jeu.
* Il g�re les op�rations de jeu telles que l'affichage de la grille et le choix des d�placements.
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
    * @param file fichier contenant les donn�es de la grille de jeu
    */
    Game(const std::string& file);

    /**
    * @brief Affiche la grille courante dans la console
    */
    void display();

    /**
    * @brief R�soud le labyrinth � l'aide de l'heuristique donn�e
    * @param heuristic Heuristique � suivre pour r�souudre le labyrinth
    * @param displayed Affiche ou non la grille � chaque �tape
    */
    void play(Heuristic& heuristic, bool displayed = false);
};
