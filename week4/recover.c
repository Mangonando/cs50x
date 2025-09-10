#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // While there's still data left to read from the memory card
    // Read 512 bytes into a buffer

    // Create JPEGs from the data
    // If start of new jpeg
    // If jpeg
    // Else

    // Else
    // If already found jpeg
}