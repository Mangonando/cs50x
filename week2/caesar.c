#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    // Program must run with only one command-line argument
    // Catch the error first
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    } else if (!only_digits(argv[1]))
    {
        printf("not only digits\n");
        return 1;
    }
    else
    {
        // Get the 0 good to go for the program
        printf("Key is: %s\n", argv[1]);
        return 0;
    }
    //Input plainText
    // string plainText = get_string("plaintext:  ");
    // printf("plainText: %s\n", plainText);
}

bool only_digits(string s)
{
    // loop the string. Use < instead of <= due to c asuming the last one is ./caesar
    for (int i = 0; i < strlen(s); i++)
    {
        // check if it is not as digit. handle error first
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    // Otherwise return true(outside the loop)
    return true;
}