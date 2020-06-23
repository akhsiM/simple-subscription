#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


string encipher(char key[], string plaintext);


int main(int argc, string argv[])
{

    // Check: only one CLA should be provided.
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Init error message to reuse later.
    string error = "Key must contain 26 non-repeated alphabetical character.\n";

    // Init variable `slen` to iterate through CLA[1] later.
    int slen = strlen(argv[1]);

    //First check: Check length = 26
    if (slen != 26)
    {
        printf("%s", error);
        return 1;
    }

    // Prepare for 2nd and 3rd check.
    // First, lowercase everything in CLA[1]. Store this in variable `key`.
    char key[slen];
    for (int i = 0, n = slen; i < n; i++)
    {
        key[i] = tolower(argv[1][i]);
    }

    // 2nd check: Check if `key` consists of only aphabetical letters.
    for (int i = 0, n = slen; i < n; i ++)
    {
        if ((key[i] < 97) || (key[i] > 122))
        {
            printf("%s", error);
            return 1;
        }
        // 3rd check: Check if any char repeats within `key`.
        for (int j = i + 1; j < n; j++)
        {
            if (key[i] == key[j])
            {
                printf("%s", error);
                return 1;
            }
        }
    }


    // Ask for plaintext input.
    string plaintext = get_string("plaintext: ");


    if (encipher(key, plaintext) == 0)
    {
        return 0;
    }
}

string encipher(char key[], string plaintext)
{


    // Init variables:
    // `n` to iterate encryption key later.
    // `n2` to iterate plain text string later.
    // `ciphertext` to store cipher text after encryption.
    int n = strlen(key);
    int n2 = strlen(plaintext);
    char ciphertext[n2];

    // Iterate through characters within encryption key and assign to variable `x`.
    // First character of key corresponds to ASCII 97 | 'a' and so on..
    for (int i = 0, j = 97; i < n; i++, j++)
    {
        char x = key[i];

        for (int z = 0; z < n2; z++)
        {
            // Iterate through characters within plaintext string and assign to variable `y`.
            int y = plaintext[z];

            if (y == j)
                // Handle lowercase.
                // If y == current ASCII position => match current key iteration.
            {
                ciphertext[z] = x;
            }
            else if (y == j - 32)
                // Handle uppercase.
                // If y == current ASCII position minus 32 (uppercase) => match current key iteration minus 32.
            {
                char u = x - 32;
                ciphertext[z] = u;
            }
            else if (y < 65 || (y > 90 && y < 97) || y > 122)
                // If y not in 65-90 or 97-122 range => match current plaintext iteration
            {
                ciphertext[z] = plaintext[z];
            }

        }
    }

    // Set result because `ciphertext` cannot be returned due to stack allocation error.
    string result = ciphertext;
    printf("ciphertext: %s\n", result);
    return 0;
}