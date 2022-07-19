#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int contarLetras(string input);
int contarPalavras(string input);
int contarFrases(string input);

int main(void)
{

    string texto = get_string("Text: ");

    float letras = contarLetras(texto);
    float palavras = contarPalavras(texto);
    float frases = contarFrases(texto);

    float indice = ((0.0588 * ((letras / palavras) * 100)) - (0.296 * ((frases / palavras) * 100)) - 15.8);
    int grau = round(indice);

    if (grau < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grau >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grau);
    }
}

int contarLetras(string input)
{
    int count = 0;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]))
        {
            count++;
        }
    }

    return count;
}

int contarPalavras(string input)
{
    int count = 0;

    for (int i = 0, n = strlen(input); i < n + 1; i++)
    {
        if (isspace(input[i]) || input[i] == '\0')
        {
            count++;
        }
    }

    return count;
}

int contarFrases(string input)
{
    int count = 0;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            count++;
        }
    }

    return count;
}
