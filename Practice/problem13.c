/**
 * problem13.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 13
 *
 * Finds the first ten digits of the sum of the 
 * specified one hundred 50-digit numbers.
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
        printf("Usage: problem13 textfile\n");
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
    long long int nums[5001];
    int index = 0;
    int num;
    while(fscanf(fp, "%1d", &num) > 0)
    {
        nums[index] = num;
        index++;
    }
    
    // put contents in useable format - multidimensional array
    int i;
    int mda[100][51];
    int count = 0;
    for (i = 0; i < 100; i++)
    {
        int j;
        for (j = 0; j < 50; j++)
        {
            mda[i][j] = nums[count];
            count++;
        }
    }
    
    // we only need the first x numbers of each line
    // (increase x for better accuracy)
    long int x = 11;
    long int temparr[100];
    for (i = 0; i < 100; i++)
    {
        int j;
        temparr[i] = 0;
        for (j = 0; j < x; j++)
        {
            temparr[i] = temparr[i] + mda[i][j];
            if (j < (x - 1))
            {
                temparr[i] = temparr[i] * 10;
            }
        }
    }
    
    // sum each element of the temp array
    long long int sum;
    for (i = 0; i < 100; i++)
    {
        sum += temparr[i];
    }
    printf("%lli\n", sum);
    
    fclose(fp);
    return 0;
}