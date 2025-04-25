#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool is_alphabetical(string s);
bool has_duplicates(string s);

int main(int argc, string argv[])
{
    // Get key
    // NQXPOMAFTRHLZGECYJIUWSKDVB
    // Catch errors first with an if condition(argc and argv[])

    // Validate key
    if (argc != 2 || !is_alphabetical(argv[1]) || has_duplicates(argv[1]))
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

// Check for duplicate chars for key.
bool has_duplicates(string s)
{
    // Create an array to compare with the key. it will be used as a checklist to compare both keys
    bool new_key_arr[26] = { false };
    for (int i = 0; i < strlen(s); i++)
    {
        // To make comparison and case insensitive
        char c = toupper(s[i]);
        // convert char to array index
        int index = c - 'A';
        // Check for duplicate
        if (new_key_arr[index])
        {
            return true;
        }
        // mark char as seen
        new_key_arr[index] = true;
    }
    return false;
}