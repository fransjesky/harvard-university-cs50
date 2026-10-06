#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int evaluate_score(string text);
int get_score(char letter);

int main(void)
{
    string player_one = get_string("Player 1: ");
    string player_two = get_string("Player 2: ");

    int one = evaluate_score(player_one);
    int two = evaluate_score(player_two);

    if (one == two)
    {
        printf("Tie!\n");
        return 0;
    }

    one > two ? printf("Player 1 wins!\n") : printf("Player 2 wins!\n");
    return 0;
}

int evaluate_score(string text)
{
    int score = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        score += get_score(text[i]);
    }

    return score;
}

int get_score(char letter)
{
    char c = tolower(letter);
    const int TOTAL_ALPHABETH = 26;
    const int SCORE[TOTAL_ALPHABETH] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                                        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    if (c >= 'a' && c <= 'z')
    {
        return SCORE[(int) c - (int) 'a'];
    }
    return 0;
}
