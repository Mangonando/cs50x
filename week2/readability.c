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
    printf("%s\n", text);

    // Count the number of letters
    int letters = count_letters(text);
    // Count the number of words
    int words = count_words(text);
    // Count the sentences
    int sentences = count_sentences(text);
}

int count_letters (string text)
{
    // Return number of letter in the text
}

int count_words (string text)
{
    // Return number of words in text
}

int count_sentences (string text)
{
    // Return number of sentence in text
    // A sentence is any sequence of characters that ends with a . or a ! or a ? to be a sentence
}