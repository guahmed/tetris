#include "Form_type_T.h"
#include "Form.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
using namespace std;

Form_type_T::Form_type_T()
{

	Matrix[1][1] = 20;
	Matrix[2][0] = 20;
	Matrix[2][1] = 20;
	Matrix[2][2] = 20;

	Matrix[0][0] = 0;
	Matrix[0][1] = 0;
	Matrix[0][2] = 0;
	Matrix[1][0] = 0;
	Matrix[1][2] = 0;

	X_pos = 6;
	Current_line = 0;
}

Form_type_T::~Form_type_T( )
{


}

/*
**************************obsolete version*****************************
void Form_type_T:: Y_Move(int matrix_map[15][15])
{
	static int i=1;

	char get_char;
	if (_kbhit) {
		get_char = _getch();
		if (get_char == 'q') {
			X_pos--;

			if (X_pos >= -6 && X_pos <= 7) {

				swap(matrix_map[0 + i - 1][7 + X_pos], matrix_map[0 + i - 1][7 + X_pos + 1]);
				swap(matrix_map[1 + i - 1][6 + X_pos], matrix_map[1 + i - 1][6 + X_pos + 1]);

				swap(matrix_map[1 + i - 1][7 + X_pos], matrix_map[1 + i - 1][7 + X_pos + 1]);
				swap(matrix_map[1 + i - 1][8 + X_pos], matrix_map[1 + i - 1][8 + X_pos + 1]);
			}
			
		}

		else if (get_char == 'd') {
			X_pos++;

			if (X_pos >= -6 && X_pos <= 7) {

				swap(matrix_map[1 + i - 1][8 + X_pos], matrix_map[1 + i - 1][8 + X_pos - 1]);
				swap(matrix_map[1 + i - 1][7 + X_pos], matrix_map[1 + i - 1][7 + X_pos - 1]);

				swap(matrix_map[0 + i - 1][7 + X_pos], matrix_map[0 + i - 1][7 + X_pos - 1]);
				swap(matrix_map[1 + i - 1][6 + X_pos], matrix_map[1 + i - 1][6 + X_pos - 1]);

			}
		}

		else if (get_char == 's') {

			for (size_t p =  0; p < 3; p++)
			{
				for (size_t k = 0; k < 3; k++)
				{
					swap(matrix_map[p + i - 1][k + 6 + X_pos], matrix_map[k + 6 + X_pos][8 + X_pos -p]);
				}
			}

		}

	}

	if (Check_next_line(matrix_map, i) && i < 15) {

		swap(matrix_map[1 + i][8+ X_pos], matrix_map[1 + i - 1][8+ X_pos]);
		swap(matrix_map[1 + i][6+ X_pos], matrix_map[1 + i - 1][6+ X_pos]);

		swap(matrix_map[1 + i][7+ X_pos], matrix_map[1 + i - 1][7+ X_pos]);
		swap(matrix_map[0 + i][7+ X_pos], matrix_map[0 + i - 1][7+ X_pos]);
	}

	i++;
	
}
*******************new version************************

bool Form_type_T::Check_next_line(int matrix_map[15][15], int i) {

	if (matrix_map[3 + i][8+X_pos]==0 && matrix_map[3 + i][7+ X_pos]==0 && matrix_map[3 + i][6+ X_pos]==0) {

		return (true);
	}
}
void Form_type_T::Clear_Previous_Raw(int matrix_map[15][15], int i) {

	matrix_map[1 + i][7 + X_pos] = 0;
	matrix_map[2 + i][8 + X_pos] = 0;
	matrix_map[2 + i][7 + X_pos] = 0;
	matrix_map[2 + i][6 + X_pos] = 0;
	matrix_map[0 + i][6 + X_pos] = 0;
	matrix_map[0 + i][7 + X_pos] = 0;
	matrix_map[0 + i][8 + X_pos] = 0;
	matrix_map[1 + i][6 + X_pos] = 0;
	matrix_map[1 + i][8 + X_pos] = 0;

}


void Form_type_T::Rotate() {

	int  matrix_copy[3][3];
	copy(begin(this->Matrix[0]), this->Matrix[0] + 3, matrix_copy[0]);
	copy(begin(this->Matrix[1]), this->Matrix[1] + 3, matrix_copy[1]);
	copy(begin(this->Matrix[2]), this->Matrix[2] + 3, matrix_copy[2]);

	for ( size_t i = 0; i < 3; i++)
	{
		int  matrix_aux[3][3];
		copy(begin(matrix_copy[0]), matrix_copy[0] + 3, matrix_aux[0]);
		copy(begin(matrix_copy[1]), matrix_copy[1] + 3, matrix_aux[1]);
		copy(begin(matrix_copy[2]), matrix_copy[2] + 3, matrix_aux[2]);

		for (size_t j = 0;  j < 3;  j++)
		{
			swap(matrix_aux[i][j], Matrix[j][2 - i]);
		}
	}

}


void Form_type_T::move(int matrix_map[15][15]) {
	static int i = 0;
	char get_char;


	if (_kbhit()) {
		get_char = _getch();
		if (get_char == 's' && i < 14) {
			Clear_Previous_Raw(matrix_map, i);
			this->Rotate();
		}
		else if (get_char == 'q' && i < 14) {
			Clear_Previous_Raw(matrix_map, i);
			this->Move_Left();

		}
		else if (get_char == 'd' && i < 14) {
			Clear_Previous_Raw(matrix_map, i);
			this->Move_Right();
		}
	}
	
	 if (Check_next_line(matrix_map,i), i<14)
	{
		 
		matrix_map[1 + i][7 + X_pos]= Matrix[1][1];
		matrix_map[2 + i][8 + X_pos]= Matrix[2][2];
		matrix_map[2 + i][7 + X_pos]= Matrix[2][1];
		matrix_map[2 + i][6 + X_pos]= Matrix[2][0];

		matrix_map[0 + i][6 + X_pos] = Matrix[0][0];
		matrix_map[0 + i][7 + X_pos] = Matrix[0][1];
		matrix_map[0 + i][8 + X_pos] = Matrix[0][2];
		matrix_map[1 + i][6 + X_pos] = Matrix[1][0];
		matrix_map[1 + i][8 + X_pos] = Matrix[1][2];
		i++;
	}



}
*/