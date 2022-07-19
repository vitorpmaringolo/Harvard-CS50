#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long numero = get_long("Número: ");
    int pares = 0;
    int impares = 0;
    int total = 0;
    int contador = 0;
    int dezena = 0;
    int check = 0;

    for (int i = 1; numero > 0; i++)
    {
        if (i % 2 == 0)
        {
            if (((numero % 10) * 2) < 9)
            {
                pares += ((numero % 10) * 2);
            }
            else
            {
                int num2 = ((numero % 10) * 2);
                int num3, num4 = 0;

                while (num2 > 0)
                {
                    num3 = (num2 % 10);
                    num4 += num3;
                    num2 = num2 / 10;
                }

                pares += num4;
            }

        }
        else
        {
            impares += (numero % 10);
        }

        contador = i;

        numero = numero / 10;

        if ((numero < 100) && (numero > 10))
        {
            dezena = numero;
        }
    }

    total = pares + impares;

    check = total % 10;

    if (check == 0 && contador == 15 && (dezena == 34 || dezena == 37))
    {
        printf("AMEX\n");
    }
    else if (check == 0 && contador == 16 && (dezena >= 51 && dezena <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if (check == 0 && (contador == 13 || contador == 16) && ((dezena / 10) == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}