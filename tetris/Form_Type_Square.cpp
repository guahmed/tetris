#include "Form_Type_Square.h"
#include <conio.h>


Form_Type_Square::Form_Type_Square()
{
	Matrix[0][0] = 0;
	Matrix[0][1] = 0;
	Matrix[0][2] = 0;

	Matrix[1][0] = 0;
	Matrix[1][1] = 20;
	Matrix[1][2] = 20;

	Matrix[2][0] = 0;
	Matrix[2][1] = 20;
	Matrix[2][2] = 20;

	X_pos = 6;
	Current_line = 0;
}


Form_Type_Square::~Form_Type_Square()
{

}

void Form_Type_Square::Move_Right() {
	if (X_pos <= 5) {

		X_pos++;
	}
}

void Form_Type_Square::Move_Left() {
	if (X_pos > -6) {

		X_pos++;
	}
}




