/*
006.
判斷何種三角形
當三個邊長能構成三角形時，再判斷該三角形是否為正三角形，若否，則判斷是否為等腰三
角形：
1. 不能成為三角形：任兩邊和不大於第三邊，或任一邊長不大於 0。
2. 正三角形：三個邊相等。
3. 等腰三角形：任兩邊相等，平方和大於第三邊的平方。
4. 一般三角形：非正三角形與等腰三角形。
此題必須寫一個運算的 function
int getTriangle(int a, int b, int c);
輸入說明：
---------------
輸入三個整數邊長
輸出說明：
---------------
1. 不能成為三角形：輸出 not triangle。
2. 正三角形：輸出 equilateral triangle。
3. 等腰三角形：輸出 isosceles triangle。
4. 一般三角形：輸出 triangle。
測試案例(Test Case)資料：
Input：
4 1 1
Output：
not triangle
---------------
Input：
3 3 3
Output：
equilateral triangle
---------------
Input：
3 2 3
Output：
isosceles triangle
---------------
Input：
7 8 9
Output：
triangle
*/

#include <stdio.h>
#include <math.h>

void getTriangle(int a, int b, int c)
{
    if (a == b && b == c && a == c)
    {
        printf("equilateral triangle");
        return;
    }

    if (a * a + b * b > c * c && a * a + c * c > b * b && b * b + c * c > a * a)
    {
        if (a == b || a == c || b == c)
        {
            printf("isosceles triangle");
        }
        else
        {
            printf("triangle");
        }
    }
    else
    {
        printf("not triangle");
    }
}

int main()
{
    int a, b, c;
    scanf("%d", &a);
    fflush(stdin);
    scanf("%d", &b);
    fflush(stdin);
    scanf("%d", &c);

    getTriangle(a, b, c);
}