#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int strcmp01(char* p1, char* p2)
{
    int ret = 0;
    while (*p1 != '\0' && *p2 != '\0')
    {
        if (*p1 != *p2)
        {
            ret = *p1 - *p2;
            return ret;

        }
        p1++;
        p2++;
    }
    return ret;
}
int main()
{
    char ch1[] = { 0 };
    char ch2[] = { 0 };
    printf("�����������ַ���\n");
    scanf("%s", ch1);
    scanf("%s", ch2);
    printf("���ַ����ȽϵĽ����\n");
    printf("%d\n", strcmp01(ch1, ch2));
    system("pause");
    return EXIT_SUCCESS;
}