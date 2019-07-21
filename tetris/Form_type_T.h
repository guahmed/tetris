#pragma once
#include "Form.h"
#include<iostream>

using namespace std;

class Form_type_T:public Form
{
	
	public:
	int Matrix[4][4];
	int x_pos;

	public:
		Form_type_T(int **matrix_map);
		~Form_type_T();


		void Y_Move(int **matrix_map);
		void Affect_line_to_line(int** matrix_map , int line );
		friend bool test_if_line_empty(int** mat, int line);

};

