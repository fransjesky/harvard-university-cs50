#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float W = count_words(text);
    float L = count_letters(text);
    float S = count_sentences(text);

    L = L / W * 100.0;
    S = S / W * 100.0;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index > 16)
    {
        index = 16;
        printf("Grade %i+\n", (int) index);
    }
    else if (index < 1)
    {
        index = 1;
        printf("Before Grade %i\n", (int) index);
    }
    else
    {
        index = round(index);
        printf("Grade %i\n", (int) index);
    }

    return 0;
}

int count_letters(string text)
{
    float letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    int words = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}
