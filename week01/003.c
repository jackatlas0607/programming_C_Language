/*
003.
數值運算
分別輸入(int) num1 num2 求出兩數的 Sum,Difference,Product,Quotient。
Difference 結果取絕對值，使用 double fabs(double);
須 #include < math.h >
結果須輸出到小數點第二位(double)
printf("%.2f",x1);
輸入:
25
2
輸出:
Difference:23.00
Sum:27.00
Quotient:12.50
Product:50.00
*/

#include <stdio.h>
#include <math.h>

void cal(int num1, int num2)
{
    double sum, difference, product, quotient;
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    printf("Difference:%.2f\n", (double)num1 - num2);
    printf("Sum:%.2f\n", sum);
    printf("Quotient:%.2f\n", quotient);
    printf("Product:%.2f\n", product);
}

int main()
{
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    cal(num1, num2);
}