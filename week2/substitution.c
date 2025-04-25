#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool is_alphabetical(string s);

int main(int argc, string argv[])
{
    // Get key
    // NQXPOMAFTRHLZGECYJIUWSKDVB
    // Catch errors first with an if condition(argc and argv[])

    // Validate key
    if (argc != 2 || !is_alphabetical(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        //Check key length 26 chars. Key must contain 26 characters.
        printf("Key must contain 26 characters.\n");
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

//Check for chars for key
bool is_alphabetical(string s)
{
    // loop the chars in the string
    for (int i = 0; i < strlen(s); i++)
    {
        // Check for chars
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}