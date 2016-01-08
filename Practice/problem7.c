/**
 * problem7.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 7
 *
 * Finds the 10,001st prime
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int count = 1;
    long int i = 2;
    while (count < 10001)
    {
        // check for prime
        int j;
        int flag = 0;
        for (j = 2; j < i; j++)
        {
            if (j == i - 1)
            {
                flag = 1;
            }
            // If i is not evenly divisible by j
            if (i % j != 0)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (flag == 1)
        {
            count += 1;
        }
        i++;
    }
    i = i - 1;
    printf("%li is the %dth prime.\n", i, count);
    return 0;
}