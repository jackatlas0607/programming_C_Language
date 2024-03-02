#include <stdio.h>

/*
001.
計算總成績、平均
某一學生修國文、計算機概論、計算機程式設計三科，使用者輸入名字（一個 char）、學號
（int）、三科成績(int)。
(1) 計算學生總成績、平均。
(2) 印出名字、學號、總成績、平均。
Input
K
905067
100
100
100
Output
Name:K
ID:905067
Average:100
Total:300
*/
void calculate(char c, int id, int grade1, int grade2, int grade3)
{
    printf("%c\n%d\n%d\n%d\n", c, id, (grade1 + grade2 + grade3) / 3, grade1 + grade2 + grade3);
}

int main()
{
    calculate('K', 905067, 100, 100, 100);
}