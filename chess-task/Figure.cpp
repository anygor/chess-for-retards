#include "Figure.h"

Figure::Figure():x(0), y(0), type(PAWN) {
}

Figure::Figure(int x, int y, FigureType type, FigureColour colour) {
	this->x = x;
	this->y = y;
	this->type = type;
	this->colour = colour;
}

int Figure::getX() {
	return x;
}

int Figure::getY() {
	return y;
}

FigureType Figure::getType() {
	return type;
}

FigureColour Figure::getColour() {
	return colour;
}

bool Figure::attacksKing(int kingX, int kingY) {
	if (this->getType() == ROOK) {
		int line = this->getX();
		int column = this->getY();
		bool attacks = false;
		for (int column = 1; column < 8; column++) {
			if (kingX == line && kingY == column) {
				attacks = true;
				break;
			}
		}
		if (!attacks) {
			for (int line = 0; line < 8; line++) {
				if (kingX == line && kingY == column) {
					attacks = true;
					break;
				}
			}
		}
		if (attacks) {
			std::cout << std::string("The rook at x: " + std::to_string(this->getX()) + ", y: " +
				std::to_string(this->getY()) + " attacks king at x: " + std::to_string(kingX) + ", y:" + std::to_string(kingY) + "\n");
		}
		return attacks;
	} 
	else if (this->getType() == BISHOP) {
		int line = this->getX();
		int column = this->getY();
		bool attacks = false;
		for (int i = line; i <= 8; i++) {
			if (attacks) {
				break;
			}
			for (int j = column; j <= 8; j++) {
				if (i == kingX && j == kingY) {
					attacks = true;
					break;
				}
				else if (i < 8){
					i++;
				}
			}
		}
		for (int i = line; i <= 8; i++) {
			if (attacks) {
				break;
			}
			for (int j = column; j >= 1; j--) {
				if (i == kingX && j == kingY) {
					attacks = true;
					break;
				}
				else if (i < 8) {
					i++;
				}
			}
		}
		for (int i = line; i >= 1; i--) {
			if (attacks) {
				break;
			}
			for (int j = column; j >= 1; j--) {
				if (i == kingX && j == kingY) {
					attacks = true;
					break;
				}
				else if (i > 1) {
					i--;
				}
			}
		}
		for (int i = line; i >= 1; i--) {
			if (attacks) {
				break;
			}
			for (int j = column; j <= 8; j++) {
				if (i == kingX && j == kingY) {
					attacks = true;
					break;
				}
				else if (i > 1) {
					i--;
				}
			}
		}
		if (attacks) {
			std::cout << std::string("The bishop at x: " + std::to_string(this->getX()) + ", y: " +
				std::to_string(this->getY()) + " attacks king at x: " + std::to_string(kingX) + ", y:" + std::to_string(kingY) + "\n");
		}		
		return attacks;
	}
}