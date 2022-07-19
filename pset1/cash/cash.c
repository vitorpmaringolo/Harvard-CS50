#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float reais;
    int moedas = 0;

    do
    {
        reais = get_float("Troco devido: ");
    }
    while (reais < 0);

    int centavos = round(reais * 100);

    while (centavos >= 25)
    {
        moedas++;
        centavos -= 25;
    }

    while (centavos >= 10)
    {
        moedas++;
        centavos -= 10;
    }

    while (centavos >= 5)
    {
        moedas++;
        centavos -= 5;
    }

    while (centavos >= 1)
    {
        moedas++;
        centavos--;
    }


    printf("%i\n", moedas);
}