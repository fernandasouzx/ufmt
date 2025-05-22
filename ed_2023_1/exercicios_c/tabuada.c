#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, multi, i;

    printf("Informe um valor para o cálculo da tabuada: ");
    scanf("%d", &number);
    printf("TABUADA DO %d\n", number);

    for (i = 1; i <= 10; i++)
    {
        multi = number * i;
        printf("%d X %d = %d\n", number, i, multi);
    }
}