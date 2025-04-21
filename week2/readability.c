#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters (string text);
int count_words (string text);
int count_sentences (string text);

int main(void)
{
    //Input text
    string text = get_string("Text: ");
    printf("Text: %s\n", text);

    // Count the number of letters
    int letters = count_letters(text);
    printf("Letters: %i\n", letters);
    // Count the number of words
    int words = count_words(text);
    printf("Words: %i\n", words);
    // Count the sentences
    int sentences = count_sentences(text);
    printf("Sentences: %i\n", sentences);
}

int count_letters (string text)
{
    // Variable to storage the count of the words
    int count_letters = 0;
    // Loop the string aka sentence
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count_letters ++;
        }
    }
    // Return number of letter in the text
    return count_letters;
}

int count_words (string text)
{
    // Variable to storage the count of the words
    int count_words = 0;
    // Count number of words in sentence
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            count_words ++;
        }
    }
    // Return number of words in text. Count spaces + 1
    return count_words + 1;
}

int count_sentences (string text)
{
    // Variable to storage the count of the sentences
    int count_sentences = 0;
    // Count number of sentences in text
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_sentences ++;
        }
    }
    // Return number of sentences in text. A sentence is any sequence of characters that ends with a . or a ! or a ? to be a sentence
    return count_sentences;
}
