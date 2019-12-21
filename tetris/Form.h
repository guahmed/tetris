#pragma once
#include <iostream>


class Form
{
	protected:
	
		int Matrix[3][3];
		int X;
		int Y;

	public:

		Form();

	   ~Form();


	
		void Rotate();
		void Move(int matrix_map[17][17],int x,int y);
		void Move_Right_Left(int matrix_map[17][17]);
		void Loop(int matrix_map[17][17]);
		

};
	
