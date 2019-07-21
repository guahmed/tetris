#include<iostream>
#include <windows.h>
#include"Form.h"
#include "Form_type_T.h"

#define WIDTH 15
#define LENGTH 15
using namespace std;

int matrix[15][15];

void gotoxy(int x,int y) {
	COORD	coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Map( ) {

	for (size_t y = 0; y < LENGTH; y++)
	{
		cout << "#";
		for (size_t x = 0; x < WIDTH; x++)
		{
			cout << " ";

			if (x == WIDTH - 1) {
				cout << "#" << endl;
			}

		}

		if (y == LENGTH - 1) {

			for (size_t z = 0; z < WIDTH + 2; z++)
			{
				cout << "#";
			}
		}
	}
}


bool test_if_line_empty(int** mat, int line)
{
	for (size_t i = 0; i < 15; i++)
	{
		if (mat[line][i] != 0)
		{
			return(false);
		}
	}
}


int main() {
	

	Map();
		
	



}





/* 
5
[5];	}
*/


