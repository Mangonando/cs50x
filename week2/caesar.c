#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Program must run with only one command-line argument
    // Catch the error first
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    } else
    {
        // Get the 0 good to go for the program
        printf("Key is: %s\n", argv[1]);
        return 0;
    }
    //Input plainText
    // string plainText = get_string("plaintext:  ");
    // printf("plainText: %s\n", plainText);
}