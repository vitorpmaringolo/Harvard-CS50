#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int altura;
    do
    {
        // Solicita o tamanho para o usuário
        altura = get_int("Tamanho: ");
    }
    while (altura < 1 || altura > 8); // Caso seja menor que 1 ou maior do que 8, solicita novamente

    // Altura ou colunas da pirâmide
    for (int i = 0; i < altura; i++)
    {
        // Linhas da pirâmide
        for (int j = 0; j < altura; j++)
        {
            printf(j < (altura - (i + 1)) ? " " : "#");
        }
        printf("\n");
    }
}