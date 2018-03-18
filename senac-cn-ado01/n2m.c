#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char *argv[]) {
    if (argc < 4) { printf("Not enough parameters\n"); exit(1); }

    char* numberToConvert = argv[1];
    int numberBase = atoi(argv[2]);
    int baseToConvert = atoi(argv[3]);
    char* test = Convert(numberToConvert, numberBase, baseToConvert);
    printf("%s\n", test);
}
