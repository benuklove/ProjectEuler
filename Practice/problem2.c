/**
 * problem2.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 2
 *
 * For Fibonacci sequence terms below four million,
 * this finds the sum of the even-valued terms.
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int a, b;
	int first = 1;
	int sum = 0;
	int next = 2;
	while (next < 4000000)
	{
		if (next % 2 == 0)
		{
			sum += next;
		}
		next = first + next;
		first = next - first;
	}	
	printf("%d", sum);
	return 0;
}