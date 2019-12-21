#include "Form_Type_I.h"



Form_Type_I::Form_Type_I()
{

	Matrix[0][0] = 0;
	Matrix[0][1] = 20;
	Matrix[0][2] = 0;

	Matrix[1][0] = 0;
	Matrix[1][1] = 20;
	Matrix[1][2] = 0;


	Matrix[2][0] = 0;
	Matrix[2][1] = 20;
	Matrix[2][2] = 0;


	X_pos = 6;
	Current_line = 0;
}


Form_Type_I::~Form_Type_I()
{
}

void Form_Type_I::Move_Right() {
	if (X_pos <= 7) {

		X_pos++;
	}
}

void Form_Type_I::Move_Left() {

	if (X_pos > -6) {

		X_pos--;
	}
}