#include<iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include"Form.h"
#include "Form_type_T.h"
#include "Form_Type_I.h"
#include "Form_Type_Square.h"
#include "Form_Type_L.h"
#include "Form_Type_N.h"
#include "Form_Type_N_inversed.h"
#include "Form_Type_L_inversed.h"


#define WIDTH 17
#define LENGTH 17
using namespace std;


int matrix[17][17];
int Score;
bool GameOver;


void Setup() {

	GameOver = false;
	Score = 0;
}

void gotoxy(int x,int y) {
	COORD	coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
	
void display_test(int matrix_map[15][15]) {
	for (size_t i = 0; i < 15; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			cout << matrix_map[i][j] << " ";
		}
		cout << endl;
	}
}

/*inline void Map(int matrix_map[15][15]) {

	for (size_t y = 0; y < LENGTH; y++)
	{
		cout << "#";
		for (size_t x = 0; x < WIDTH; x++)
		{

			if (x == WIDTH - 1) {

				cout << "#" << endl;
			} 

			else if (matrix[y][x]==20) {

				cout << "*";
			}

			else cout << " ";

		}

		if (y == LENGTH - 1) {

			for (size_t z = 0; z < WIDTH+1 ; z++)
			{
				cout << "#";
			}
		}
	}

	cout << endl;
	cout << endl;

	display_test(matrix_map);
}*/


void Finish_Cycle_Block( ) {
	for (size_t i = 0; i < 17; i++)
	{
		for (size_t j = 0; j < 17; j++)
		{
			if (matrix[i][j] == 20)
			{
				matrix[i][j] = 21;
			}
		}
	}
}

Form* Create_Object() {
	int Rand_Number;
	srand(time(0));
	Rand_Number = rand() % 7;

	switch (Rand_Number) {

	case 0:
		return(new Form_type_T);
	case 1:
		return(new Form_Type_I);
	case 2:
		return(new Form_Type_Square);
	case 3:
		return(new Form_Type_L);
	case 4:
		return(new Form_Type_N);
	case 5:
		return(new Form_Type_N_inversed);
	case 6:
		return(new Form_Type_L_inversed);

	}
}

void Increase_Score(int matrix_map[17][17]){
	int Sum=0;
	int Tab_Of_Zero[15] = { 0 };
	for (size_t i = 0; i < 15; i++)
		{
			Sum += matrix_map[14][i];
		}
	if (Sum == 300) {
		Score += 10;
		copy(begin(Tab_Of_Zero), end(Tab_Of_Zero), matrix_map[14]);
		for (int i = 0; i <14; i++) {

			swap(*(matrix + i), *(matrix + i +1 ));
		}
}

}


int main() {
	
	Form* Current_Form = Create_Object();


		Current_Form->Loop(matrix);


	}
	
		
	




