#include "Grid.h"


Grid::Grid(const std::string& file, char wallChar, char emptyChar) : wallChar(wallChar), emptyChar(emptyChar), player() {

	std::ifstream infile(file);

	std::string line;

	if (infile.is_open()) {

		std::vector<Cells> row;

		while (std::getline(infile, line)) {
			// permet de scale le fichier de données pour passer de la représentation rectangulaire à la représentation carrée
			// pour n'avoir que des couloirs d'un caractère de largeur
			int cpt = 1;
			for (int i = 0; i < line.length(); i++) {
				++cpt;
				if (cpt % 3 != 0) {
					if (line[i] == emptyChar)
						row.push_back(Cells::EMPTY);
					else if (line[i] == wallChar)
						row.push_back(Cells::WALL);
					else { // si le caractère n'est pas un mur ou une case vide, on lève une exception
						throw std::exception();
					}
				}
			}
			labyrinth.push_back(row);
			row.clear();
		}
		infile.close();

		width = labyrinth[0].size();
		height = labyrinth.size();


		labyrinth[height - 2][width - 2] = Cells::EXIT; // on place la sortie 

		// on ajout des murs pour que le joueur ne puisse pas sortir de la grille
		// dans le coin supérieur gauche
		labyrinth[0][0] = Cells::WALL;
		labyrinth[0][1] = Cells::WALL;
		labyrinth[0][2] = Cells::WALL;
		labyrinth[1][0] = Cells::WALL;
	}
	else { // si le fichier n'est pas ouvert, on lève une exception
		throw std::exception();
	}

}

void Grid::display() const { // affiche la grille dans la console

	// L'utilisation d'un stringstream permet d'éviter de faire pleins d'appels à std::cout
	// ce qui évite des clignotements dans la console
	std::stringstream ss;
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < labyrinth[y].size(); ++x) {
			if (this->player.getX() == x && this->player.getY() == y) { // si la case est occupée par le joueur, on ajoute son caractère
				ss << this->player.getChar();
			}
			else if (labyrinth[y][x] == Cells::WALL) { // si la case est un mur, on ajoute le caractère du mur
				ss << wallChar;
			}
			else if (labyrinth[y][x] == Cells::EXIT) { // si la case est la sortie, on ajoute le caractère de la sortie
				ss << '@';
			}
			else { // sinon, on ajoute le caractère vide
				ss << emptyChar;
			}
		}
		ss << std::endl;
	}
	std::cout << ss.str(); // on affiche toute la grille d'un coup

}


bool Grid::isExit() const { // vérifie si le joueur est sur la sortie
	return labyrinth[this->player.getY()][this->player.getX()] == Cells::EXIT;
}


std::vector<std::vector<Cells>> Grid::getLabyrinth() const { // retourne le labyrinthe
	return labyrinth;
}

const bool Grid::playerHasNothingInFront() { // vérifie si le joueur a un mur devant lui
	std::vector<std::vector<Cells>> laby = getLabyrinth();
	const Player player = getPlayer();;
	int x = getPlayer().getX();
	int y = getPlayer().getY();

	switch (player.getOrientation())
	{
	case up:
		return laby[y - 1][x] != Cells::WALL;
		break;
	case right:
		return laby[y][x + 1] != Cells::WALL;
		break;
	case down:
		return laby[y + 1][x] != Cells::WALL;
		break;
	case left:
		return laby[y][x - 1] != Cells::WALL;
		break;
	default:
		return false;
		break;
	}
}

const bool Grid::playerHasNothingOnLeft() { // vérifie si le joueur a un mur à sa gauche
	std::vector<std::vector<Cells>> laby = getLabyrinth();
	const Player player = getPlayer();;
	const int x = getPlayer().getX();
	const int y = getPlayer().getY();

	switch (player.getOrientation()) //la vérfication dépend de l'orientation du joueur
	{
	case up:
		return laby[y][x - 1] != Cells::WALL;
		break;
	case right:
		return laby[y - 1][x] != Cells::WALL;
		break;
	case down:
		return laby[y][x + 1] != Cells::WALL;
		break;
	case left:
		return laby[y + 1][x] != Cells::WALL;
		break;
	default:
		return false;
		break;
	}
}

const bool Grid::playerHasNothingOnRight() { // vérifie si le joueur a un mur à sa droite
	std::vector<std::vector<Cells>> laby = getLabyrinth();
	const Player player = getPlayer();;
	const int x = getPlayer().getX();
	const int y = getPlayer().getY();

	switch (player.getOrientation()) //la vérfication dépend de l'orientation du joueur
	{
	case up:
		return laby[y][x + 1] != Cells::WALL;
		break;
	case right:
		return laby[y + 1][x] != Cells::WALL;
		break;
	case down:
		return laby[y][x - 1] != Cells::WALL;
		break;
	case left:
		return laby[y - 1][x] != Cells::WALL;
		break;
	default:
		return false;
		break;
	}
}

const std::vector<Action> Grid::possibleRelativeActions() { // retourne les actions possibles par rapport à l'orientation du joueur

	std::vector<Action> actions; // on stocke les actions possibles dans un vecteur

	if (playerHasNothingInFront()) {
		actions.push_back(Action::GO_FORWARD);
	}
	if (playerHasNothingOnLeft()) {
		actions.push_back(Action::TURN_LEFT);
	}
	if (playerHasNothingOnRight()) {
		actions.push_back(Action::TURN_RIGHT);
	}
	if (actions.size() == 0) {
		actions.push_back(Action::TURN_BACK);
	}
	return actions;
}

const bool Grid::checkAbsoluteActions(Action action) { // vérifie si une action absolue est possible

	std::vector<Action> actions;

	int x = getPlayer().getX();
	int y = getPlayer().getY();

	switch (action)
	{
	case Action::GO_UP:
		return labyrinth[y - 1][x] != Cells::WALL;
		break;
	case Action::GO_RIGHT:
		return labyrinth[y][x + 1] != Cells::WALL;
		break;
	case Action::GO_DOWN:
		return labyrinth[y + 1][x] != Cells::WALL;
		break;
	case Action::GO_LEFT:
		return labyrinth[y][x - 1] != Cells::WALL;
		break;
	default:
		return false;
		break;
	}
}

const void Grid::displayPath() { // affiche le chemin que le joueur a parcouru pour sortir du labyrinthe
	std::vector<std::tuple<int, int>> path = player.getTracer().getPath();

	std::vector<std::vector<Cells>> laby = getLabyrinth();

	//on affiche le labyrinthe
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < labyrinth[y].size(); ++x) {
			std::tuple<int, int> pos = std::make_tuple(x, y); // on crée un tuple pour la position actuelle

			if (laby[y][x] == Cells::WALL) {
				std::cout << wallChar;
			}
			else if (laby[y][x] == Cells::EXIT) {
				std::cout << '@';
			}
			else if (std::find(path.begin(), path.end(), pos) != path.end()) {  // on vérifie si la position actuelle est dans le chemin
				std::cout << '*'; // si oui, on affiche un *
			}
			else {
				std::cout << emptyChar;
			}
		}
		std::cout << std::endl;
	}


}
