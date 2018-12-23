//
//  main.c
//  itoa_example
//
//  Created by Gal Argov on 22/12/2018.
//  Copyright © 2018 Gal Argov Sofer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_ITOA_ITERATION 5
#define MAX_BASE 32
#define MIN_BASE 2


void swap(char *x, char *y);
char* reverse(char *buffer, int i, int j);
char* itoa(int value, char* buffer, int base);

// implement itoa function in C
int main(void)
{
    char buffer[33];
    
    int value[] = { 11184810, -25, 64, 127, 13 };
    int base[]  = { 16, 10, 8, 2, 16 };
    
    for (int i = 0; i < NUMBER_OF_ITOA_ITERATION; i++)
    {
        printf("itoa(%d, buffer, %d) =\t\t%s\n", value[i], base[i], itoa(value[i], buffer, base[i]));
    }
    
    return 0;
}

// inline function to swap two numbers
void swap(char *x, char *y) {
    char t = *x; *x = *y; *y = t;
}

// function to reverse buffer[i..j]
char* reverse(char *buffer, int i, int j)
{
    while (i < j)
        swap(&buffer[i++], &buffer[j--]);
    
    return buffer;
}

// Iterative function to implement itoa() function in C
char* itoa(int value, char* buffer, int base)
{
    // invalid input
    if (base < MIN_BASE || base > MAX_BASE)
        return buffer;
    
    // consider absolute value of number
    int n = abs(value);
    
    int i = 0;
    while (n)
    {
        int r = n % base;
        
        if (r >= 10)
            buffer[i++] = 65 + (r - 10);
        else
            buffer[i++] = 48 + r;
        
        n = n / base;
    }
    
    // if number is 0
    if (i == 0)
        buffer[i++] = '0';
    
    // If base is 10 and value is negative, the resulting string
    // is preceded with a minus sign (-)
    // With any other base, value is always considered unsigned
    if (value < 0 && base == 10)
        buffer[i++] = '-';
    
    buffer[i] = '\0'; // null terminate string
    
    // reverse the string and return it
    return reverse(buffer, 0, i - 1);
}
