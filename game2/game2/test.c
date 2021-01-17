#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void game()
{
	char mine[ROWS][COLS] ;
	char show[ROWS][COLS];
	//初始化
	InitBoard(mine, ROWS, COLS,'0');
	printf("\n");
	InitBoard(show, ROWS, COLS, '*');
	//打印地图
	//display(mine, ROW, COL);
	display(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL, 10);
	//扫雷
	FindMine(mine, show, ROW, COL);
}

void menu(){
	printf("---------------------\n");
	printf("---1.play---0.exit---\n");
}
int main(void)
{
	int option;
	srand((unsigned int)time(NULL));
	do
	{	
		menu();
		printf("请选择：1 或 0:>");
		scanf("%d", &option);
		switch (option)
		{
			case 1:game(); break;
			case 0:printf("退出游戏\n"); break;
			default:printf("输入有误，请重新输入\n"); break;
		}
	} while (option);
	return 0;
}