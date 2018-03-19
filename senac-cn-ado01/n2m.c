#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char *argv[]) {
    if (argc < 4) { printf("Not enough parameters\n"); exit(1); }

    char* numberToConvert = argv[1];
    int numberBase = atoi(argv[2]);
    int baseToConvert = atoi(argv[3]);

    if (numberBase < 2 || numberBase > 36) { printf("number base is outside the acceptable range.\n"); exit(1); }
    if (baseToConvert < 2 || baseToConvert > 36) { printf("base to convert is outside the acceptable range.\n"); exit(1); }

    long int decimalNumber = ConvertToDecimal(numberToConvert, numberBase);
    if (decimalNumber == 0) { printf("%d\n", 0); exit(0); }
    if (decimalNumber < 0 || decimalNumber > Power(2, 32)) { printf("Number is not between 0 and pow(2,32).\n"); exit(1); };
    printf("%s\n", Convert(decimalNumber, baseToConvert));

    exit(0);
}
