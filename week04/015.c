/*
羅馬數字共有 7 個，即Ⅰ（1）、Ⅴ（5）、Ⅹ（10）、Ⅼ（50）、Ⅽ（100）、Ⅾ（500）和Ⅿ
（1000）。
按照下述的規則可以表示任意正整數。
需要注意的是羅馬數字中沒有「0」，與進位制無關。一般認為羅馬數字只用來記數，而不作
演算。
重複數次：
一個羅馬數字重複幾次，就表示這個數的幾倍。
右加左減：
在較大的羅馬數字的右邊記上較小的羅馬數字，表示大數字加小數字。
在較大的羅馬數字的左邊記上較小的羅馬數字，表示大數字減小數字。
左減的數字有限制，僅限於 I、X、C。比如 45 不可以寫成 VL，只能是 XLV
但是，左減時不可跨越一個位值。比如，99 不可以用 IC（100-1）表示，而是用 XCIX
（[100-10]+[10-1]）表示。（等同於阿拉伯數字每位數字分別表示。）
左減數字必須為一位，比如 8 寫成 VIII，而非 IIX。
右加數字不可連續超過三位，比如 14 寫成 XIV，而非 XIIII。（見下方「數碼限制」一
項。）
數碼限制：
同一數碼最多只能連續出現三次，如 40 不可表示為 XXXX，而要表示為 XL。
Hint: 請由下表中找出規律，並用判斷式實作此題，若使用迴圈則不計分
禁止使用暴力破解
輸入說明：
---------------
輸入為一個正整數，並且小於 100
輸出說明：
---------------
根據輸入的整數，輸出對應的羅馬數字
測試案例(Test Case)資料：
Input：
3
Output：
III
Input：
40
Output：
XL
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

void cal(int num);

int main()
{
    int num;
    scanf("%d", &num);
    fflush(stdin);
    cal(num);
}

void cal(int num)
{
    char roman_numerals[8] = {'\0'};

    char one[] = "I";

    char two[] = "II";
    char three[] = "III";
    char four[] = "IV";

    char five[] = "V";

    char six[] = "VI";
    char seven[] = "VII";
    char eight[] = "VIII";
    char nine[] = "IX";

    char ten[] = "X";

    char twenty[] = "XX";
    char thirty[] = "XXX";
    char fourty[] = "XL";

    char fifty[] = "L";

    char sixty[] = "LX";
    char seventy[] = "LXX";
    char eighty[] = "LXXX";
    char ninety[] = "XC";

    char hundred[] = "C";

    int tens_digit = num / 10;

    switch (tens_digit)
    {
    case 1:
        strcat(roman_numerals, ten);
        break;
    case 2:
        strcat(roman_numerals, twenty);
        break;
    case 3:
        strcat(roman_numerals, thirty);
        break;
    case 4:
        strcat(roman_numerals, fourty);
        break;
    case 5:
        strcat(roman_numerals, fifty);
        break;
    case 6:
        strcat(roman_numerals, sixty);
        break;
    case 7:
        strcat(roman_numerals, seventy);
        break;
    case 8:
        strcat(roman_numerals, eighty);
        break;
    case 9:
        strcat(roman_numerals, ninety);
        break;
    default:
        break;
    }

    int units_digit = num % 10;

    switch (units_digit)
    {
    case 0:
        break;
    case 1:
        strcat(roman_numerals, one);
        break;
    case 2:
        strcat(roman_numerals, two);
        break;
    case 3:
        strcat(roman_numerals, three);
        break;
    case 4:
        strcat(roman_numerals, four);
        break;
    case 5:
        strcat(roman_numerals, five);
        break;
    case 6:
        strcat(roman_numerals, six);
        break;
    case 7:
        strcat(roman_numerals, seven);
        break;
    case 8:
        strcat(roman_numerals, eight);
        break;
    case 9:
        strcat(roman_numerals, nine);
        break;
    default:
        break;
    }

    printf("%s\n", roman_numerals);
}