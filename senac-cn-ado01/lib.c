#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"

int ConvertCharToDecimal(char value) {
    if (value >= '0' && value <= '9') 
        return (int) value - '0';
    else
        return (int) value - 'A' + 10;
}

char ConvertToBase(int value) {
    if (value >= 0 && value <= 9)
        return (char)(value + '0');
    else
        return (char)(value - 10 + 'A');
}

long int Power(int value, int power) {
    long int response = 1;
    for (int i = 0; i < power; i++)
        response *= value;

    return response;
}

long int ConvertToDecimal(char* value, int NumberBase) {
    int len = strlen(value);
    long int decimalValue = 0;
    for (int i = 0; i < len; i++) 
    {
        int Value = (int)value[len - 1 - i];
        decimalValue += ConvertCharToDecimal(Value) * Power(NumberBase, i);
    }

    return decimalValue;
}

char* Convert(long int NumberToConvert, int BaseToConvert) {
    char* convertedNumber = (char*) calloc(10000, 10000 * sizeof(char));
    int index = 0;
    while (NumberToConvert > 0) 
    {
        convertedNumber[index++] = ConvertToBase(NumberToConvert % BaseToConvert);
        NumberToConvert /= BaseToConvert;
    }
    convertedNumber[index] = '\0';

    int n = strlen(convertedNumber);
    for (int i = 0; i < n/2; i++) 
    {
        char temp = convertedNumber[i];
        convertedNumber[i] = convertedNumber[n-i-1];
        convertedNumber[n-i-1] = temp;
    }

    return convertedNumber;
}
