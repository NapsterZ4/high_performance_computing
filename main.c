#include <stdio.h>
#include <math.h>

double *tSerial(double n[7]){
    static double resultSerial[7];

    for (int i = 0; i <= 7; ++i){
        resultSerial[i] = pow(n[i], 2.0);
    }

    return resultSerial;
}

double *tParallel(double p[8]){
    static double resultParallel[8];

    for (int i = 0; i <= 8; ++i){
        resultParallel[i] = pow(p[i], 2.0) / (pow(p[i], 2.0) / p[i] + log2(p[i]));
    }

    return resultParallel;
}

int main(int argc,  char * argv[]) {
    //Napster
    double n[7] = {10.0, 20.0, 30.0, 40.0, 80.0, 160.0, 320.0};
    double p[8] = {1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0};

    double *tSerialResult = tSerial(n);
    double *tParallelResult = tParallel(p);

    printf("********Serial Result*********\n");

    for (int i=0; i < 7; ++i){
        printf("%f\n", tSerialResult[i]);
    }

    printf("\n********Parallel Result***********\n");

    for (int i = 0; i < 8; ++i){
        printf("%f\n", tParallelResult[i]);
    }

    return 0;
}
