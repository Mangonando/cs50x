#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Loop candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // if candidate matches
        if (strcmp(candidates[i], name) == 0)
        {
            //Store the index(i) inside ranks[]
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // loop candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // loop the candidates again and compare it to the candidate in the i loop
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Update the preferences
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Start count in 0
    pair_count = 0;

    // loop candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // loop the candidates again and compare it to the candidate in the i loop
        for (int j = i + 1; j < candidate_count; j++)
        {
            // Skip(continue if the candidate is the same)
            if (i == j)
            {
                continue;
            }
            // check if cnadidate i is prefered over j
            if (preferences[i][j] > preferences[j][i])
            {
                //Add pairs to pairs[]
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            // check if candidate j is prefered over i
            else if (preferences[j][i] > preferences[i][j])
            {
                //Add pairs to pairs[]
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Loop the pair_count
    for (int i = 0; i < pair_count; i++)
    {
        // big pair left. Starting on i then compare with the loop
        int max_index = i;

        // Loop the unsorted pairs left
        for (int j = i; j < pair_count; j++)
        {
            // Get big chances of winnint for current pair
            int big_j = preferences[pairs[j].winner][pairs[j].loser];
            // Get big chances of winnint for current max
            int big_max = preferences[pairs[max_index].winner][pairs[max_index].loser];

            // Update max index if curent pair is larger than current max
            if (big_j > big_max)
            {
                max_index = j;
            }
        }
        // Swap if a bigger pair appears
        if (max_index != i)
        {
            pair temp = pairs[i];
            pairs[i] = pairs[max_index];
            pairs[max_index] = temp;
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}
