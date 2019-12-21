#include "Form.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>


#define LENGTH 17
#define WIDTH 17

using namespace std;


int Prev=0;


Form::Form()
{

}

Form::~Form()
{

}

inline void Map(int matrix_map[17][17]) {


	for (size_t y = 0; y < LENGTH; y++)
	{
		
		for (size_t x = 0; x < WIDTH; x++)
		{
	
    		if (matrix_map[y][x] == 20 ) 
			{
				cout << "#";
			}

			else cout << " ";

		}
		cout << endl;
	}

	cout << endl;
	cout << endl;


	for (size_t a = 0; a < 17; a++)
	{
		for (size_t b = 0; b < 17; b++)
		{
		   cout << matrix_map[a][b] << " ";
		}
		cout << endl;
	}

}




void Form::Rotate() {

	int  matrix_copy[3][3];

	copy(begin(this->Matrix[0]), this->Matrix[0] + 3, matrix_copy[0]);
	copy(begin(this->Matrix[1]), this->Matrix[1] + 3, matrix_copy[1]);
	copy(begin(this->Matrix[2]), this->Matrix[2] + 3, matrix_copy[2]);

	for (size_t i = 0; i < 3; i++)
	{
		int  matrix_aux[3][3];

		copy(begin(matrix_copy[0]), matrix_copy[0] + 3, matrix_aux[0]);
		copy(begin(matrix_copy[1]), matrix_copy[1] + 3, matrix_aux[1]);
		copy(begin(matrix_copy[2]), matrix_copy[2] + 3, matrix_aux[2]);

		for (size_t j = 0; j < 3; j++)
		{
			swap(matrix_aux[i][j], Matrix[j][2 - i]);
		}
	}

}

void Form::Move(int matrix_map[17][17],int x,int y) {

	system("cls");

	Map(matrix_map);
	
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			
			matrix_map[i + x ][j + y + 7] = 0;
		}
	}

	x = X;
	y = ++Y;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (Matrix [i][j])
				matrix_map[i + x][j + y] = Matrix[i][j];
		}
	}

}

void Form::Move_Right_Left(int matrix_map[17][17]) {
	
	char input;

	if (_kbhit()) {

	    input = _getch();

		if (input == 'd') {

			Move(matrix_map,X++,Y);

		}
		else if (input == 'q') {

			Move(matrix_map,X--,Y);

		}
		else if (input == 's') {

			Rotate();
			Move(matrix_map);
		}
		
	}
	else

		Move(matrix_map,X,Y);

}
void Form::Loop(int matrix_map[17][17]) {

	while (Y < 15) {

		//Move(matrix_map);
		Move_Right_Left(matrix_map);
		Sleep(500);
	}

}

