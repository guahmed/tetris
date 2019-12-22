#include "Block_Type_T.h"



Block_Type_T::Block_Type_T(int matrix_map[16][16])
{
	matrix_map[0][6]=matrix[0][0] = 0;
	matrix_map[0][7]=matrix[0][1] = 0;
	matrix_map[0][8]=matrix[0][2] = 0;
	matrix_map[0][9]=matrix[0][3] = 0;

	matrix_map[1][6]=matrix[1][0] = 0;
	matrix_map[1][7]=matrix[1][1] = 1;
	matrix_map[1][8]=matrix[1][2] = 0;
	matrix_map[1][9]=matrix[1][3] = 0;

	matrix_map[2][6]=matrix[2][0] = 1;
	matrix_map[2][7]=matrix[2][1] = 1;
	matrix_map[2][8]=matrix[2][2] = 1;
	matrix_map[2][9]=matrix[2][3] = 0;

	matrix_map[3][6]=matrix[3][0] = 0;
	matrix_map[3][7]=matrix[3][1] = 0;
	matrix_map[3][8]=matrix[3][2] = 0;
	matrix_map[3][9]=matrix[3][3] = 0;

	X = 0;
	Y = 6;
}


Block_Type_T::~Block_Type_T()
{
}
