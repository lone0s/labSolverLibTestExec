/**
* @file Grid.h
* @brief Ce fichier contient la d�finition de la classe Grid qui repr�sente une grille de jeu.
* Il g�re les op�rations li�es � la grille telles que l'affichage, la v�rification de la pr�sence de murs ou encore l'acc�s au joueur.
*/

#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream> 

#include "Player.h"

/**
* @enum class Cells
* @brief Different types de cellules dans la grille
*/
enum class Cells {
    EMPTY,
    WALL,
    EXIT
};

/**
* @class Grid
* @brief Represente la grille de jeu
*/
class Grid
{
    std::vector<std::vector<Cells>> labyrinth; // 2D array de Cells
    char wallChar; // Caract�re repr�sentant les murs dans le fichier de donn�es
    char emptyChar; // Caract�re repr�sentant les cases vides dans le fichier de donn�es

    Player player;

    size_t width; // Largeur de la grille
    size_t height; // Hauteur de la grille

public:
    /**
    * @brief Constructeur de la classe Grid
    * @param file fichier contenant les donn�es de la grille
    * @param wallChar caract�re repr�sentant les murs dans le fichier de donn�es
    * @param emptyChar caract�re repr�sentant les cases vides dans le fichier de donn�es
    */
    explicit Grid(const std::string& file, char wallChar = '#', char emptyChar = ' ');

    /**
    * @brief Renvoie l'objet Player associ� � la grille
    * @return le joueur associ� � la grille
    */
    inline Player& getPlayer() {
        return this->player;
    };

    /**
    * @brief Affiche la grille dans la console
    */
    void display() const;

    /**
    * @brief V�rifie si le joueur se trouve sur la sortie de la grille
    * @return vrai si le joueur est sur la sortie, faux sinon
    */
    bool isExit() const;

    /**
    * @brief V�rifie si devant le joueur il n'y a pas de murs
    * @return vrai si il y a un mur devant le joueur, faux sinon
    */
    const bool playerHasNothingInFront();
    /**
    * @brief V�rifie si � gauche du joueur il n'y a pas de murs
    * @return vrai si il y a un mur � gauche du joueur, faux sinon
    */
    const bool playerHasNothingOnLeft();
    /**
    * @brief V�rifie si � droite du joueur il n'y a pas de murs
    * @return vrai si il y a un mur � droite du joueur, faux sinon
    */
    const bool playerHasNothingOnRight();
    /**
    * @brief Calcule les actions relatives possible en fonction de la position du joueur
    * @return liste des actions relatives possibles
    */
    const std::vector<Action> possibleRelativeActions();

    /**
    * @brief V�rifie si une action absolue est possible en fonction de la position du joueur
    * @param action Action absolue � v�rifier
    * @return vrai si l'action est possible, faux sinon
    */

    /**
     * @brief V�rifie si une action absolue est possible en fonction de la position du joueur
    */
    const bool checkAbsoluteActions(Action action);

    /**
     * @brief Affiche le chemin parcouru par le joueur dans la grille
    */
    const void displayPath();

    /**
     * @brief Renvoie la grille du labyrinthe sous forme de matrice de Cells
     * @return la grille du labyrinthe
    */
    std::vector<std::vector<Cells>> getLabyrinth() const;
};

