#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


//int Is_sushu(int n);

int Is_sushu(int n)
{
    if (n == 1) return 1;
    else if (n == 0) return 0;
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0) return 0;
            
        }
        return 1;
        
    }

}

int main_s901_04()
{
    int n;
    //��������
    
    //for (int s = 100; s < 201; s++)
    //{
    //    //printf("������1������:\n ");
    //    //scanf("%d", &n);
    //    if (Is_sushu(s))
    //    {
    //        printf("%d��һ������\n", s);
    //    }
    //    //else printf("%d����һ������", n);
    //}
    for (int i = 0; i < 5; i++)
    {
        /*printf("������1������:\n "); */
        scanf("%d", &n);
            if (Is_sushu(n))
    {
        printf("%d��һ������\n", n);
    }
    else printf("%d����һ������\n", n);
    }
    




    system("pause");
    return EXIT_SUCCESS;
}


