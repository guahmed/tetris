#pragma once
class Block
{
public:

	int matrix[4][4];
	int X, Y;
	Block();
	~Block();
	int Get_Not_Empty_line();
	void Move(int matrix_map[16][16],int x,int y);
	void Move_Left(int matrix_map[16][16], int y);
	void Loop(int matrix_map[16][16]);
	void Input_Command(int matrix_map[16][16]);
	void Rotate();
	bool check_last_line(int matrix_map[16][16]);
	bool check_left_clash(int matrix_map[16][16]);
	bool check_right_clash(int matrix_map[16][16]);
	bool Check_Clash(int matrix_map[16][16]);
	bool Check_Clash_Rotation(int matrix_map[16][16]);
	friend void Map (int matrix_map[16][16]);

};

