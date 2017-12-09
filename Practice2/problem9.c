/**
 * problem9.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 9
 *
 * Finds the product abc where a < b < c and abc is a Pythagorean
 * triplet (a^2 + b^2 = c^2) whose sum a + b + c = 1000.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Usage: remember to link with the flag -lm after filename.c

int main(void)
{
    int a, b, c, aa, bb, cc;
    for (a = 3; a < 300; a++)
    {
        for (b = 4; b < 400; b++)
        {
            double c = sqrt(square(a) + square(b));
            if (a + b + c == 1000)
            {
                //printf("%d, %d, %f\n", a, b, c);
                aa = a;
                bb = b;
                cc = c;
                break;
            }
        }
    }
    int product = aa * bb * cc;
    printf("The product of a (%d), b (%d), and c (%d) is %d\n", aa, bb, cc, product);
    return 0;
}

// Function to square a number - just for fun
int square(x)
{
    int result = x * x;
    return result;
}