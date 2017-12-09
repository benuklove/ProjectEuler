/**
 * problem10.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 10
 *
 * Finds the sum of all primes below two million.
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Usage: remember to link with the flag -lm after filename.c

int main()
{
    long long int sum = 5;
    long int i;
    for (i = 3; i < 2000000; i++)
    {
        long int j;
        int flag = 0;
        int sroot = (int) sqrt(i);
        for (j = 2; j <= sroot; j++)
        {
            if (j == sroot)
            {
                flag = 1;
            }
            if (i % j == 0)
            {
                break;
            }
            if (flag == 1)
            {
                sum += i;
            }
        }
    }
    printf("sum is: %lli\n", sum);
    return 0;
}