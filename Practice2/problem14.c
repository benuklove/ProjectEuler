/**
 * problem14.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 14
 *
 * Finds the starting number, under one million, that produces
 * the longest chain of numbers using the Collatz sequence:
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    // iterative starting number, i; final starting number, start
    long long int i, n, start;
    long int terms = 1;
    for (i = 1; i < 1000000; i++)
    {
        long int count = 1;
        n = i;
        while (n > 1)
        {
            if (n % 2 == 0)
            {
                n = n / 2;
                count++;
            }
            else
            {
                n = 3 * n + 1;
                count++;
            }
        }
        if (count > terms)
        {
            terms = count;
            start = i;
        }
    }
    printf("Starting at %lli yields %li terms.\n", start, terms);
    return 0;
}