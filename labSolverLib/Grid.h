/**
* @file Grid.h
* @brief Ce fichier contient la définition de la classe Grid qui représente une grille de jeu.
* Il gère les opérations liées à la grille telles que l'affichage, la vérification de la présence de murs ou encore l'accès au joueur.
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
    char wallChar; // Caractère représentant les murs dans le fichier de données
    char emptyChar; // Caractère représentant les cases vides dans le fichier de données

    Player player;

    size_t width; // Largeur de la grille
    size_t height; // Hauteur de la grille

public:
    /**
    * @brief Constructeur de la classe Grid
    * @param file fichier contenant les données de la grille
    * @param wallChar caractère représentant les murs dans le fichier de données
    * @param emptyChar caractère représentant les cases vides dans le fichier de données
    */
    explicit Grid(const std::string& file, char wallChar = '#', char emptyChar = ' ');

    /**
    * @brief Renvoie l'objet Player associé à la grille
    * @return le joueur associé à la grille
    */
    inline Player& getPlayer() {
        return this->player;
    };

    /**
    * @brief Affiche la grille dans la console
    */
    void display() const;

    /**
    * @brief Vérifie si le joueur se trouve sur la sortie de la grille
    * @return vrai si le joueur est sur la sortie, faux sinon
    */
    bool isExit() const;

    /**
    * @brief Vérifie si devant le joueur il n'y a pas de murs
    * @return vrai si il y a un mur devant le joueur, faux sinon
    */
    const bool playerHasNothingInFront();
    /**
    * @brief Vérifie si à gauche du joueur il n'y a pas de murs
    * @return vrai si il y a un mur à gauche du joueur, faux sinon
    */
    const bool playerHasNothingOnLeft();
    /**
    * @brief Vérifie si à droite du joueur il n'y a pas de murs
    * @return vrai si il y a un mur à droite du joueur, faux sinon
    */
    const bool playerHasNothingOnRight();
    /**
    * @brief Calcule les actions relatives possible en fonction de la position du joueur
    * @return liste des actions relatives possibles
    */
    const std::vector<Action> possibleRelativeActions();

    /**
    * @brief Vérifie si une action absolue est possible en fonction de la position du joueur
    * @param action Action absolue à vérifier
    * @return vrai si l'action est possible, faux sinon
    */

    /**
     * @brief Vérifie si une action absolue est possible en fonction de la position du joueur
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

