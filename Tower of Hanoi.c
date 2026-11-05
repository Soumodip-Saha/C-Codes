#include <stdio.h>
void toh(int, char, char, char);
int main(void)
{
    printf("\n Towewr Of Hanoi");
    printf("\n S is Source - T is Temporary - D is Destination");
    char source = 'S', temp = 'T', dest = 'D';
    int number_of_discs;
    printf("\n Enter the number of discs : ");
    scanf("%d", &number_of_discs);
    toh(number_of_discs, source, temp, dest);
    printf("\n");
    return 0;
}
void toh(int n, char source, char temp, char dest)
{
    if (n == 1)
    {
        printf("\n Move disc %d from %c to %c", n, source, dest);
        return;
    }
    toh(n - 1, source, dest, temp);
    printf("\n Move disc %d from %c to %c", n, source, dest);
    toh(n - 1, temp, source, dest);
}
