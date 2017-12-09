/**
 * problem12.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 12
 *
 * Finds the value of the first triangle number to have
 * over five hundred divisors.
 * 
 * Output: The 12375th trinum is 76576500 and has 576 factors.
 * (After only twenty minutes!  Surely there's a faster way)
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    long int trinum;
    long int i = 10880;
    int factors = 0;
    while (factors < 501)
    {
        long int j = i;
        trinum = 0;
        while (j > 0)
        {
            trinum += j;
            j--;
        }
        long int k;
        factors = 0;
        for (k = trinum; k > 0; k--)
        {
            if (trinum % k == 0)
            {
                factors++;
            }
        }
        i++;
    }
    printf("The %lith trinum is %li and has %d factors.\n", i-1, trinum, factors);
}