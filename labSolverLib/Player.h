/**
 * @file Player.h
 * @brief Ce fichier contient la définition de la classe Player qui représente le joueur dans le jeu.
 * Il gère les opérations liées au joueur telles que les déplacements, les rotations, etc.
*/
#pragma once
#include "Action.h"
#include "Orientation.h"
#include "Tracer.h"

/**
 * @class Player
 * @brief Represente le joueur dans le jeu
*/
class Player
{
	int x;
	int y;

	Orientation orientation;

	Tracer tracer;

	/**
	 * @brief Modifie l'orientation du joueur vers la gauche en fonction de l'orientation actuelle
	*/
	void turnLeft();

	/**
	 * @brief Modifie l'orientation du joueur vers la droite en fonction de l'orientation actuelle
	*/
	void turnRight();

	/**
	 * @brief Modifie la position du joueur en fonction de l'orientation actuelle
	*/
	void goForward();

	/**
	 * @brief Modifie l'orientation du joueur vers l'opposé de l'orientation actuelle
	*/
	void turnBack();

	/**
	 * @brief Déplace le joueur d'une case vers le haut
	*/
	void goUp();

	/**
	 * @brief Déplace le joueur d'une case vers la droite
	*/
	void goRight();

	/**
	 * @brief Déplace le joueur d'une case vers le bas
	*/
	void goDown();

	/**
	 * @brief Déplace le joueur d'une case vers la gauche
	*/
	void goLeft();

public:
	/**
	 * @brief Constructeur de la classe Player
	*/
	Player();

	/**
	 * @brief Getter du tracer du joueur
	 * @return Le tracer du joueur
	*/
	Tracer getTracer() const {
		return this->tracer;
	}

	/**
	 * @brief Getter de la position x du joueur
	 * @return La position x du joueur
	*/
	int getX() const;

	/**
	 * @brief Getter de la position y du joueur
	 * @return La position y du joueur
	*/
	int getY() const;

	/**
	 * @brief Getter de l'orientation du joueur
	 * @return L'orientation du joueur
	*/
	int getOrientation() const;

	/**
	 * @brief Getter du caractère représentant le joueur
	 * @return Le caractère représentant le joueur
	*/
	char getChar() const;

	/**
	 * @brief Effectue une action sur le joueur
	 * @param action L'action à effectuer
	*/
	void doAction(Action action);

	/**
	 * @brief Redéfinition de l'opérateur de conversion en size_t
	 * @return La longueur du chemin parcouru par le joueur
	*/
	inline operator size_t() const {
		return this->tracer.getPath().size();
	}

};
