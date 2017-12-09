/**
 * problem5.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 5
 *
 * Finds the smallest positive number that is
 * evenly divisible by all of the numbers from 1 to 20.
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    long int i, spn;
    int j;
    for (i = 2520; i < 2000000000; i = i + 2)
    {
        int flag = 0;
        for (j = 2; j < 21; j++)
        {
            if (i % j == 0 && j == 20)
            {
                flag = 1;
            }
            if (i % j != 0)
            {
                break;
            }
            if (i % j == 0 && j < 20)
            {
                continue;
            }
            if (flag == 1)
            {
                spn = i;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    printf("%li is the smallest.\n", spn);
    return 0;
}