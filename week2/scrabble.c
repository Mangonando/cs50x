#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Array with points which will match the letters of the words
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate_value_word(string word);

int main(void)
{
    // Get word from player1 and player2
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Calculate value of the word. This is done with a function
    int score1 = calculate_value_word(player1);
    int score2 = calculate_value_word(player2);

    // Print winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Function to calculate the value of the word. It will be used after the the user prompt the word
// It needs to be added before main(void) too.
int calculate_value_word(string word)
{
    //Calculate and return value of the word
    //Store score
    int score = 0;

    //Calculate value of each character(loop)
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}