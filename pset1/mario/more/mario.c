#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int altura;
    do
    {
        altura = get_int("Tamanho: ");
    }
    while (altura < 1 || altura > 8);

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            printf((j < (altura - (i + 1))) ? " " : "#");
        }

        printf("  ");

        for (int m = i; m >= 0; m--)
        {
            printf("#");
        }
        printf("\n");
    }
}