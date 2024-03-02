/*
009
A、B、C 三本書價格及折扣表如下：
 定價 1~10 本 11~20 本 21~30 本 31 本以上
A 380 原價 打 9 折 打 8.5 折 打 8 折
B 1200 原價 打 9.5 折 打 8.5 折 打 8 折
C 180 原價 打 8.5 折 打 8 折 打 7 折
有一顧客欲購買 A：ｘ本、B：ｙ本、C：ｚ本（ｘ、ｙ、ｚ為使用者輸入），請計算需花費
多少錢？
例如：
A 購買 6 本 B 購買 12 本 C 購買 30 本
6*380+12*1200*0.95+30*180*0.8
=20280
輸入說明：
---------------
A 書本數量，整數
B 書本數量，整數
C 書本數量，整數
輸出說明：
---------------
費用，整數
printf("%d", x);
測試案例(Test Case)資料：
Input：
6
12
30
Output：
20280
*/

#include <stdio.h>
#include <math.h>

void cal(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0)
    {
        return;
    }

    int book_A = 380;
    int book_B = 1200;
    int book_C = 180;

    int total = 0;

    // book A
    if (a <= 10)
    {
        total += book_A * a;
    }
    else if (a <= 20)
    {
        total += book_A * 0.9 * a;
    }
    else if (a <= 30)
    {
        total += book_A * 0.85 * a;
    }
    else
    {
        total += book_A * 0.8 * a;
    }

    // book B
    if (b <= 10)
    {
        total += book_B * b;
    }
    else if (b <= 20)
    {
        total += book_B * 0.95 * b;
    }
    else if (b <= 30)
    {
        total += book_B * 0.85 * b;
    }
    else
    {
        total += book_B * 0.8 * b;
    }

    // book C
    if (c <= 10)
    {
        total += book_C * c;
    }
    else if (c <= 20)
    {
        total += book_C * 0.85 * c;
    }
    else if (c <= 30)
    {
        total += book_C * 0.8 * c;
    }
    else
    {
        total += book_C * 0.7 * c;
    }

    printf("%d", total);
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    cal(a, b, c);
}