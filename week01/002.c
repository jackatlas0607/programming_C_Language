/*
002.
一元二次方程式
一元二次方程式，aX^2 + bx + c = 0，輸入 a, b, c, 求 方程式的兩個實根。
---------------
輸入說明
第一個數(int) a
第二個數(int) b
第三個數(int) c
---------------
輸出說明
第一個實根(double)， x1 = ((-b)+sqrt(b*b-4*a*c))/(2*a)
第二個實根(double)， x2 = ((-b)-sqrt(b*b-4*a*c))/(2*a)
須 #include < math.h >
x1, x2 輸出到小數點第一位
printf("%.1f",x1);
---------------
Input
1
-2
1
Output
1.0
1.0
*/

#include <stdio.h>
#include <math.h>

void cal(int a, int b, int c)
{
    double x1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
    double x2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
    printf("%.1f\n", x1);
    printf("%.1f\n", x2);
}

int main()
{
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    cal(a, b, c);
}