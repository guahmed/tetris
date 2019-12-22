#include<iostream>
#include<vector>
#include "Block.h"
#include "Block_Type_I.h"
#include "Block_Type_T.h"

using namespace std;

int matrix_map[16][16] = {0};

void Display_matrix(int matrix[4][4]) {

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout<<matrix[i][j];
		}
		cout << endl;
	}

}

bool Check_Game_Over(int matrix_map[16][16]) {

	for (size_t i = 0; i < 16; i++)
	{
		if (matrix_map[0][i] == 1) {
			return(false);
		}
		else return(true);
	}
}

int main()
{
	bool Game_over = true;

	while (Game_over)
	{

		Block* B = new Block_Type_T(matrix_map);
		B->Loop(matrix_map);

		Game_over = Check_Game_Over(matrix_map);

	}


}