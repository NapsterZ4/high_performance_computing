#include <stdio.h>
#include <math.h>
#include <string.h>

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

/*
void * createFile(tSerial, tParallel){
    FILE *fps = fopen("serial.txt", "w");

    for (int i = 0; i < 7; ++i){
        fprintf(fps, tSerial[i]);
    }

    fclose(fps);

    FILE *fpp = fopen("parallel.txt", "w");
    fprintf(fpp, tParallel);
    fclose(fpp);
    return 0;
}
*/

void *results(double serial[], double parallel[]){
    printf("******** Serial Result *********\n");


    for (int i=0; i < 7; ++i){
        printf("%d %f\n", i+1, serial[i]);
    }

    printf("\n******** Parallel Result ***********\n");

    for (int i=0; i < 8; ++i){
        printf("%d %f\n", i+1, parallel[i]);
    }
}

int main(int argc,  char * argv[]) {
    //Napster
    double n[7] = {10.0, 20.0, 30.0, 40.0, 80.0, 160.0, 320.0};
    double p[8] = {1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0};

    double *tSerialResult = tSerial(n);
    double *tParallelResult = tParallel(p);

    results(tSerialResult, tParallelResult);

    //createFile(tSerialResult, tParallelResult);

    //FILE *fps = fopen("serial.txt", "w");
/*
    char serialArray[100] = "";

    for (int i = 0; i < 7; ++i){
        serialArray[i] = tSerialResult[i];
        printf("Serial %c", serialArray[i]);
    }
*/

    return 0;
}
