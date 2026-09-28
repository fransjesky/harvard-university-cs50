#include <cs50.h>
#include <stdio.h>

bool check_sum(long data);
int get_last_digit(long data);
int get_length(long data);
int get_first_two_digits(long data);

int main(void)
{
    long card_number = get_long("Number: ");
    if (check_sum(card_number))
    {
        int length = get_length(card_number);
        int identity = get_first_two_digits(card_number);

        if (length == 15 && (identity == 34 || identity == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (identity >= 51 && identity <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if (length == 13 || (length == 16 && identity / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool check_sum(long data)
{
    int multiplied_sum = 0;
    int non_multiplied_sum = 0;
    int total = 0;

    do
    {
        non_multiplied_sum += get_last_digit(data);
        data /= 10;

        int count = get_last_digit(data) * 2;

        if (count > 9)
        {
            multiplied_sum += count % 10;
            count /= 10;
            multiplied_sum += count;
        }
        else
        {
            multiplied_sum += count;
        }
        data /= 10;
    }
    while (data > 0);

    total = multiplied_sum + non_multiplied_sum;

    return total % 10 == 0;
}

int get_length(long data)
{
    int count = 0;

    do
    {
        count++;
        data /= 10;
    }
    while (data > 0);

    return count;
}

int get_first_two_digits(long data)
{
    do
    {
        data /= 10;
    }
    while (data > 99);

    return data;
}

int get_last_digit(long data)
{
    return data % 10;
}
