#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

float func(float x, int n);
int main()
{
    float x;
    int n;
    printf("������x��n��ֵ");
    if (scanf("%f%d", &x, &n) == 2)
    {
        printf("f(%f,%d)�Ľ��Ϊ: %f", x, n, func(x, n));
    }
    else printf("�����������");
    system("pause");
    return EXIT_SUCCESS;
}   

float func(float x, int n)
{
    if (n == 1) return sqrt(1 + x);
    else if (n > 1) return sqrt(n + func(x, n - 1));
    else return 0;
}