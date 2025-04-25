#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Get key
    // NQXPOMAFTRHLZGECYJIUWSKDVB
    // Catch errors first with an if condition(argc and argv[])

    // Validate key
    // Check key length 26 chars.
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Check non-alphabetical chars
    // No repetition of chars(case insensitive)

    // Get plaintext good old get_string

    // Encipher
    // Map and check which letter from the key should map the letter
    // Keep case
    // Leave non-alphabetical chars as it is

    // Print ciphertext
}