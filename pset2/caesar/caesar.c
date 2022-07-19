#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool checarChave(string key);
string cifrarTexto(string s, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || checarChave(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string texto = get_string("plaintext: ");

        int k = atoi(argv[1]);

        string ciphertext = cifrarTexto(texto, k);

        printf("ciphertext: %s\n", ciphertext);

        return 0;
    }
}

bool checarChave(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            return true;
        }
    }

    return false;
}

string cifrarTexto(string s, int key)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
            {
                s[i] = ((((s[i] - 'a') + key) % 26) + 'a');
            }

            if (isupper(s[i]))
            {
                s[i] = ((((s[i] - 'A') + key) % 26) + 'A');
            }
        }
        else
        {
            s[i] = s[i];
        }
    }

    return s;
}
