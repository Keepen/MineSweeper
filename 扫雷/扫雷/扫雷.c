#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define ROW 9
#define COL 9
int MINE_NUM;//���е�����Ŀ���趨
//ɨ�ף�
//1.��Ϸ�˵���
int Menu();
int Menu()
{
	printf("============================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.�˳���Ϸ\n");
	printf("============================\n");
	printf("��ѡ��");
	int choice;
	scanf("%d", &choice);
	return choice;
}
//��ʼ��һ����ͼ
void Init(char map[ROW+2][COL+2])
{
	int i, j;
	//��ʼ����һ��
	for (i = 0, j = 0; j < COL + 2; j++)
	{
		if (i == 0 && j == 0)
			map[i][j] = ' ';
		else if (j > 0 && j < COL + 2)
			map[i][j] = j;
		else
			map[i][j] = ' ';
	}
	//��ʼ��֮���ÿһ��
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
	//��ʼ�����һ��
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

//��ʼ�����׵ĵ�ͼ
//���õ��׵���Ŀ��mine_num
//���õ��ף������������������õ���     *��ʾ����
void Initmine(char minemap[ROW+2][COL+2])
{
	//��ʼ�����׵���Ŀ�������кϷ����жϡ�
	while(1)
	{
		printf("��������׵���Ŀ��");
		scanf("%d", &MINE_NUM);
		if (MINE_NUM > 0 && MINE_NUM <= ROW * COL)
			break;
		else
		{
			printf("������󣡣������������룡\n");
			continue;
		}
	}
	
	int i=0,row,col,j;
	//��ʼ����һ��
	//for (i = 0, j = 0; j < COL + 2; j++)
	//{
	//	if (i == 0 && j == 0)
	//		minemap[i][j] = ' ';
	//	else if (j > 0 && j < COL + 2)
	//		minemap[i][j] = j;
	//	else
	//		minemap[i][j] = ' ';
	//}
	//��ʼ��֮���ÿһ��
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
	//��ʼ�����һ��
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
		//�����������
		row = rand() % ROW + 1;
		col = rand() % COL + 1;
		minemap[row][col] = '*';
		i++;
	}
}
//��ӡ��ͼ��
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


//2.��Ϸ������ҷ���̺���������û�е��ף��ͱ������Χ8��������ߵõ��׵���Ŀ
//��Ϸ�����ı�־��


void Game(char map[ROW + 2][COL + 2],char minemap[ROW + 2][COL + 2])
{
	int n = MINE_NUM;
	while (1)
	{
		int row, col;
		printf("���������꣺");		
		//����ĺϷ����ж�
		while(1)
		{
			scanf("%d %d", &row, &col);
			if ((row >= 1 && row <= ROW) && (col >= 1 && col <= COL))
				break;
			else
			{
				printf("������󣡣���");
				continue;
			}
		}
		
		//�ȵ�����
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
			printf("�������ˣ�����\n");
			break;
		}
		else if ((minemap[row][col] != '*')&&(n!=0))
		{
			//n--;
			//int num=0;//��¼��Χ���׸����ı���
			////�ж���Χ���׵ĸ���
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
		//���������һ�����ǵ��׵Ŀ�
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
			printf("ɨ�׳ɹ�������\n");
			break;
		}
	}
}

int main()
{	
	srand((unsigned)time(NULL));//�������������
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