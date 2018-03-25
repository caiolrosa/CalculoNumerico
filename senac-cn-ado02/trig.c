#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

int main() 
{
    FILE *file;
    if (!(file = fopen("seno.dat", "r")))
        file = fopen("seno.dat", "w");

    file = fopen("seno.dat", "a");
    for(int i = 0; i <= 720; i ++)
    {
        double angle = i*(PI/180);
        double absError = fabs(sin(angle) - Sin(angle));
        double relError = fabs(absError / Sin(angle));
        fprintf(file, "%d\t%f\t%f\t%f\n", i, Sin(angle), absError, relError);
    }
    fclose(file);

    if (!(file = fopen("cosseno.dat", "r")))
        file = fopen("cosseno.dat", "w");

    file = fopen("cosseno.dat", "a");
    for(int i = 0; i <= 720; i ++)
    {
        double angle = i*(PI/180);
        double absError = fabs(cos(angle) - Cos(angle));
        double relError = fabs(absError / Cos(angle));
        fprintf(file, "%d\t%f\t%f\t%f\n", i, Cos(angle), absError, relError);
    }

    fclose(file);

    FILE *plotFile = popen("gnuplot -persistent", "w");
    fprintf(plotFile, "%s\n%s", "set terminal png size 400,300\nset output 'seno.png'", "plot 'seno.dat'\n");
    fprintf(plotFile, "%s\n%s", "set terminal png size 400,300\nset output 'cosseno.png'", "plot 'cosseno.dat'");

    exit(0);
}
