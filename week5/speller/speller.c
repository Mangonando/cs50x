// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// count loaded words
static unsigned int words_in_dict = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // return false if word is not in the dictionary
    if (word == NULL)
    {
        return false;
    }
    // hash word to get hash value
    unsigned int idx = hash(word);
    // traverse list looking for the word. strcasecmp
    node *cursor = table[idx];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // empty bucket
    if (word == NULL || word[0] == '\0')
    {
        return 0;
    }
    // hash by first letter aka char
    unsigned char c = (unsigned char) tolower((unsigned char) word[0]);
    if (c >= 'a' && c <= 'z')
    {
        return (unsigned int)(c - 'a');
    }
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open dict file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }
    // read strings from file one at a time
    char storage[LENGTH + 1];
    while (fscanf(source, "%45s", storage) == 1)
    {
        // new node use malloc
        node *n = malloc(sizeof(node));
        // check if return value is NULL
        if (n == NULL)
        {
            fclose(source);
            return false;
        }
        // copy word into node
        int i = 0;
        while (storage[i] != '\0' && i < LENGTH)
        {
            n->word[i] = (char) tolower((unsigned char) storage[i]);
            i++;
        }
        n->word[i] = '\0';
        // hash word: hash function. takes a string and return an index
        unsigned int idx = hash(n->word);
        // insert node into bash table at that location
        n->next = table[idx];
        table[idx] = n;

        // count words
        words_in_dict++;
    }
    // return true if date was loaded successfully
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words_in_dict;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // i for buckets
    unsigned int i = 0;
    // lopp each bucket
    while (i < N)
    {
        // pointer to first node
        node *current_node = table[i];
        // traverse linked list
        while (current_node != NULL)
        {
            // remember next before free actual
            node *next = current_node->next;
            free(current_node);
            current_node = next;
        }
        table[i] = NULL;
        i++;
    }
    return true;
}
