/*
010.
最佳資費選擇
輸入每月網內、網外、市話、通話時間(秒)及網內、網外簡訊則數，求最佳資費。
費率如下表：
資費類型 183 型 383 型 983 型
月租費 183 元 383 元 983 元
優惠內容 月 租 費 可 抵 等 額 通 信 費
語音費率 網內 0.08 0.07 0.06
(元/秒) 網外 0.139 0.130 0.108
 市話 0.135 0.121 0.101
(元/秒)
簡訊費率 網內 1.128 1.128 1.128
(元/則) 網外 1.483 1.483 1.483
---------------
輸入說明：
---------------
網內語音(秒)，整數
網外語音(秒)，整數
市話 (秒)，整數
網內簡訊數，整數
網外簡訊數，整數
輸入說明：
---------------
費用，整數
最佳資費類型，(183, 383, 983)
測試案例(Test Case)資料：
Input：
120
150
20
10
5
Output：
183
183
---------------
Input：
3000
4000
200
5
5
Output：
767
383
*/

#include <stdio.h>
#include <math.h>

void cal(int a, int b, int c, int d, int e)
{
    int total_183;
    int total_383;
    int total_983;

    total_183 = a * 0.08 + b * 0.139 + c * 0.135 + d * 1.128 + e * 1.483;
    total_383 = a * 0.07 + b * 0.130 + c * 0.121 + d * 1.128 + e * 1.483;
    total_983 = a * 0.06 + b * 0.108 + c * 0.101 + d * 1.128 + e * 1.483;

    // 比較扣掉月租費的價格，拿來看要選定哪個方案
    int new_183, new_383, new_983;
    int min;

    if (total_183 > 183)
    {
        new_183 = total_183 - 183;
    }
    else
    {
        total_183 = 183;
        new_183 = 183;
    }

    if (total_383 > 383)
    {
        new_383 = total_383 - 383;
    }
    else
    {
        total_383 = 383;
        new_383 = 383;
    }

    if (total_983 > 983)
    {
        new_983 = total_983 - 983;
    }
    else
    {
        total_983 = 983;
        new_983 = 983;
    }

    min = new_183 < new_383 ? new_183 : new_383;
    min = min < new_983 ? min : new_983;

    if (min == new_183)
    {
        printf("%d\n", total_183);
        printf("183");
    }
    else if (min == new_383)
    {
        printf("%d\n", total_383);
        printf("383");
    }
    else
    {
        printf("%d\n", total_983);
        printf("983");
    }
}

int main()
{
    int a, b, c, d, e;
    scanf("%d", &a);
    fflush(stdin);
    scanf("%d", &b);
    fflush(stdin);
    scanf("%d", &c);
    fflush(stdin);
    scanf("%d", &d);
    fflush(stdin);
    scanf("%d", &e);
    fflush(stdin);

    cal(a, b, c, d, e);
}