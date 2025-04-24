#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Program must run with only one command-line argument
    // Catch the error first
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // convert string to integer
    int key = atoi(argv[1]);

    //Input plainText
    string plainText = get_string("plaintext:  ");

    printf("ciphertext: ");

    // Loop the integer and convert the plaintext to the cypher(rotate function) char by char
    for (int i = 0; i < strlen(plainText); i++)
    {
        // Use rotate function and print cypher text here
        printf("%c", rotate(plainText[i], key));
    }
    printf("\n");
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

// Encrypt message here. c is char. n will be the key
char rotate(char c, int n)
{
    // Checking if it is uppercase letter, then lowercase, and lastly left the non letter char untouched
    if (isupper(c))
    {
        return ((c - 'A' + n) % 26) + 'A';
    }
    else if (islower(c))
    {
        return ((c - 'a' + n) % 26) + 'a';
    }
    else
    {
        return c;
    }
}