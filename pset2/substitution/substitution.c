#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool checarChave(string key);
string cifrarTexto(string text, string key);

int main(int argc, string argv[])
{
    if (argc != 2) // Se o argumento não for informado, informa erro.
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    if (!checarChave(argv[1]))
    {
        string plaintext = get_string("plaintext: "); // Solicita a entrada do texto a ser criptografado.

        string ciphertext = cifrarTexto(plaintext, argv[1]);

        printf("ciphertext: %s\n", ciphertext);

        return 0;
    }
    else
    {
        return 1;
    }
}

bool checarChave(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // Valida se a chave informada contém somente letras e não possui letras repetidas.
            if (!isalpha(key[i]) || (key[j] == key[i]))
            {
                printf("Usage: ./substitution KEY\n");
                return 1;
            }
            // Valida se a chave informada tem um tamanho diferente de 26.
            else if (n != 26)
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
        }
    }

    return 0;
}

string cifrarTexto(string text, string key)
{
    string s = text;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Substitui a letra pela correspondente à posição da chave de criptografia.
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
            {
                s[i] = tolower(key[s[i] - 'a']);
            }
            else if (isupper(s[i]))
            {
                s[i] = toupper(key[s[i] - 'A']);
            }
        }
        else // Se não for letra, não substitui.
        {
            s[i] = text[i];
        }
    }

    return s;
}