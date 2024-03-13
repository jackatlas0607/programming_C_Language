#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    char time[3] = "-0";
    printf("%d\n", isdigit(time[2]));
}