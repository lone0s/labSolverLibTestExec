#include "Player.h"
Player::Player() : tracer(), orientation(right), x(1), y(1) {} // Initialisation du joueur à la position (1,1)


int Player::getX() const {
	return x;
}

int Player::getY() const {
	return y;
}

int Player::getOrientation() const {
	return orientation;
}


char Player::getChar() const { // Retourne le caractère représentant le joueur en fonction de son orientation
	switch (orientation)
	{
	case up:
		return '^';
		break;
	case right:
		return '>';
		break;
	case down:
		return 'v';
		break;
	case left:
		return '<';
		break;
	default:
		return '?';
		break;
	}
}

void Player::goForward() { // Déplace le joueur d'une case dans la direction de son orientation
	switch (orientation)
	{
	case up:
		y--;
		break;
	case right:
		x++;
		break;
	case down:
		y++;
		break;
	case left:
		x--;
		break;
	default:
		break;
	}
}

void Player::turnLeft() { // Tourne le joueur à gauche
	orientation = Orientation(((orientation + 3) % 4));
}

void Player::turnRight() { // Tourne le joueur à droite
	orientation = Orientation(((orientation + 1) % 4));
}

void Player::turnBack() { // Tourne le joueur de 180°
	orientation = Orientation(((orientation + 2) % 4));
}

void Player::goUp() { // Déplace le joueur d'une case vers le haut
	y--;
	orientation = up;
}

void Player::goRight() { // Déplace le joueur d'une case vers la droite
	x++;
	orientation = right;
}

void Player::goDown() { // Déplace le joueur d'une case vers le bas 
	y++;
	orientation = down;
}

void Player::goLeft() { // Déplace le joueur d'une case vers la gauche
	x--;
	orientation = left;
}


void Player::doAction(Action action) { // Effectue une action

	switch (action)
	{
	case Action::TURN_LEFT:
		this->turnLeft();
		break;
	case Action::TURN_RIGHT:
		this->turnRight();
		break;
	case Action::GO_FORWARD:
		this->goForward();
		break;
	case Action::TURN_BACK:
		this->turnBack();
		break;
	case Action::GO_UP:
		this->goUp();
		break;
	case Action::GO_RIGHT:
		this->goRight();
		break;
	case Action::GO_DOWN:
		this->goDown();
		break;
	case Action::GO_LEFT:
		this->goLeft();
		break;
	default:
		break;
	}

	tracer.add(std::make_tuple(x, y));
}