#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            int rgbtGray = round((red + green + blue) / 3);

            image[i][j].rgbtRed = rgbtGray;
            image[i][j].rgbtGreen = rgbtGray;
            image[i][j].rgbtBlue = rgbtGray;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, h = height; i < h; i++)
    {
        int x = width - 1;

        for (int j = 0, w = (width / 2); j < w; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][x];
            image[i][x] = temp;

            x--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;
            int counter = 0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    if (((i + x) < 0) || ((i + x) >= h))
                    {
                        continue;
                    }

                    if (((j + y) < 0) || ((j + y) >= w))
                    {
                        continue;
                    }

                    sumRed += temp[i + x][j + y].rgbtRed;
                    sumBlue += temp[i +x][j + y].rgbtBlue;
                    sumGreen += temp[i +x][j + y].rgbtGreen;
                    counter++;
                }
            }

            image[i][j].rgbtRed = round(sumRed / counter);
            image[i][j].rgbtGreen = round(sumGreen / counter);
            image[i][j].rgbtBlue = round(sumBlue / counter);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            float GxRed = 0;
            float GxGreen = 0;
            float GxBlue = 0;
            float GyRed = 0;
            float GyGreen = 0;
            float GyBlue = 0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    if (((i + x) < 0) || ((i + x) >= h))
                    {
                        continue;
                    }

                    if (((j + y) < 0) || ((j + y) >= w))
                    {
                        continue;
                    }

                    GxRed += temp[i + x][j + y].rgbtRed * Gx[x + 1][y + 1];
                    GxGreen += temp[i + x][j + y].rgbtGreen * Gx[x + 1][y + 1];
                    GxBlue += temp[i + x][j + y].rgbtBlue * Gx[x + 1][y + 1];
                    GyRed += temp[i + x][j + y].rgbtRed * Gy[x + 1][y + 1];
                    GyGreen += temp[i + x][j + y].rgbtGreen * Gy[x + 1][y + 1];
                    GyBlue += temp[i + x][j + y].rgbtBlue * Gy[x + 1][y + 1];
                }
            }

            int red = round(sqrt(GxRed * GxRed + GyRed * GyRed));
            int green = round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            int blue = round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue));

            if (red > 255)
            {
                red = 255;
            }

            if (green > 255)
            {
                green = 255;
            }

            if (blue > 255)
            {
                blue = 255;
            }

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}
