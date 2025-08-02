#include "helpers.h"
#include <math.h>

// Helper. Cap value at 255

#define MAX_COLOR 255

static BYTE cap(int val)
{
    if (val > MAX_COLOR)
    {
        return MAX_COLOR;
    }
    return (BYTE) val;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            float avg = (image[i][j].rgbtRed
                         + image[i][j].rgbtGreen
                         + image[i][j].rgbtBlue) / 3.0;

            //Round the int
            BYTE gray = (BYTE) round(avg);

            // Update pixel values
            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            int sepiaRed = (int) round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = (int) round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = (int) round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // Update pixel with sepia values
            image[i][j].rgbtRed = cap(sepiaRed);
            image[i][j].rgbtGreen = cap(sepiaGreen);
            image[i][j].rgbtBlue = cap(sepiaBlue);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Loop each pixel(2 loops)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 0;

            // Check neighbors in each direction
            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    int neighborRow = i + row;
                    int neighborCol = j + col;

                    // If neighbor is in the box keep it
                    if (neighborRow >= 0 && neighborRow < height && neighborCol >= 0 && neighborCol < width)
                    {
                        sumRed += copy[neighborRow][neighborCol].rgbtRed;
                        sumGreen += copy[neighborRow][neighborCol].rgbtGreen;
                        sumBlue += copy[neighborRow][neighborCol].rgbtBlue;
                        count++;
                    }
                }
            }
            // Compute and round the average
            image[i][j].rgbtRed = (BYTE) round((float)sumRed / count);
            image[i][j].rgbtGreen = (BYTE) round((float)sumGreen / count);
            image[i][j].rgbtBlue = (BYTE) round((float)sumBlue / count);
        }
    }
}
