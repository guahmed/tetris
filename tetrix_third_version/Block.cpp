#include "Block.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <algorithm>

Block::Block()
{
	
}


Block::~Block()
{

}

int Block::Get_Not_Empty_line(){

	for (int i = 3; i >= 0; i--)
	{
		for (int j = 0; j <= 3; j++) {

			if (matrix[i][j] != 0)
				return(i);
		}
	}
}




void Block::Rotate( ) {

	int matrix_aux[4][4];
	int aux;
	std::copy(matrix[0], matrix[0] + 4, matrix_aux[0]);
	std::copy(matrix[1], matrix[1] + 4, matrix_aux[1]);
	std::copy(matrix[2], matrix[2] + 4, matrix_aux[2]);
	std::copy(matrix[3], matrix[3] + 4, matrix_aux[3]);

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			matrix[j][3-i]=matrix_aux[i][j];
		}
	}

}

bool Block::Check_Clash(int matrix_map[16][16])
{
 	
		for (size_t i = 0; i < 4 ; i++)
		{
			for (size_t j = 0; j < 4; j++) {

				if (matrix[i][j] && matrix_map[X + i][Y + j]!=0) {

					return(true);

				}
			}
		}
		return(false);
	

}




void Map(int matrix_map[16][16]) {

	system("cls");

	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 16; j++) {

			std::cout << matrix_map[i][j] << " ";

		}
		std::cout <<std::endl;
	}
}

int prev_x = 0;
int prev_y = 6;

void Block::Move(int matrix_map[16][16],int x,int y) {

	if (x == 0) 
	{
		prev_x = 0;
		prev_y = 6;
	}
	
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{

			matrix_map[i+ prev_x][j+ prev_y] -= matrix[i][j];

		}
	}

		prev_x = x;
		prev_y = y;

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			matrix_map[i + x][j + y] += matrix[i][j];
		}
	}
}
//bool Block::check_left_clash(int matrix_map[16][16]) {
//	if()
//}

void Block::Input_Command(int matrix_map[16][16]) {

	char get_char;

	if (_kbhit()) {

		get_char = _getch();

		switch (get_char) 
		{

		case 'q':
			Move(matrix_map, X, Y--);
			break;

		case 'd':
			Move(matrix_map, X, Y++);
			break;

		case ' ':
			Rotate();
			//Move(matrix_map, X, Y);
			break;
			 
		}
	}

	else if (Check_Clash(matrix_map))
			Move(matrix_map, X++, Y);

}


void Block::Loop(int matrix_map[16][16]) {

	while(X<13)
	{

		Map(matrix_map);

		Input_Command(matrix_map);

		Sleep(500);

	//std::cout<< Get_Not_Empty_line();
	}
	
}

