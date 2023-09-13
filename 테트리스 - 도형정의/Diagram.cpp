#include "Diagram.h"


const int block_vals[MAX_DIAGRAM][MAX_TURN][DH][DW] =
{
	{
		{
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0}
		},
		{

			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		},
	    {
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0}
		},
		{

			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		},

	},//0
	{
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{

			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
	
		{	
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{

			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
	},//1
	{
		{
			{0,0,0,0},
			{0,0,1,0},
			{0,1,1,0},
			{0,0,1,0}
		},
	    {
			{0,0,0,0},
			{0,0,1,0},
			{0,1,1,1},
			{0,0,0,0}
		},
		{

			{0,0,0,0},
			{0,0,1,0},
			{0,0,1,1},
			{0,0,1,0}
		},
	
		{

			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,1},
			{0,0,1,0}
		},
	},//2
	{
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,0},
			{0,0,1,1}
		},
		{

			{0,0,0,0},
			{0,0,0,1},
			{0,0,1,1},
			{0,0,1,0}
		},
	    {
			{0,0,0,0},
			{0,0,0,0},
			{0,0,1,1},
			{0,1,1,0}
		},
		{

			{0,0,0,0},
			{0,1,0,0},
			{0,1,1,0},
			{0,0,1,0}
		},
	},//3
	{
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,1,1},
			{0,1,1,0}
		},
		{

			{0,0,0,0},
			{0,1,0,0},
			{0,1,1,0},
			{0,0,1,0}
		},
		{

			{0,0,0,0},
			{0,0,0,0},
			{0,0,1,1},
			{0,1,1,0}
		},
		{

			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
	},//4
	{
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,0,1,0},
			{0,0,1,0}
		},
		{

			{0,0,0,0},
			{0,0,0,1},
			{0,1,1,1},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,1}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,1},
			{0,1,0,0}
		},
	},//5
	{
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,1},
			{0,1,0,0}
		},
		{

			{0,0,0,0},
			{0,1,0,0},
			{0,1,1,1},
			{0,0,0,0}
		},{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,1},
			{0,1,0,0}
		},
		{

			{0,0,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,1,0}
		},
	},//6

};

Diagram::Diagram()
{
	dindex = 0;
	turn = 0;
	x = 0;
	y = 0;
}
void Diagram::SetPosition(int x, int y)
{
	dindex = rand() % MAX_DIAGRAM;
	turn = 0;
	this->x = x;
	this->y = y;
}
void Diagram::SetPosition(Diagram* next)
{
	dindex = next->dindex;
	turn = next->turn;
	x = next->x;
	y = next->y;
}
void Diagram::Move(int cx, int cy)
{
	x += cx;
	y += cy;
}
int Diagram::GetX()const
{
	return x;
}
int Diagram::GetY()const
{
	return y;
}
void Diagram::Turn()
{
	turn = (turn + 1) % MAX_TURN;
}
block Diagram::GetBlock(bool is_turn)
{
	if (is_turn)
	{
		int nturn = (turn + 1) % MAX_TURN;
		return block_vals[dindex][nturn];
	
	}
	return block_vals[dindex][turn];
}

