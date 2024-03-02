/*
005.
BMI 計算

輸入身高(公尺) 體重(公斤)(皆使用 double)

BMI = 體重(公斤) / (身高*身高)(公尺)

結果須輸出到小數點第一位(double)
 printf("%.1f",x1);

輸入:
1.72
60

輸出:
 20.3
*/

#include <stdio.h>
#include <math.h>

void cal(double height, double weight)
{
    double BMI = weight / pow(height, 2);
    printf("%.1lf\n", BMI);
}

int main()
{
    double height, weight;

    /*
    用scanf讀的時候，讀%f就規規矩矩的放進float中來存，讀%lf就放進double中，
    這樣在使用的時候里面的數據才不會錯位
    */
    scanf("%lf %lf", &height, &weight);
    cal(height, weight);
}