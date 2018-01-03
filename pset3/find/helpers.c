/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //return false if no values in array
    if(n <= 0)
    {
        return false;
    }
    
    //initalize and declare points of interest in the array
    int middle;
    int end = n - 1;
    int start = 0;
    
    //searches through the array to find value
    while(start <= end)
    {
        middle = (start + end) / 2;
        
        if(values[middle] == value)
        {
            return true;
        }
        else if(values[middle] < value)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }
    // return false if value not found in while loop
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int min;
    int place;
    int consider;
    
    for(int i = 0; i <= n - 2; i++)
    {
        min = values[i];
        consider = values[i];
        
        for(int a = i + 1; a <= n - 1; a++)
        {
            if(values[a] < min)
            {
                min = values[a];
                place = a;
            }
        }
        
        if(min != values[i])
        {
            values[i] = min;
            values[place] = consider;
        }
    }
    return;
}
