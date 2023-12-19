#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAXSIZE 20
#define ERROR 0;
#define OK 1;
typedef int ElemType;
typedef int Status;//״̬�����ֱ�ʾ OK = 1,ERROR = 0
typedef struct Node
{
	ElemType data;//������
	struct Node* Next;//ָ����
} Node;

typedef Node* LinkList;//����ָ�� 

typedef struct Delegate
{
    int No;
    char Name[21];
    int Hour;
    int Number;
	int is_exist;

} Delegate;
int main()
{
	Delegate list[MAXSIZE];//��ֽ
	for (int k = 0; k < MAXSIZE; k++)
	{
		list[k].is_exist = 0;//��ʼ������ί��Ϊ��
	}
    
	int i;
	int n = 0;//���
	int temp;

	int temp_No;
	char temp_Name[21];
	int temp_Hour;
	int temp_Number;
	while (1)
	{
		printf("��ѡ����Ҫִ�еĲ���(0-3)\n");
		printf("\n0:�˳�\n1:��Ӷ���\n2:�޸Ķ���\n3:��ɶ���(ȡ������)\n4:�鿴����\n");
		printf("\n��ѡ��Ҫִ�еĲ����ǣ� \n");
		scanf("%d", &i);
		printf("\n");
		switch (i)
		{
		case 0: exit(i); break;
		case 1:
			printf("������������ʱ�䣨Сʱ0-23��������(����: »»�� 0 1 ��ʾ»»����0��һ��������Է�)\n");
			scanf("%s%d%d", list[n].Name, &list[n].Hour, &list[n].Number);
			if (list[n].Hour >= 24 || list[n].Hour < 0)
			{
				printf("��������\n");
				continue;
			}
			else if (n >= MAXSIZE) { printf("����������������������"); }
			else { list[n].is_exist = 1; list[n].No = n; n++;   continue; }

			break;
		case 2:
			

			printf("��Ҫ�޸ĵĶ������\n ");
			scanf("%d", &temp);
			if (temp < MAXSIZE && temp >= 0 && list[temp].is_exist == 1)
			{
				printf("������������ʱ�䣨Сʱ0-23��������(����: »»�� 0 1 ��ʾ»»����0��һ��������Է�)\n");
				scanf("%s%d%d",&temp_Name, &temp_Hour, &temp_Number);
				if (list[temp].Hour >= 24 || list[temp].Hour < 0)
				{
					printf("��������\n");
					continue;
				}
				else { list[temp].is_exist = 1; 
					strcpy(list[temp].Name, temp_Name); 
					list[temp].Hour = temp_Hour; 
					list[temp].Number = temp_Number; }
				printf("�޸����\n");
				continue;
			}
			else {
				printf("\n\n\t�Ҳ����ö�����˶���Ϣ\n\n\n\n\n");
				continue;
			}
			break;
		case 3:
			printf("��������ɵĶ������:\n");
			scanf("%d\n", temp);
			if (list[temp].is_exist == 1) { list[temp].is_exist = 0; }
			else { printf("�����ڸö���\n"); }
			continue;
			break;
		case 4:
			printf("\n\t______________________________________________________\n");
			for (int k = 0; k < MAXSIZE; k++)
			{
				
				if (list[k].is_exist == 1)
				{
					
					printf("��� : %d\n", list[k].No);
					printf("���� : %s\n", list[k].Name);
					printf("ʱ�䣨Сʱ�� : %d\n", list[k].Hour);
					printf("���� : %d\n", list[k].Number);
					printf("\t______________________________________________________\n");
				}

			}
			continue;
			break;
		default:
			printf("\n\n\t�����������������\n\n\n\n");
			continue;
		}
	}




    system("pause");
    return EXIT_SUCCESS;
}




Status ListInsert(LinkList* L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)
	{
		p = p->Next;
		j++;
	}
	if (!p || j > i) return ERROR;

	s = (LinkList)malloc(sizeof(Node));
	s->data = e;//����ڴ治����s�����ǿ�ָ�룬���IDE��������
	s->Next = p->Next;
	p->Next = s;

	return OK;


}