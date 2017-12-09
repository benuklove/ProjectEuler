/**
 * problem1.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 1
 *
 * Finds the sum of all the multiples of 3 or 5 below 1000.
 *
 */
 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int i;
	int sum = 0;
    for (i = 1; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
    }
	printf("%d", sum);
	return 0;
}