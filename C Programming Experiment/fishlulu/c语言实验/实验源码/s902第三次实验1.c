#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
void DateCalc(int year, int day,int* is_run,int** dayTab,int *ret1,int* ret2)//�����Ӧ�·�����
{
    int month = 0;
    int day_calc = 0;
    if (year % 4 == 0 && year % 100 != 0)//���������Ļ�
    {
        *is_run = 1;
        dayTab += 1;//ת���������
    }
    //printf("%d\n", **dayTab);
    while (day - **dayTab > 0&&month< 12)
    {
        day -= **dayTab;
        *dayTab += 1;
        month += 1;
    }
    day_calc = day;//���ʣ�µ�����Ϊ��������
    //ָ����ս��
    *ret1 = month;
    *ret2 = day_calc;
}


int main()
{
    //������,����ÿ���µ�����

    int year = 0;
    int day = 0;
    int year_ret, day_ret;
    int is_run = 0,*p1 = &is_run;
    int* ret1 = &year_ret;
    int* ret2 = &day_ret;

    int** dayTab = (int**)malloc(sizeof(int*) * 2);
    for (int i = 0; i < 2; i++)
    {
        dayTab[i] = (int*)malloc(sizeof(int*) * 13);
    }
    int t1[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int t2[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    dayTab[0] = t1;
    dayTab[1] = t2;
   

    printf("��������ݺ͵ڼ���:\n");
    scanf("%d", &year);
    scanf("%d", &day);
    //printf("%d %d", year, day);
    printf("%d��ĵ�%d��,������:\n",year,day);
    DateCalc(year, day, p1,dayTab, ret1, ret2);
    if(*ret1 && *ret2) printf("%d��%d��%d��\n", year, *ret1, *ret2);
    
    printf("�����");
    if (is_run == 1) printf("������\n");
    else printf("��������\n");
    system("pause");
    return EXIT_SUCCESS;
}