#include <stdio.h>
#include <math.h>
#include "lib.h"

enum DataType
{
    FLOAT = 0,
    DOUBLE = 1,
    LDOUBLE = 2
};

int main() {
    char* fileNames[3] = { "euler_flt.png", "euler_dbl.png", "euler_ldbl.png" };
    FILE* gnuFiles[3] = {
        popen("gnuplot -persistent", "w"),
        popen("gnuplot -persistent", "w"),
        popen("gnuplot -persistent", "w")
    };

    for (int i = 0; i < 3; i++)
    {
        fprintf(gnuFiles[i], "set terminal png\n");
        fprintf(gnuFiles[i], "set output '%s'\n", fileNames[i]);
        fprintf(gnuFiles[i], "set logscale x\n");
        fprintf(gnuFiles[i], "set title 'Euler number for float type'\n");
        fprintf(gnuFiles[i], "set xlabel 'n'\n");
        fprintf(gnuFiles[i], "set ylabel 'Euler'\n");
        fprintf(gnuFiles[i], "set nokey\n");
        fprintf(gnuFiles[i], "set tic scale 0\n");
        fprintf(gnuFiles[i], "set grid ytics\n");
        fprintf(gnuFiles[i], "set yrange [0:3.5]\n");
        fprintf(gnuFiles[i], "plot '-' w l\n");
    }

    FloatCalcEuler(gnuFiles[FLOAT]);
    fprintf(gnuFiles[FLOAT], "e");
    
    DoubleCalcEuler(gnuFiles[DOUBLE]);
    fprintf(gnuFiles[DOUBLE], "e");

    LDoubleCalcEuler(gnuFiles[LDOUBLE]);
    fprintf(gnuFiles[LDOUBLE], "e");

    for (int i = 0; i < 3; i++) {
        pclose(gnuFiles[i]);
    }

    return 0;
}
