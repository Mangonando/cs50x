#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number;
    // Get a number(int) between 1 and 8
    do
    {
        number = get_int("Pick a number between 1 and 8: ");
    }
    while (number < 1 || number > 8);
    // Iterate over number
    for (int i = 0; i < number; i++)
    {
        // Iterate to get the space " " by doing a reverse pyramid. Starting with number and substract.
        for (int j = number - 1; j > i; j--)
        {
            printf(" ");
        }
        // Iterate to get #s from 0 to number
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        // Print "  " spaces between pyramids
        printf("  ");
        // Iterate to get new #s for the next pyramid
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        // Break each row after each iteration
        printf("\n");
    }
}