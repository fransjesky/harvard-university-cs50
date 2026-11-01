#include "helpers.h"
#include <math.h>

int convertValue(float color);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            int avg = (int)round((r + g + b) / 3.0);

            // Update pixel values
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
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
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            // Update pixel with sepia values
            image[i][j].rgbtRed = convertValue(sepiaRed);
            image[i][j].rgbtGreen = convertValue(sepiaGreen);
            image[i][j].rgbtBlue = convertValue(sepiaBlue);
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
            int n = j + 1;

            // Swap pixels
            int tRed = image[i][width - n].rgbtRed;
            int tGreen = image[i][width - n].rgbtGreen;
            int tBlue = image[i][width - n].rgbtBlue;

            image[i][width - n].rgbtRed = image[i][j].rgbtRed;
            image[i][width - n].rgbtGreen = image[i][j].rgbtGreen;
            image[i][width - n].rgbtBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = tRed;
            image[i][j].rgbtGreen = tGreen;
            image[i][j].rgbtBlue = tBlue;
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

    // getting the color from copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avgRed = 0;
            int avgGreen = 0;
            int avgBlue = 0;
            float count = 0.0;

            // loop for the neighboring pixels to get the average
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    if ((i + x) >= 0 && (i + x) < height && (j + y) >= 0 && (j + y) < width)
                    {
                        avgRed += copy[i + x][y + j].rgbtRed;
                        avgGreen += copy[i + x][y + j].rgbtGreen;
                        avgBlue += copy[i + x][y + j].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = convertValue(avgRed / count);
            image[i][j].rgbtGreen = convertValue(avgGreen / count);
            image[i][j].rgbtBlue = convertValue(avgBlue / count);
        }
    }
}

int convertValue(float color)
{
    int n = (int)round(color);

    if (n < 0)
        return 0;
    else if (n > 255)
        return 255;
    else
        return n;
}

