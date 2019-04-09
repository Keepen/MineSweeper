#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define ROW 9
#define COL 9
int MINE_NUM;//进行地雷数目的设定
//扫雷：
//1.游戏菜单：
int Menu();
int Menu()
{
	printf("============================\n");
	printf("1.开始游戏\n");
	printf("2.退出游戏\n");
	printf("============================\n");
	printf("请选择：");
	int choice;
	scanf("%d", &choice);
	return choice;
}
//初始化一个地图
void Init(char map[ROW+2][COL+2])
{
	int i, j;
	//初始化第一行
	for (i = 0, j = 0; j < COL + 2; j++)
	{
		if (i == 0 && j == 0)
			map[i][j] = ' ';
		else if (j > 0 && j < COL + 2)
			map[i][j] = j;
		else
			map[i][j] = ' ';
	}
	//初始化之后的每一行
	for (i = 1; i < ROW + 1; i++)
	{
		for (j = 0; j < COL + 2; j++)
		{			
			if (j == 0)
				map[i][j] = i;
			else if (j >= 0 && j < COL + 2)
				map[i][j] = '-';
			else if (j == COL + 2)
				map[i][j] = ' ';
		}
	}
	//初始化最后一行
	for (i = ROW + 2, j = 0; j < COL + 2; j++)
	{
		map[i][j] = ' ';
	}
	//for (i = 1,j=COL+2; i < ROW + 2; i++)
	//{
	//	map[i][j] = ' ';
	//}
	//for (i = ROW + 2, j = 1; j < COL + 2; j++)
	//{
	//	map[i][j] = ' ';
	//}
}

//初始化地雷的地图
//设置地雷的数目：mine_num
//布置地雷：产生随机数，随机布置地雷     *表示地雷
void Initmine(char minemap[ROW+2][COL+2])
{
	//初始化地雷的数目，并进行合法性判断。
	while(1)
	{
		printf("请输入地雷的数目：");
		scanf("%d", &MINE_NUM);
		if (MINE_NUM > 0 && MINE_NUM <= ROW * COL)
			break;
		else
		{
			printf("输入错误！！！请重新输入！\n");
			continue;
		}
	}
	
	int i=0,row,col,j;
	//初始化第一行
	//for (i = 0, j = 0; j < COL + 2; j++)
	//{
	//	if (i == 0 && j == 0)
	//		minemap[i][j] = ' ';
	//	else if (j > 0 && j < COL + 2)
	//		minemap[i][j] = j;
	//	else
	//		minemap[i][j] = ' ';
	//}
	//初始化之后的每一行
	//for (i = 1; i < ROW + 1; i++)
	//{
	//	for (j = 0; j < COL + 2; j++)
	//	{
	//		if (j == 0)
	//			minemap[i][j] = i;
	//		else if (j >= 0 && j < COL + 2)
	//			minemap[i][j] = ' ';
	//		else if (j == COL + 2)
	//			minemap[i][j] = ' ';
	//	}
	//}
	//初始化最后一行
	//for (i = ROW + 2, j = 0; j < COL + 2; j++)
	//{
	//	minemap[i][j] = ' ';
	//}
	
	for (i = 1; i < ROW + 1; i++)
	{
		for ( j = 1; j < COL + 1; j++)
		{
			minemap[i][j] = ' ';
		}
	}
	
	i = 0;
	while (i < MINE_NUM)
	{
		//随机产生地雷
		row = rand() % ROW + 1;
		col = rand() % COL + 1;
		minemap[row][col] = '*';
		i++;
	}
}
//打印地图；
void Showmap(char map[ROW + 2][COL + 2])
{
	printf("\n");
	int i, j;
	printf("   1  2  3  4  5  6  7  8  9\n");
	for (i = 1; i < ROW + 1; i++)
	{
		printf("%d", i);
		for (j = 1; j < COL + 1; j++)
		{
			printf("  %c", map[i][j]);
		}
		printf("\n");
	}
}


//2.游戏规则：玩家翻地毯，如果下面没有地雷，就标出其周围8个格子里边得地雷的数目
//游戏结束的标志：


void Game(char map[ROW + 2][COL + 2],char minemap[ROW + 2][COL + 2])
{
	int n = MINE_NUM;
	while (1)
	{
		int row, col;
		printf("请输入坐标：");		
		//输入的合法性判定
		while(1)
		{
			scanf("%d %d", &row, &col);
			if ((row >= 1 && row <= ROW) && (col >= 1 && col <= COL))
				break;
			else
			{
				printf("输入错误！！！");
				continue;
			}
		}
		
		//踩到地雷
		if (minemap[row][col] == '*')
		{
			for (int i = 1; i < ROW; i++)
			{
				for (int j = 1; j < COL; j++)
				{
					if (minemap[i][j] == '*')
						map[i][j] = '*';
				}
			}
			Showmap(map);
			printf("您踩雷了！！！\n");
			break;
		}
		else if ((minemap[row][col] != '*')&&(n!=0))
		{
			//n--;
			//int num=0;//记录周围地雷个数的变量
			////判断周围地雷的个数
			//int row1, col1;
			//for (row1 = row - 1; row1 <= row + 1; row1++)
			//{
			//	for (col1 = col - 1; row1 <= col + 1; col1++)
			//	{
			//		if (minemap[row1][col1] == '*')
			//			num++;
			//	}
			//}
			//map[row][col] = num;
			map[row][col] = ' ';
			Showmap(map);
			continue;
		}
		//翻开了最后一个不是地雷的空
		else if (n == 0)
		{
			for (int i = 1; i < ROW; i++)
			{
				for (int j = 1; j < COL; j++)
				{
					if (minemap[i][j] == '*')
						map[i][j] = '*';
				}
			}
			Showmap(map);
			printf("扫雷成功！！！\n");
			break;
		}
	}
}

int main()
{	
	srand((unsigned)time(NULL));//产生随机数种子
	int choice = Menu();	
	char map[ROW+2][COL+2],minemap[ROW+2][COL+2];
	Init(map);
	Showmap(map);
	Initmine(minemap);
	Showmap(minemap);
	Game(map, minemap);
	system("pause");
	return 0;
}