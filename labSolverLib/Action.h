/**
* @file Action.h
* @brief D�finit les diff�rentes actions possibles pour une entit�.
* Ce fichier d�finit un enumeration qui repr�sente les diff�rentes actions
* possibles pour une entit�, comme les directions relatives (tourner � gauche,
* tourner � droite, avancer, reculer) et les directions absolues (aller vers le haut,
* aller vers le bas, aller � droite, aller � gauche). Il y a �galement une valeur
* sp�ciale "INVALID" pour repr�senter une action qui n'est pas valide.
* Il y a �galement un surchargeur d'op�rateur pour l'enumeration qui permet de l'afficher sur un flux de sortie.
*/


#pragma once
#include <iostream>

/**
 * @enum Action
 * @brief Enum�ration des actions possibles.
 */
enum class Action {
    /** @brief Tourner � gauche */
    TURN_LEFT,
    /** @brief Tourner � droite */
    TURN_RIGHT,
    /** @brief Avancer */
    GO_FORWARD,
    /** @brief Tourner en arri�re */
    TURN_BACK,

    /** @brief Aller vers le haut */
    GO_UP,
    /** @brief Aller vers le bas */
    GO_DOWN,
    /** @brief Aller � droite */
    GO_RIGHT,
    /** @brief Aller � gauche */
    GO_LEFT,

    /** @brief Action invalide */
    INVALID
};

/**
 * @brief Surcharge de l'op�rateur << pour l'affichage d'une Action.
 * @param out le stream de sortie.
 * @param action l'action � afficher.
 * @return le stream de sortie.
 */
inline std::ostream& operator<<(std::ostream& out, const Action& action) {
    switch (action) {
    case Action::TURN_LEFT:
        out << "Tourner � gauche";
        break;
    case Action::TURN_RIGHT:
        out << "Tourner � droite";
        break;
    case Action::GO_FORWARD:
        out << "Avancer";
        break;
    case Action::TURN_BACK:
        out << "Tourner en arri�re";
        break;
    }
    return out;
}
