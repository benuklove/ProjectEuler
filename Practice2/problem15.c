/**
 * problem15.c
 *
 * Ben Love
 * benuklove@gmail.com
 * 
 * Project Euler
 * Problem 15
 *
 * Finds how many routes on a 20 X 20 grid
 * 
 * compile linking math
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int rows, columns;
    printf("Rows: ");
    scanf("%d", &rows);
    printf("Columns: ");
    scanf("%d", &columns);
    int nodes = (rows + 1) * (columns + 1);
    printf("Nodes: %d\n", nodes);
    
    int count = 0;
    int pathlength = rows + columns + 2;
    // somewhat arbitrary guess to be enough iterations:
    //int passes = nodes * (nodes - 1) * (nodes - 2) * (nodes - 3);
    int passes = nodes * nodes * nodes;
    int routes[passes][pathlength]; // = { 0 };
    while (passes > 0)
    {
        // initialize array
        int route[pathlength]; // = { 0 };
        int down = rows + 1;
        int right = 1;
        int current = nodes;
        int location = 0;
        int path = 1;
        while (current > 1)
        {
            // add 'current' to 'route' array, starting with, say, 16
            route[location] = current;
            srand48( 0.05 * path * time(NULL) );
            path = drand48() * 100000;
            printf("randpathnum: %i\n", path);
            if (path % 2 == 0)
            {
                if (current > rightendofmatrix(columns, nodes, current))
                {
                    current = current - right;
                }
                else
                {
                    current = current - down;
                }
                location++;
            }
            if (path % 2 != 0)
            {
                if (current > sqrt(nodes))
                {
                    current = current - down;
                }
                else
                {
                    current = current - right;
                }
                location++;
            }
        }
        if (isunique(routes, route, count, pathlength) == 0)
        {
            // add route to routes
            int i;
            for (i = 0; i < pathlength; i++)
            {
                routes[count][i] = route[i];
            }
            count++;
        }
        passes--;
    }
    printf("Number of unique routes: %d\n", count);
    return 0;
}

// function to determine appropriate row end element
int rightendofmatrix(columns, nodes, current)
{
    int end = nodes - columns;
    while (current < end)
    {
        end = end - columns;
    }
    return end;
}

// function to determine if route is unique
// returns 0 if the route is new, 1 if not
int isunique(int routes[][100], int route[], int count, int routelength)
{
    if (count == 0)
    {
        return 0;
    }
    else
    {
        int difference[routelength];
        int totaldiff = 0;
        int flag = 0;
        // compare the route to each route already stored
        int i;
        for (i = 0; i < count; i++)
        {
            // compare each member of the route
            int j;
            for (j = 0; j < routelength - 1; j++)
            {
                difference[j] = abs(route[j] - routes[i][j]);
                totaldiff += difference[j];
            }
            if (totaldiff == 0)
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            return 1;
        }
        if (flag == 0)
        {
            return 0;
        }
    }
}