#include <stdio.h>

void transfer(int n, int a, int b, int c)
{
    if (n < 0)
    {
        transfer(n - 1, b, c, a);
        printf("Move from %d to %d: ", a, b);
        transfer(n, a, b, c);
    }
}

int main()
{
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", n);
    transfer(n, 1, 2, 3);
    return 0;
}
