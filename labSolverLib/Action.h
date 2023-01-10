/**
* @file Action.h
* @brief Définit les différentes actions possibles pour une entité.
* Ce fichier définit un enumeration qui représente les différentes actions
* possibles pour une entité, comme les directions relatives (tourner à gauche,
* tourner à droite, avancer, reculer) et les directions absolues (aller vers le haut,
* aller vers le bas, aller à droite, aller à gauche). Il y a également une valeur
* spéciale "INVALID" pour représenter une action qui n'est pas valide.
* Il y a également un surchargeur d'opérateur pour l'enumeration qui permet de l'afficher sur un flux de sortie.
*/


#pragma once
#include <iostream>

/**
 * @enum Action
 * @brief Enumération des actions possibles.
 */
enum class Action {
    /** @brief Tourner à gauche */
    TURN_LEFT,
    /** @brief Tourner à droite */
    TURN_RIGHT,
    /** @brief Avancer */
    GO_FORWARD,
    /** @brief Tourner en arrière */
    TURN_BACK,

    /** @brief Aller vers le haut */
    GO_UP,
    /** @brief Aller vers le bas */
    GO_DOWN,
    /** @brief Aller à droite */
    GO_RIGHT,
    /** @brief Aller à gauche */
    GO_LEFT,

    /** @brief Action invalide */
    INVALID
};

/**
 * @brief Surcharge de l'opérateur << pour l'affichage d'une Action.
 * @param out le stream de sortie.
 * @param action l'action à afficher.
 * @return le stream de sortie.
 */
inline std::ostream& operator<<(std::ostream& out, const Action& action) {
    switch (action) {
    case Action::TURN_LEFT:
        out << "Tourner à gauche";
        break;
    case Action::TURN_RIGHT:
        out << "Tourner à droite";
        break;
    case Action::GO_FORWARD:
        out << "Avancer";
        break;
    case Action::TURN_BACK:
        out << "Tourner en arrière";
        break;
    }
    return out;
}
