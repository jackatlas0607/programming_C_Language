/*
013.
小明到保齡球館打保齡球，一輪有十局，假設小明一到八局都拿零分，剩下最後兩局
每局有十瓶保齡球瓶，倒一瓶保齡瓶得一分，每一局最多為十分，
每一局可以打兩次，若在第十局打出 strike，可以再多打一局，但當局只能打一次，試算
出總得分
測試案例(Test Case)資料：
Input：
2
5
7
1
Output：
15
---------------
Input：
5
5
10
0
8
Output：
28
*/

#include <stdio.h>
#include <math.h>

int cal(int nine_1, int nine_2, int ten_1, int ten_2, int bonus_1, int bonus_2)
{
    return nine_1 + nine_2 + ten_1 + ten_2 + bonus_1 + bonus_2;
}

int main()
{
    int nine_1, nine_2, ten_1, ten_2, bonus_1, bonus_2;
    scanf("%d", &nine_1);
    fflush(stdin);
    if (nine_1 == 10)
    {
        nine_2 = 0;
    }
    else
    {
        scanf("%d", &nine_2);
        fflush(stdin);
    }

    scanf("%d", &ten_1);
    fflush(stdin);

    if (ten_1 == 10)
    {
        ten_2 = 0;

        scanf("%d", &bonus_1);
        fflush(stdin);

        if (bonus_1 == 10)
        {
            bonus_2 = 0;
        }
        else
        {
            scanf("%d", &bonus_2);
            fflush(stdin);
        }
    }
    else
    {
        scanf("%d", &ten_2);
        fflush(stdin);
        bonus_1 = 0;
        bonus_2 = 0;
    }

    printf("%d", cal(nine_1, nine_2, ten_1, ten_2, bonus_1, bonus_2));
}
