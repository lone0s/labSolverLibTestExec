/**
 * @file Tracer.h
 * @brief Ce fichier contient la définition de la classe Tracer qui représente le chemin parcouru par le joueur.
 * Elle permet de stocker les positions du joueur à chaque déplacement.
 * Elle permet aussi de récupérer le chemin parcouru par le joueur.
 * Elle est utilisée pour l'affichage du chemin parcouru par le joueur dans la console.
*/
#pragma once
#include <vector>
#include <tuple>
#include <iostream>
#include "Orientation.h"

/**
 * @class Tracer
 * @brief Represente le chemin parcouru par le joueur
*/
class Tracer
{

	std::vector<std::tuple<int, int>> path;

public:
	/**
	 * @brief Constructeur de la classe Tracer
	*/
	Tracer() {
		path.push_back(std::make_tuple(1, 1)); // Initialisation du joueur à la position (1,1)
	};

	/**
	 * @brief Ajoute une position au chemin parcouru par le joueur
	 * @param pos Position à ajouter au chemin
	*/
	inline void add(const std::tuple<int, int> pos) {
		this->path.push_back(pos);
	};

	/**
	 * @brief Getter du chemin parcouru par le joueur
	 * @return Le chemin parcouru par le joueur, sous forme d'un vecteur de tuples (x,y)
	*/
	inline std::vector<std::tuple<int, int>> getPath() const {
		return this->path;
	};

};

