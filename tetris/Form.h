#pragma once
#include <iostream>

class Form
{
	private:
	
		int Matrix[4][4];


	public:

		virtual bool check_position(int x, int y)=0;

		Form();

		~Form();
};

