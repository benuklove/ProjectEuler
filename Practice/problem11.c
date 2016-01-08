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
 * a 20 X 20 matrix.
 *
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
    printf("%d\n", total);
    
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
    printf("Greatest Diagonal negslope: %d\n", ns);
    
    // Positive slope
    
    
    /*
    printf("%d\n", mda[0][0]);
    printf("%d\n", mda[2][6]);
    printf("%d\n", mda[19][19]);
    printf("\n");
    */
    
    fclose(fp);
    return 0;
}

