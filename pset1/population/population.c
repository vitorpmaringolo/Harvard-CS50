#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int inicio, fim;
    int anos = 0;

    /* Solicita população inicial.
    Precisa ser um número maior do que 9.*/
    do
    {
        inicio = get_int("Start size: ");
    }
    while (inicio < 9);

    /* Solicita a população final.
    Precisa ser um número maior ou igual
    ao informado na população inicial. */
    do
    {
        fim = get_int("End size: ");
    }
    while (inicio > fim);

    /* Calcula a quantidade de anos que levará
    para atingir a população final.*/
    for (int i = 0; inicio < fim; i++)
    {
        inicio += (inicio / 3) - (inicio / 4);
        anos++;
    }

    // Quantidade de anos que levará para atingir o crescimento populacional.
    printf("Years: %i\n", anos);
}