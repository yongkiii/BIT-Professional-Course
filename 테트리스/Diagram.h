#pragma once
#include <stdlib.h>
#include <time.h>
#define MAX_DIAGRAM 7
#define MAX_TURN 7

#define DIAGRAM_WIDTH 4
#define DIAGRAM_HEIGHT 4
#define DW DIAGRAM_WIDTH
#define DH DIAGRAM_HEIGHT
typedef const int (*block)[4];

class Diagram //테트리스 실제 블록들을 설정하는 곳
{
private:
	int dindex; //몇번째 도형
	int turn; // 몇번 턴 했는가

	int x;
	int y;
public:
	Diagram();
	void SetPosition(int x, int y);
	void SetPosition(Diagram*next);
	void Move(int cx, int cy);
	int GetX()const;
	int GetY()const;
	void Turn();
	int GetBNUM()const;
	block GetBlock(bool is_turn=false);
};

