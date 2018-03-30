#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

double Sin(double value)
{
    double result = 0;
    for(int i = 0; i < 16; i++)
        result += (Power(-1, i) * Power(value, 2 * i + 1)) / Factorial(2 * i + 1);

    return result;
}

double Cos(double value)
{
    double result = 0;
    for(int i = 0; i < 16; i++)
        result += (Power(-1, i) * Power(value, 2 * i)) / Factorial(2 * i);

    return result;
}


double Factorial(int value)
{
    int current = value;
    double result = 1;

    while(current > 0)
    {
        result *= current;
        current--;
    }

    return result;
}

double Power(double value, double power)
{
    int i = 0;
    double result = 1;
    while(i < power)
    {
        result *= value;
        i++;
    }

    return result;
}
