#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    while (true)
    {
        height = get_int("How tall the pyramid? ");
        if (height > 0)
        {
            break;
        }
    }

    for (int i = height; i > 0; i--)
    {
        // left side
        for (int left = 0; left < height; left++)
        {
            if (left < i - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        // mid side
        printf("  ");

        // right side
        for (int right = 0; right < height; right++)
        {
            if (!(right < i - 1))
            {
                printf("#");
            }
        }

        // breakline
        printf("\n");
    }
}
