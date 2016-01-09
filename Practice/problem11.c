/**
 * problem11.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 11
 *
 * Finds the greatest product of four adjacent numbers given
 * a 20 X 20 matrix (horizontally, vertically, or diagonally).
 *
 * Compile: gcc -o problem11 problem11.c -std=c99
 * Run: ./problem11 problem11.txt
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    // check for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: problem11 textfile\n");
        return 1;
    }
    
    // open text file
    char* text = argv[1];
    FILE* fp = fopen(text, "r");
    if (fp == NULL)
    {
        printf("Could not open %s.\n", text);
        return 1;
    }
    
    // read the file contents
    int nums[401];
    int index = 0;
    int num;
    while(fscanf(fp, "%2d", &num) > 0)
    {
        nums[index] = num;
        index++;
    }

    // assign to arrays of useful format
    int i;
    int mda[21][21];
    int count = 0;
    for (i = 0; i < 20; i++)
    {
        int j;
        for (j = 0; j < 20; j++)
        {
            mda[i][j] = nums[count];
            count++;
        }
    }
    
    /* Find greatest product of each direction  */
    // Vertical and Horizontal
    int v = 1, h = 1, total = 0;
    int j, tempv, temph;
    for (j = 0; j < 20; j++)
    {
        int k;
        for (k = 0; k < 17; k++)
        {
            int tempv = 1, temph = 1;
            int i;
            for (i = 0+k; i < 4+k; i++)
            {
                tempv *= mda[i][j];
                temph *= mda[j][i];
            }
            if (tempv > v)
            {
                v = tempv;
            }
            if (temph > h)
            {
                h = temph;
            }
            total += 1;
        }
    }
    printf("Greatest Vertical: %d\n", v);
    printf("Greatest Horizontal: %d\n", h);
    
    // Negative slope
    int ns = 1;
    int k, tempns;
    for (k = 0; k < 17; k++)
    {
        int j;
        for (j = 0+k; j < 4+k; j++)
        {
            int i;
            tempns = 1;
            for (i = 0+k; i < 4+k; i++)
            {
                tempns *= mda[i][j];
            }
            if (tempns > ns)
            {
                ns = tempns;
            }
        }
    }
    printf("Greatest Negative Slope Diagonal: %d\n", ns);
    
    // Positive slope
    int ps = 1;
    int stepi;
    int tempps;
    for (stepi = 0; stepi < 17; stepi++)
    {
        int stepj;
        for (stepj = 0; stepj < 17; stepj++)
        {
            tempps = 1;
            int i, j;
            for (i = 3+stepi, j = 0+stepj; i >= 0+stepi, j < 4+stepj; i--, j++)
            {
                tempps *= mda[i][j];
            }
            if (tempps > ps)
            {
                ps = tempps;
            }
        }
    }
    printf("Greatest Positive Slope Diagonal: %d\n", ps);

    // determine greatest of the four directions
    int prods[] = { v, h, ns, ps };
    int arri;
    int greatest = 1;
    for (arri = 0; arri < 4; arri++)
    {
        if (prods[arri] > greatest)
        {
            greatest = prods[arri];
        }
    }
    
    printf("Greatest product overall: %d\n", greatest);

    fclose(fp);
    return 0;
}

