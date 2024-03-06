/*
011.
請檢查輸入的三門課程是否衝堂。
依序輸入
課程編號 (4 位數字)、
上課小時數 (1-2 小時)、
上課時間 (依小時數輸入上課時間, 星期 1-5, 第 1-8 節)。
輸入任何錯誤，輸出-1。
輸入說明：
---------------
1002 (第一門課課程編號)
2 (2 小時)
33 (星期 3 第 3 節課)
59 (星期 5 第 9 節課)
1003 (第二門課課程編號)
2 (2 小時)
11 (星期 1 第 1 節課)
33 (星期 3 第 3 節課)
3003 (第三門課課程編號)
2 (2 小時)
11 (星期 1 第 1 節課)
33 (星期 3 第 3 節課)
(上課時間輸入順序為星期 1~5，第 1 節 ~ 第 8 節)
(課程編號輸入順序為編號大小)
輸出說明：
---------------
1002,1003,33
1002,3003,33
1003,3003,11
1003,3003,33
輸出 課程編號,課程編號,衝突時間
若沒有衝突則輸出 correct
若有錯誤輸入則輸出 -1
(每次列出兩個衝突課程編號，一個衝突時間，所有倆倆課程衝突均要列出)
(衝突輸出順序，課程 1-2, 1-3, 2-3, 第 1 節 ~ 第 2 節)
測試案例(Test Case)資料：
Input：
1001
2
12
13
1002
2
13
21
1003
2
21
25
Output：
1001,1002,13
1002,1003,21
---------------
Input：
1001
1
21
1002
2
32
33
1003
2
45
46
Output：
correct
---------------
Input：
101
3
99
1002
2
32
33
1003
2
45
46
Output：
-1
*/

#include <stdio.h>
#include <math.h>

void cal(int class_name1, int time1, int class1_time1, int class1_time2, int class_name2, int time2, int class2_time1, int class2_time2, int class_name3, int time3, int class3_time1, int class3_time2)
{
    if (!(11 <= class1_time1 && class1_time1 <= 18 || 21 <= class1_time1 && class1_time1 <= 28 || 31 <= class1_time1 && class1_time1 <= 38 || 41 <= class1_time1 && class1_time1 <= 48 || 51 <= class1_time1 && class1_time1 <= 58))
    {
        printf("-1");
        return;
    }

    if (time1 == 2 && !(11 <= class1_time2 && class1_time2 <= 18 || 21 <= class1_time2 && class1_time2 <= 28 || 31 <= class1_time2 && class1_time2 <= 38 || 41 <= class1_time2 && class1_time2 <= 48 || 51 <= class1_time2 && class1_time2 <= 58))
    {
        printf("-1");
        return;
    }

    if (!(11 <= class2_time1 && class2_time1 <= 18 || 21 <= class2_time1 && class2_time1 <= 28 || 31 <= class2_time1 && class2_time1 <= 38 || 41 <= class2_time1 && class2_time1 <= 48 || 51 <= class2_time1 && class2_time1 <= 58))
    {
        printf("-1");
        return;
    }

    if (time2 == 2 && !(11 <= class2_time2 && class2_time2 <= 18 || 21 <= class2_time2 && class2_time2 <= 28 || 31 <= class2_time2 && class2_time2 <= 38 || 41 <= class2_time2 && class2_time2 <= 48 || 51 <= class2_time2 && class2_time2 <= 58))
    {
        printf("-1");
        return;
    }

    if (!(11 <= class3_time1 && class3_time1 <= 18 || 21 <= class3_time1 && class3_time1 <= 28 || 31 <= class3_time1 && class3_time1 <= 38 || 41 <= class3_time1 && class3_time1 <= 48 || 51 <= class3_time1 && class3_time1 <= 58))
    {
        printf("-1");
        return;
    }

    if (time3 == 2 && !(11 <= class3_time2 && class3_time2 <= 18 || 21 <= class3_time2 && class3_time2 <= 28 || 31 <= class3_time2 && class3_time2 <= 38 || 41 <= class3_time2 && class3_time2 <= 48 || 51 <= class3_time2 && class3_time2 <= 58))
    {
        printf("-1");
        return;
    }

    // 查看衝堂
    // class1 與其他課是否衝堂，所以 class1 跟 class2,class3都比過了
    if (class1_time1 == class2_time1 || class1_time1 == class2_time2)
    {
        printf("%d,%d,%d\n", class_name1, class_name2, class1_time1);
    }
    else if (class1_time1 == class3_time1 || class1_time1 == class3_time2)
    {
        printf("%d,%d,%d\n", class_name1, class_name3, class1_time1);
    }
    else if (class1_time2 == class2_time1 || class1_time2 == class2_time2)
    {
        printf("%d,%d,%d\n", class_name1, class_name2, class1_time2);
    }
    else if (class1_time2 == class3_time1 || class1_time2 == class3_time2)
    {
        printf("%d,%d,%d\n", class_name1, class_name3, class1_time2);
    }

    // 比較 class2跟 class3
    if (class2_time1 == class3_time1 || class2_time1 == class3_time2)
    {
        printf("%d,%d,%d\n", class_name2, class_name3, class2_time1);
    }
    else if (class2_time2 == class3_time1 || class2_time2 == class3_time2)
    {
        printf("%d,%d,%d\n", class_name2, class_name3, class2_time2);
    }
    else
    {
        printf("correct");
    }
}

int main()
{
    int class_name1, time1, class1_time1, class1_time2;
    int class_name2, time2, class2_time1, class2_time2;
    int class_name3, time3, class3_time1, class3_time2;

    scanf("%d", &class_name1);
    fflush(stdin);
    scanf("%d", &time1);
    fflush(stdin);
    scanf("%d", &class1_time1);
    fflush(stdin);

    if (time1 == 2)
    {
        scanf("%d", &class1_time2);
        fflush(stdin);
    }
    else
    {
        class1_time2 = 0;
    }

    scanf("%d", &class_name2);
    fflush(stdin);
    scanf("%d", &time2);
    fflush(stdin);
    scanf("%d", &class2_time1);
    fflush(stdin);

    if (time2 == 2)
    {
        scanf("%d", &class2_time2);
        fflush(stdin);
    }
    else
    {
        class2_time2 = 0;
    }

    scanf("%d", &class_name3);
    fflush(stdin);
    scanf("%d", &time3);
    fflush(stdin);
    scanf("%d", &class3_time1);
    fflush(stdin);

    if (time3 == 2)
    {
        scanf("%d", &class3_time2);
        fflush(stdin);
    }
    else
    {
        class3_time2 = 0;
    }

    cal(class_name1, time1, class1_time1, class1_time2, class_name2, time2, class2_time1, class2_time2, class_name3, time3, class3_time1, class3_time2);
}