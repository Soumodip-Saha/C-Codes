#include <stdio.h>
int factorial(int, int);
int main()
{
    int num;
    printf("\n Enter a number : ");
    scanf("%d", &num);
    int fact = 1;
    int f;
    f = factorial(num, fact);
    printf("\n Factorial of %d is : %d \n", num, f);
    return 0;
}
int factorial(int num, int fact)
{
    if (num == 0 || num == 1)
    {
        return fact;
    }
    else
    {
        return factorial(num - 1, fact * num);
    }
}
