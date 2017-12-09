#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int num;
	scanf("%d",&num);
	int pal = ispal(num);
	if (pal == 0)
	{
		printf("It is a palindrome number!\n");
	}
	else
	{
		printf("It is not a palindrome number.\n");
	}
	
}

// Function to determine if a number of less than 11 digits is a palindrome
int ispal (int x)
{
	int n = x;
	int count = 0;
	// Get the total number of digits
	while(n != 0)
	{
		n = n / 10;
		count++;
	}
	
	// A power of 10 used below
	int values[count];
	int m = x;
	int last = count - 1;
	int mult = 1;
	int k;
	for (k = 1; k < count; k++ )
	{
	    mult *= 10;
	}
	
	// Filling the array "values" with scanf'd digits
	int i;
	for (i = 0; i < count; i++)
	{
	    values[i] = (m / mult) - ((m / mult) % 1);
	    m = m - (values[i] * mult);
	    mult /= 10;
	}
	
	// Palindrome test for even digit numbers
	if (count % 2 == 0)
	{
		int last = values[count - 1];
		int mid = count / 2;
		int total = 0;
		int j;
		for (j = 0; j < mid; j++)
		{
			total += abs((values[j] - values[count - 1 - j]));
		}
		return total;
	}
	
	// Palindrome test for odd digit numbers
	else
	{
	    int last = values[count - 1];
		int mid = (count - 1) / 2;
		int total = 0;
		int j;
		for (j = 0; j < mid; j++)
		{
			total += abs((values[j] - values[count - 1 - j]));
		}
		return total;
	}
}