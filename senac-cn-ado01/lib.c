#include <stdio.h>
#include <string.h>
#include <math.h>
#include "lib.h"

int ConvertToDecimal(char value) {
    if (value >= '0' && value <= '9')
        return (int) value - '0';
    else 
        return (int) value - 'A' + 10;
}

int ConvertToBase(char *NumberToConvert, int BaseToConvert) {
    int i = 0, decimalValue = 0;
    for (i = 0; i < strlen(NumberToConvert); i++)
        decimalValue += ConvertToDecimal(NumberToConvert[strlen(NumberToConvert) - 1 - i]) * pow(BaseToConvert, i);

    return decimalValue;
}