/*
007.
請輸入五個數字，分別計算出平均數、變異數、標準差，
並精確到小數點後第二位(註，之後的小數捨去)。
變異數參考公式：
Σ(Xi-μ)^2/N
標準差參考公式：
(Σ(Xi-μ)^2/N)^(0.5)
平均數參考公式：
μ=Σ(Xi)/N
例如：1 2 8 9 10
變異數：14.00
> Σ(Xi-μ)^2=(1-6)^2+(2-6)^2+(8-6)^2+(9-6)^2+(10-6)^2
 =25+16+4+9+16=70
 700./5.0=14.00
標準差：3.74
> 14^(0.5) = 3.74165
 取兩位小數 = 3.74
平均值：6.00
> (1+2+8+9+10)/5.0 = 6.00
輸入說明：
---------------
輸入五個整數
輸出說明：
---------------
變異數
標準差
平均值
輸出到小數點第二位 printf("%.2f",x);
測試案例(Test Case)資料：
Input：
1 2 8 9 10
Output：
14.00
3.74
6.00
*/

#include <stdio.h>
#include <math.h>

void cal(int a, int b, int c, int d, int e)
{
    float mean = (a + b + c + d + e) / 5;
    float variance = (pow(a - mean, 2) + pow(b - mean, 2) + pow(c - mean, 2) + pow(d - mean, 2) + pow(e - mean, 2)) / 5;
    float standard_deviation = sqrt(variance);

    printf("%.2f\n", variance);
    printf("%.2f\n", standard_deviation);
    printf("%.2f\n", mean);
}

int main()
{
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    cal(a, b, c, d, e);
}