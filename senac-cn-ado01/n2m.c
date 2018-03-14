#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char *argv[]) {
    char* numberToConvert = argv[1];
    int baseToConvert = atoi(argv[2]);
    int test = ConvertToBase(numberToConvert, baseToConvert);
    printf("%d\n", test);
}