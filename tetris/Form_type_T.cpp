#include "Form_type_T.h"
#include "Form.h"
#include <iostream>
#include <string>
#include "main.cpp"

using namespace std;

Form_type_T::Form_type_T(int **matrix_map)
{
	Matrix[0][2] = 1;
	Matrix[1][1] = 1;
	Matrix[1][2] = 1;
	Matrix[1][3] = 1;

    x_pos = 0;

	matrix_map[0][7] = Matrix[0][2];
	matrix_map[1][7] = Matrix[1][2];
	matrix_map[1][8] = Matrix[1][3];
	matrix_map[1][6] = Matrix[1][1];

}


Form_type_T::~Form_type_T( )
{


}

void Form_type_T:: Y_Move(int **matrix_map)
{

	

}

void Form_type_T::Affect_line_to_line(int** matrix_map , int line ) {
	if (test_if_line_empty(**matrix_map, line))

	 
}

