#pragma once
#include <string>
#include <iostream>
#include <math.h>
enum FigureType {
	PAWN, ROOK, BISHOP, KING
};

enum FigureColour {
	WHITE, BLACK
};

class Figure {
protected:
	int x;
	int y;
	FigureType type;
	FigureColour colour;
public:
	Figure();
	Figure(int, int, FigureType, FigureColour);

	bool attacksKing(int kingX, int kingY, Figure whiteFigures[], Figure blackFigures[]);
	bool isBlocked(int x, int y, int kingX, int kingY, Figure whiteFigures[], Figure blackFigures[]);
public:
	int getX();
	int getY();
	FigureType getType();
	FigureColour getColour();
	friend bool operator==(const Figure& left, const Figure& right);
};

bool operator==(const Figure& left, const Figure& right);
