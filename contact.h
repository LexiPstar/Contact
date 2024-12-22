#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

#define MAX_DATA 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDRESS 30

//���͵�����
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
}PeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX_DATA];
	int count;
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������Ϣ
void AddContact(Contact* pc);

//��ʾ����
void ShowContact(const Contact* pc);

//ɾ������
void DeleContact(Contact* pc);

//��������
void SearchContact(Contact* pc);

//�޸�����
void ModifyContact(Contact* pc);

//��������
void SortContact(Contact* pc);