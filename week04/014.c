/*
014.
停車費計算
假設某個停車場的費率是停車 2 小時以內，每半小時 30 元，未滿半小時部分不計費。
超過 2 小時，但未滿 4 小時，每半小時 40 元，未滿半小時以半小時計費。
超過 4 小時以上的部份，每半小時 60 元，未滿半小時以半小時計費。
請撰寫程式計算輸入數筆資料，共需繳交的停車費。
本程式不考慮隔夜情況。
輸入說明：
---------------
輸入 3 組時間，每組分別為開始與離開時間，24 小時制。
若輸入格式錯誤，則輸出 error
輸出說明：
---------------
輸出總停車費。
測試案例(Test Case)資料：
Input：
8:00
9:15
13:45
16:50
6:20
10:50
Output：
60
280
540
Input：
00:01
25:00
00:11
23:66
-01:00
12:34
Output：
error
error
error
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

/*
C/C++ 如果一個函數接受 array為參數( char[])，相當於接受一個指標
放在function裡, 並不會回傳 input array的大小, 而會回傳 char* 指標的 size大小
sizeof(char[]) 相當於  sizeof(char *)                                                                                                                                                                                                                                                                                                                                                                                                                                          sizeof(char* )
一般所通用的64 位元作業系統中，指標的大小就是8 bytes
*/

int cal_fee(int time);
void reset_array(char *arr, int len);
void cal(char time1_1[], char time1_2[], char time2_1[], char time2_2[], char time3_1[], char time3_2[]);
bool check_array_all_digit(char *arr, int len);

int main()
{
    char time1_1[7] = {'\0'};
    char time1_2[7] = {'\0'};
    char time2_1[7] = {'\0'};
    char time2_2[7] = {'\0'};
    char time3_1[7] = {'\0'};
    char time3_2[7] = {'\0'};

    scanf("%s", time1_1);
    fflush(stdin);
    scanf("%s", time1_2);
    fflush(stdin);
    scanf("%s", time2_1);
    fflush(stdin);
    scanf("%s", time2_2);
    fflush(stdin);
    scanf("%s", time3_1);
    fflush(stdin);
    scanf("%s", time3_2);
    fflush(stdin);

    cal(time1_1, time1_2, time2_1, time2_2, time3_1, time3_2);
}

int cal_fee(int time)
{
    int total = 0;

    if (time < 30)
    {
        total = 0;
    }
    else if (time <= 120)
    {
        total = 30 * (time / 30);
    }
    else if (time < 240)
    {

        if (time % 30 == 0)
        {
            total = 40 * (time / 30);
        }
        else
        {
            total = 40 * (time / 30) + 40;
        }
    }
    else
    {

        if (time % 30 == 0)
        {
            total = 60 * (time / 30);
        }
        else
        {
            total = 60 * (time / 30) + 60;
        }
    }
    return total;
}

bool check_array_all_digit(char *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(arr[i]) && arr[i] != '\0')
        {
            return false;
        }
    }
    return true;
}

void reset_array(char *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        arr[i] = '\0';
    }
}

void cal(char time1_1[], char time1_2[], char time2_1[], char time2_2[], char time3_1[], char time3_2[])
{
    int time1_1_minutes, time1_2_minutes, time2_1_minutes, time2_2_minutes, time3_1_minutes, time3_2_minutes;
    int time1_1_hours, time1_2_hours, time2_1_hours, time2_2_hours, time3_1_hours, time3_2_hours;
    int parking_time1 = 0;
    int parking_time2 = 0;
    int parking_time3 = 0;
    bool flag_hours_1, flag_minutes_1, flag_hours_2, flag_minutes_2;

    char hours[3] = {'\0'};
    char minutes[3] = {'\0'};

    // 第一筆停車資訊
    if (time1_1[4] == '\0')
    {
        time1_1_hours = atoi((strncpy(hours, &time1_1[0], 1)));
        time1_1_minutes = atoi((strncpy(minutes, &time1_1[2], 2)));
    }
    else
    {
        time1_1_hours = atoi(strncpy(hours, &time1_1[0], 2));
        time1_1_minutes = atoi(strncpy(minutes, &time1_1[3], 2));
    }

    flag_hours_1 = check_array_all_digit(hours, sizeof(hours) / sizeof(hours[0]));
    flag_minutes_1 = check_array_all_digit(minutes, sizeof(minutes) / sizeof(minutes[0]));

    reset_array(hours, sizeof(hours));
    reset_array(minutes, sizeof(minutes));

    if (time1_2[4] == '\0')
    {
        time1_2_hours = atoi((strncpy(hours, &time1_2[0], 1)));
        time1_2_minutes = atoi((strncpy(minutes, &time1_2[2], 2)));
    }
    else
    {
        time1_2_hours = atoi(strncpy(hours, &time1_2[0], 2));
        time1_2_minutes = atoi(strncpy(minutes, &time1_2[3], 2));
    }

    flag_hours_2 = check_array_all_digit(hours, sizeof(hours) / sizeof(hours[0]));
    flag_minutes_2 = check_array_all_digit(minutes, sizeof(minutes) / sizeof(minutes[0]));

    reset_array(hours, sizeof(hours));
    reset_array(minutes, sizeof(minutes));

    if (!flag_hours_1 || !flag_minutes_1 || !flag_hours_2 || !flag_minutes_2 || time1_1_hours >= 24 || time1_1_minutes >= 60 || time1_2_hours >= 24 || time1_2_minutes >= 60)
    {
        printf("error\n");
    }
    else
    {
        parking_time1 = (60 * time1_2_hours + time1_2_minutes) - (60 * time1_1_hours + time1_1_minutes);
        printf("%d\n", cal_fee(parking_time1));
    }

    // 第二筆停車資訊
    if (time2_1[4] == '\0')
    {
        time2_1_hours = atoi((strncpy(hours, &time2_1[0], 1)));
        time2_1_minutes = atoi((strncpy(minutes, &time2_1[2], 2)));
    }
    else
    {
        time2_1_hours = atoi(strncpy(hours, &time2_1[0], 2));
        time2_1_minutes = atoi(strncpy(minutes, &time2_1[3], 2));
    }

    flag_hours_1 = check_array_all_digit(hours, sizeof(hours) / sizeof(hours[0]));
    flag_minutes_1 = check_array_all_digit(minutes, sizeof(minutes) / sizeof(minutes[0]));

    reset_array(hours, sizeof(hours));
    reset_array(minutes, sizeof(minutes));

    if (time2_2[4] == '\0')
    {
        time2_2_hours = atoi((strncpy(hours, &time2_2[0], 1)));
        time2_2_minutes = atoi((strncpy(minutes, &time2_2[2], 2)));
    }
    else
    {
        time2_2_hours = atoi(strncpy(hours, &time2_2[0], 2));
        time2_2_minutes = atoi(strncpy(minutes, &time2_2[3], 2));
    }

    flag_hours_2 = check_array_all_digit(hours, sizeof(hours) / sizeof(hours[0]));
    flag_minutes_2 = check_array_all_digit(minutes, sizeof(minutes) / sizeof(minutes[0]));

    reset_array(hours, sizeof(hours));
    reset_array(minutes, sizeof(minutes));

    if (!flag_hours_1 || !flag_minutes_1 || !flag_hours_2 || !flag_minutes_2 || time2_1_hours >= 24 || time2_1_minutes >= 60 || time2_2_hours >= 24 || time2_2_minutes >= 60)
    {
        printf("error\n");
    }
    else
    {
        parking_time2 = (60 * time2_2_hours + time2_2_minutes) - (60 * time2_1_hours + time2_1_minutes);
        printf("%d\n", cal_fee(parking_time2));
    }

    // 第三筆停車資訊

    if (time3_1[4] == '\0')
    {
        time3_1_hours = atoi((strncpy(hours, &time3_1[0], 1)));
        time3_1_minutes = atoi((strncpy(minutes, &time3_1[2], 2)));
    }
    else
    {
        time3_1_hours = atoi(strncpy(hours, &time3_1[0], 2));
        time3_1_minutes = atoi(strncpy(minutes, &time3_1[3], 2));
    }

    flag_hours_1 = check_array_all_digit(hours, sizeof(hours) / sizeof(hours[0]));
    flag_minutes_1 = check_array_all_digit(minutes, sizeof(minutes) / sizeof(minutes[0]));
    reset_array(hours, sizeof(hours));
    reset_array(minutes, sizeof(minutes));

    if (time3_2[4] == '\0')
    {
        time3_2_hours = atoi((strncpy(hours, &time3_2[0], 1)));
        time3_2_minutes = atoi((strncpy(minutes, &time3_2[2], 2)));
    }
    else
    {
        time3_2_hours = atoi(strncpy(hours, &time3_2[0], 2));
        time3_2_minutes = atoi(strncpy(minutes, &time3_2[3], 2));
    }

    flag_hours_2 = check_array_all_digit(hours, sizeof(hours) / sizeof(hours[0]));
    flag_minutes_2 = check_array_all_digit(minutes, sizeof(minutes) / sizeof(minutes[0]));

    reset_array(hours, sizeof(hours));
    reset_array(minutes, sizeof(minutes));

    if (!flag_hours_1 || !flag_minutes_1 || !flag_hours_2 || !flag_minutes_2 || time3_1_hours >= 24 || time3_1_minutes >= 60 || time3_2_hours >= 24 || time3_2_minutes >= 60)
    {
        printf("error\n");
    }
    else
    {
        parking_time3 = (60 * time3_2_hours + time3_2_minutes) - (60 * time3_1_hours + time3_1_minutes);
        printf("%d\n", cal_fee(parking_time3));
    }
}