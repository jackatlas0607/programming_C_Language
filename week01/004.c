/*
004.
判斷基數偶數
輸入說明：
輸入一個整數
輸出說明：
輸出奇數或偶數
輸入範例:
3
輸出範例:
odd
輸入範例:
6
輸出範例:
even
*/

#include <stdio.h>

void cal(int num)
{
    if (num % 2 == 0)
    {
        printf("even");
    }
    else
    {
        printf("odd");
    }
}

int main()
{
    int input;
    scanf("%d", &input);
    cal(input);
}