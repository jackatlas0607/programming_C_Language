/*
012.
請算出 a,b,c 三條線在 X 軸上所涵蓋的長度(不含重複線段)
例如:a(x1,x2)表示 a 線段為 X 軸上點 x1 到點 x2 的線
輸入說明:
---------------
-1 (a 的 x1 座標為 -1)
1 (a 的 x2 座標為 1)
0 (b 的 x1 座標為 0)
2 (b 的 x2 座標為 2)
1 (c 的 x1 座標為 1)
3 (c 的 x2 座標為 3)
<img src="https://i.imgur.com/3RWOXvp.png">
輸出說明:
---------------
4
*/

#include <stdio.h>
#include <math.h>

int cal(int a_x1, int a_x2, int b_x1, int b_x2, int c_x1, int c_x2)
{
    int min = a_x1;

    if (min > a_x2)
    {
        min = a_x2;
    }

    if (min > b_x1)
    {
        min = b_x1;
    }

    if (min > b_x2)
    {
        min = b_x2;
    }

    if (min > c_x1)
    {
        min = c_x1;
    }

    if (min > c_x2)
    {
        min = c_x2;
    }

    int max = a_x1;

    if (max < a_x2)
    {
        max = a_x2;
    }

    if (max < b_x1)
    {
        max = b_x1;
    }

    if (max < b_x2)
    {
        max = b_x2;
    }

    if (max < c_x1)
    {
        max = c_x1;
    }

    if (max < c_x2)
    {
        max = c_x2;
    }

    return abs(max - min);
}

int main()
{
    int a_x1, a_x2, b_x1, b_x2, c_x1, c_x2;
    scanf("%d %d %d %d %d %d", &a_x1, &a_x2, &b_x1, &b_x2, &c_x1, &c_x2);
    fflush(stdin);

    printf("%d\n", cal(a_x1, a_x2, b_x1, b_x2, c_x1, c_x2));
}