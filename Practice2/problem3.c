/**
 * problem3.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 3
 *
 * Finds the largest prime factor of the number 600851475143.
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	unsigned long long int bignum = 600851475143;
	long int i;
	long int largestprime;
	// check if each number, i, is a factor of the big number
	long int stopat = 1000000000;
	for (i = 2; i < stopat; i++)
	{
		if (bignum % i == 0)
		{
			long int j;
			// check if each factor is prime
			int flag = 0;
			for (j = 2; j < i; j++)
			{
				if (i % j == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
			    largestprime = i;
			}
		}
	}
	printf("Largest prime factor: %li\n", largestprime);
	return 0;
}