#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid(int n, string str);
bool has_duplicated(int n, string str);

int main(int argc, string argv[])
{
    const int NUMBER_LETTERS = 26;
    int key_length;

    if (argc > 1)
    {
        key_length = strlen(argv[1]);
    }

    // basic validation
    if (argc == 1 || argc > 2 || key_length < NUMBER_LETTERS)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // check if the key is valid
    if (!is_valid(NUMBER_LETTERS, argv[1]))
    {
        printf("Key is invalid!\n");
        return 1;
    }

    // check if the key got duplicated character
    if (has_duplicated(NUMBER_LETTERS, argv[1]))
    {
        printf("Key is duplicated!\n");
        return 1;
    }

    // core logic
    string input = get_string("plaintext: ");
    char output[strlen(input)];

    for (int i = 0, n = strlen(input); i <= n; i++)
    {
        if (isalpha(input[i]))
        {
            // check if its uppercase letter
            if (input[i] >= 'A' && input[i] <= 'Z')
            {
                output[i] = toupper(argv[1][tolower(input[i]) - 'a']);
            }
            else
            {
                output[i] = tolower(argv[1][tolower(input[i]) - 'a']);
            }
        }
        else
        {
            output[i] = input[i];
        }
    }

    printf("ciphertext: ");
    for (int i = 0, n = strlen(output); i < n; i++)
    {
        printf("%c", output[i]);
    }
    printf("\n");
    return 0;
}

bool is_valid(int n, string str)
{
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}

bool has_duplicated(int n, string str)
{
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[tolower(str[i]) - 'a']++;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 1)
        {
            return true;
        }
    }
    return false;
}
