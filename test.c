#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stddef.h>
#include "contact.h"

//struct stt
//{
//	int m;
//	double l;
//	char b;
//};
//int main()
//{
//	struct stu s;
//	offsetof(struct stu,m);
//	printf("%d\n", sizeof(struct stu));
//	return 0;
//}
//struct stu
//{
//	char l[10];
//	char c[10];
//	int m;
//};
//void print1(struct stu ss)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", ss.c[i]);	
//	}
//	printf("\n");
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", ss.l[i]);
//	}
//	printf("\n");
//	printf("%d\n", ss.m);
//}
//
//void print2(struct stu* ps)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", ps->c[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", ps->l[i]);
//	}
//	printf("\n");
//	printf("%d\n", ps->m);
//}
//int main()
//{
//	struct stu s = { {1,2,3},{4,5,6},7 };
//	print1(s);
//	print2(&s);
//	return 0;
//}


//struct stu
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//
//int main()
//{
//	struct stu s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//	return 0;
//}

void menu()
{
	printf("******  1.add   (���) *******\n");
	printf("******  2.dele  (ɾ��) *******\n");
	printf("******  3.search(����) *******\n");
	printf("******  4.modify(�޸�) *******\n");
	printf("******  5.show  (��ʾ) *******\n");
	printf("******  6.sort  (����) *******\n");
	printf("******  0.exit  (�˳�) *******\n");
}

int main()
{
	int input = 0;
	Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do 
	{
		printf("\n");
		menu();
		printf("\n");
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DeleContact(&con);
			break;
		case 3:
			SearchContact(&con);
			break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			SortContact(&con);
			break;
		case 0:
			printf("�˳�ͨѶ¼!\n");
			break;
		default:
			printf("ѡ�����!\n");
			break;
		}
	} while (input);
	return 0;
}