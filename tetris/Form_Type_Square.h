#pragma once
#include "Form.h"
class Form_Type_Square :public Form

{
public:

	Form_Type_Square();
	~Form_Type_Square();
	void move(int matrix_map[17][17]);
	void Move_Right();
	void Move_Left();

};
	