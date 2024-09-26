#include <stdio.h>

int main()
{
    int t;
    int i;
    int num1 [100000];
    int num2 [100000];
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        scanf("%d %d", &num1[i], &num2[i]);
    }
    for (i = 1; i <= t; i++)
    {
        printf("%d\n", num1[i] + num2[i]);
    }
    return 0;
}