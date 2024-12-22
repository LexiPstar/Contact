#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//
void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX_DATA )
	{
		printf("通讯录已满，无法添加!\n");
		return;
	}
	//增加
	printf("请输入名字:");
	scanf("%s", pc->data[pc->count].name); 
	printf("请输入年龄:");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别:");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话:");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址:");
	scanf("%s", pc->data[pc->count].address);
	pc->count++;
	printf("增加成功!\n");
}
//增加信息
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-10s\t%-12s\t%-30s\n", 
		"姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-10s\t%-12s\t%-30s\n",  
				pc->data[i].name, 
				pc->data[i].age, 
				pc->data[i].sex, 
				pc->data[i].tele, 
				pc->data[i].address);
	}
}

//删除信息
static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
			return i;
	}
	return -1;
}
void DeleContact(Contact* pc) 
{
	char name[MAX_NAME] = { 0 };
	assert(pc);
	int i = 0;
	if (pc->count == 0)
	{
		printf("通讯录没有数据,不需要删除!\n");
		return;
	}
	printf("请输入需要删除联系人名字:");
	scanf("%s", name);
	//删除
	//1.查找
	int pos = FindByName(pc,name);
	if (pos == -1)
	{
		printf("要删除的联系人不存在!\n");
		return;
	}
	//2.删除
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除联系人成功!\n");
}

//查找信息
void SearchContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入需要查找的联系人名字:");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的联系人不存在!\n");
		return;
	}
	printf("%-20s\t%-5s\t%-10s\t%-12s\t%-30s\n",
		"姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-5d\t%-10s\t%-12s\t%-30s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].address);
}


//修改信息
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入需要修改的联系人名字:");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的联系人不存在!\n");
		return;
	}
	printf("请输入名字:");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄:");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别:");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话:");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址:");
	scanf("%s", pc->data[pos].address);
	printf("修改成功!\n");
	printf("%-20s\t%-5s\t%-10s\t%-12s\t%-30s\n",
		"姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-5d\t%-10s\t%-12s\t%-30s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].address);
}

//排序数据
//按名字字符大小排序
int cmp_peo_byname(const void* n1, const void* n2)
{
	return strcmp(((PeoInfo*)n1)->name, ((PeoInfo*)n2)->name);
}
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(pc->data[0]), cmp_peo_byname);
	printf("排序成功!\n");
}