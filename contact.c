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
		printf("ͨѶ¼�������޷����!\n");
		return;
	}
	//����
	printf("����������:");
	scanf("%s", pc->data[pc->count].name); 
	printf("����������:");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�������Ա�:");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰:");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ:");
	scanf("%s", pc->data[pc->count].address);
	pc->count++;
	printf("���ӳɹ�!\n");
}
//������Ϣ
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-10s\t%-12s\t%-30s\n", 
		"����", "����", "�Ա�", "�绰", "��ַ");
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

//ɾ����Ϣ
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
		printf("ͨѶ¼û������,����Ҫɾ��!\n");
		return;
	}
	printf("��������Ҫɾ����ϵ������:");
	scanf("%s", name);
	//ɾ��
	//1.����
	int pos = FindByName(pc,name);
	if (pos == -1)
	{
		printf("Ҫɾ������ϵ�˲�����!\n");
		return;
	}
	//2.ɾ��
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ����ϵ�˳ɹ�!\n");
}

//������Ϣ
void SearchContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("��������Ҫ���ҵ���ϵ������:");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ���ϵ�˲�����!\n");
		return;
	}
	printf("%-20s\t%-5s\t%-10s\t%-12s\t%-30s\n",
		"����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-5d\t%-10s\t%-12s\t%-30s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].address);
}


//�޸���Ϣ
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("��������Ҫ�޸ĵ���ϵ������:");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����!\n");
		return;
	}
	printf("����������:");
	scanf("%s", pc->data[pos].name);
	printf("����������:");
	scanf("%d", &(pc->data[pos].age));
	printf("�������Ա�:");
	scanf("%s", pc->data[pos].sex);
	printf("������绰:");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ:");
	scanf("%s", pc->data[pos].address);
	printf("�޸ĳɹ�!\n");
	printf("%-20s\t%-5s\t%-10s\t%-12s\t%-30s\n",
		"����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-5d\t%-10s\t%-12s\t%-30s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].address);
}

//��������
//�������ַ���С����
int cmp_peo_byname(const void* n1, const void* n2)
{
	return strcmp(((PeoInfo*)n1)->name, ((PeoInfo*)n2)->name);
}
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(pc->data[0]), cmp_peo_byname);
	printf("����ɹ�!\n");
}