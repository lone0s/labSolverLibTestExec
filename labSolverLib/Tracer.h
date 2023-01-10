/**
 * @file Tracer.h
 * @brief Ce fichier contient la d�finition de la classe Tracer qui repr�sente le chemin parcouru par le joueur.
 * Elle permet de stocker les positions du joueur � chaque d�placement.
 * Elle permet aussi de r�cup�rer le chemin parcouru par le joueur.
 * Elle est utilis�e pour l'affichage du chemin parcouru par le joueur dans la console.
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
		path.push_back(std::make_tuple(1, 1)); // Initialisation du joueur � la position (1,1)
	};

	/**
	 * @brief Ajoute une position au chemin parcouru par le joueur
	 * @param pos Position � ajouter au chemin
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

