/**
 * problem6.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 6
 *
 * Finds the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int sumofsq = 0;
    int sum = 0;
    for (i = 1; i < 101; i++)
    {
        sumofsq += i * i;
        sum += i;
    }
    int sqofsum = sum * sum;
    int diff = sqofsum - sumofsq;
    printf("%d\n", diff);
    return 0;
}