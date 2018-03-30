#include <math.h>
#include <stdio.h>
#include "lib.h"

void FloatCalcEuler(FILE* file) {
    double lim = pow(10, 20);
    for (float i = 1; i <= lim; i *= 10) 
        fprintf(file, "%f %f\n", i, powf((1 + 1/i), i));
}

void DoubleCalcEuler(FILE* file) {
    double lim = pow(10, 20);
    for (double i = 1; i <= lim; i *= 10) 
        fprintf(file, "%lf %lf\n", i, pow((1 + 1/i), i));
}

void LDoubleCalcEuler(FILE* file) {
    double lim = pow(10, 20);
    for (long double i = 1; i <= lim; i *= 10) 
        fprintf(file, "%Lf %Lf\n", i, powl((1 + 1/i), i));
}
