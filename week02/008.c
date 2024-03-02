/*
008.
一元二次方程式
一元二次方程式，aX^2 + bx + c = 0，輸入 a, b, c, 求 方程式的兩個實/虛根。
T = sqrt(b*b-4*a*c)
第一個根， x1 = (-b+T)/(2*a)
第二個根， x2 = (-b-T)/(2*a)
本題須 #include < math.h >
---------------
輸入說明：
第一個數 a
第二個數 b
第三個數 c
---------------
輸出說明：
當 T>=0
輸出 x1, x2 為實根，輸出到小數點第一位 printf("%.1f",x1);
當 T<0
輸出 x1 , x2 為虛根，輸出到小數點第一位
printf("%.1f+%.1fi",x11, x12);
printf("%.1f-%.1fi",x21, x22);
若 x11 或 x21 為 0.0 時，不須輸出正負號
測試案例(Test Case)資料：
Input：
1
-2
1
Output：
1.0
1.0
---------------
Input：
1
2
2
Output：
-1.0+1.0i
-1.0-1.0i
*/

#include <stdio.h>
#include <math.h>

void cal(int a, int b, int c)
{
    float T = sqrt(b * b - 4 * a * c);

    if (T >= 0)
    {
        float x1 = (-b + T) / 2 * a;
        float x2 = (-b - T) / 2 * a;
        printf("%.1f\n", x1);
        printf("%.1f\n", x2);
    }
    else
    {
        float x_real = -b / 2 * a;
        float xi_plus = sqrt(-(b * b - 4 * a * c)) / 2 * a;
        float xi_negative = sqrt(-(b * b - 4 * a * c)) / 2 * a;

        printf("%.1f+%.1fi\n", x_real, xi_plus);
        printf("%.1f-%.1fi\n", x_real, xi_negative);
    }
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    /*
    連續使用多個scanf會有緩衝區的問題，
    用fflush來清理就部會有問題
    scanf("%d", &a);
    fflush(stdin);
    scanf("%d", &b);
    fflush(stdin);
    scanf("%d", &c);
    */
    cal(a, b, c);
}