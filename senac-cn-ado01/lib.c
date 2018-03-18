#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"

int ConvertToDecimal(char value) {
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

char* Convert(char *NumberToConvert, int NumberBase, int BaseToConvert) {
    int i = 0, decimalValue = 0;

    if (NumberBase == BaseToConvert) { return NumberToConvert; }

    int len = strlen(NumberToConvert);
    for (i = 0; i < len; i++) 
    {
        int Value = (int)NumberToConvert[len - i - 1];
        decimalValue += ConvertToDecimal(Value) * pow(NumberBase, i);
    }

    char* convertedNumber = (char*) calloc(50, 50 * sizeof(char));
    int index = 0;
    while (decimalValue > 0) 
    {
        convertedNumber[index++] = ConvertToBase(decimalValue % BaseToConvert);
        decimalValue /= BaseToConvert;
    }
    convertedNumber[index] = '\0';

    int n = strlen(convertedNumber);
    for (i = 0; i < n/2; i++) 
    {
        char temp = convertedNumber[i];
        convertedNumber[i] = convertedNumber[n-i-1];
        convertedNumber[n-i-1] = temp;
    }

    return convertedNumber;
}
