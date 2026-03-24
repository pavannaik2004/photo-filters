#include "helpers.h"
#include <math.h>
#include<stdio.h>

// Flags for colors
int red = 1, blue = 2, green = 3;

// Function prototype
int get_average(int i, int j, int color, int height, int width, RGBTRIPLE image[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;
    //Going through every pixle
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //printf("%i\t%i\t%i", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
            average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            //printf("\n%f\n", average);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Swaping extreme side of a row
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2 ; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE replica[height][width];

    // Coping image into replica
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            replica[row][column] = image[row][column];
        }
    }

    // Calculate Average for box blur
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = get_average(i, j, red, height, width, replica);
            image[i][j].rgbtGreen = get_average(i, j, green, height, width, replica);
            image[i][j].rgbtBlue = get_average(i, j, blue, height, width, replica);
        }
    }
    return;
}

// To calulate the average of 9 pixles
int get_average(int i, int j, int color, int height, int width, RGBTRIPLE image[height][width])
{
    int color_sum = 0;
    float pxl_count = 0.0;

    // Going through all 8 pixles surrounding pixel of each pixel
    for (int row = i - 1; row <= i + 1; row++)
    {
        for (int column = j - 1; column <= j + 1; column++)
        {
            // Skipping pixles at edge and corner
            if (row < 0 || row >= height || column < 0 || column >= width)
            {
                continue;
            }

            pxl_count++;

            // Calculating sum of box for each pixle
            if (color == 1)
            {
                color_sum += image[row][column].rgbtRed;
            }
            else if (color == 3)
            {
                color_sum += image[row][column].rgbtGreen;
            }
            else
            {
                color_sum += image[row][column].rgbtBlue;
            }
        }
    }
    // Getting average
    float average = round(color_sum / pxl_count);
    return average;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    //Copy image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int sepia_red, sepia_blue, sepia_green;

    // Calculating sepia color for each color in a pixle
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepia_red = round(.393 * copy[i][j].rgbtRed + .769 * copy[i][j].rgbtGreen + .189 * copy[i][j].rgbtBlue);
            sepia_green = round(.349 * copy[i][j].rgbtRed + .686 * copy[i][j].rgbtGreen + .168 * copy[i][j].rgbtBlue);
            sepia_blue = round(.272 * copy[i][j].rgbtRed + .534 * copy[i][j].rgbtGreen + .131 * copy[i][j].rgbtBlue);

            //Capping value to 255
            image[i][j].rgbtRed = sepia_red > 255 ? 255 : sepia_red;
            image[i][j].rgbtGreen = sepia_green > 255 ? 255 : sepia_green;
            image[i][j].rgbtBlue = sepia_blue > 255 ? 255 : sepia_blue;
        }
    }
    return;
}
