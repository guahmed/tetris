#include "Form_Type_L_inversed.h"



Form_Type_L_inversed::Form_Type_L_inversed()
{
	Matrix[0][0] = 0;
	Matrix[0][1] = 0;
	Matrix[0][2] = 0;

	Matrix[1][0] = 20;
	Matrix[1][1] = 20;
	Matrix[1][2] = 20;

	Matrix[2][0] = 20;
	Matrix[2][1] = 0;
	Matrix[2][2] = 0;

	X_pos = 6;
	Current_line = 0;
}


Form_Type_L_inversed::~Form_Type_L_inversed()
{
}
