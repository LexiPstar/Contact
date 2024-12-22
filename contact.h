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

//类型的声明
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

//初始化通讯录
void InitContact(Contact* pc);

//增加信息
void AddContact(Contact* pc);

//显示数据
void ShowContact(const Contact* pc);

//删除数据
void DeleContact(Contact* pc);

//查找数据
void SearchContact(Contact* pc);

//修改数据
void ModifyContact(Contact* pc);

//排序数据
void SortContact(Contact* pc);