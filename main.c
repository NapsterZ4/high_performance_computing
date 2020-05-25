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

double *speedup(double *serial, double *parallel){
    static double resultSpeedup[8];

    for (int i = 0; i <= 8; ++i){
        resultSpeedup[i] = serial[i] / parallel[i];
    }
}

double *efficiency(double *speedup, double *p){
    static double resultEfficiency[8];

    for (int i = 0; i <= 8; ++i){
        resultEfficiency[i] = speedup[i] / p[i];
    }
}

void *printResults(double *serial, double *parallel, double *speedup, double *efficiency){
    printf("******** Serial Result *********\n");

    for (int i=0; i < 7; ++i){
        printf("%d %f\n", i+1, serial[i]);
    }

    printf("\n******** Parallel Result ***********\n");

    for (int i=0; i < 8; ++i){
        printf("%d %f\n", i+1, parallel[i]);
    }

    printf("\n******** Speedup ***********\n");

    for (int i=0; i < 8; ++i){
        printf("%d %f\n", i+1, speedup[i]);
    }

    printf("\n******** Efficiency ***********\n");

    for (int i=0; i < 8; ++i){
        printf("%d %f\n", i+1, efficiency[i]);
    }

    return 0;
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

int main(int argc,  char * argv[]) {
    //Napster
    double n[7] = {10.0, 20.0, 30.0, 40.0, 80.0, 160.0, 320.0};
    double p[8] = {1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0};

    double *tSerialResult = tSerial(n);
    double *tParallelResult = tParallel(p);
    double *speedupResult = speedup(tSerialResult, tParallelResult);
    double *efficiencyResult = efficiency(speedupResult, p);

    printResults(tSerialResult, tParallelResult, speedupResult, efficiencyResult);

/*
    createFile(tSerialResult, tParallelResult);

    FILE *fps = fopen("serial.txt", "w");
    char serialArray[100] = "";

    for (int i = 0; i < 7; ++i){
        serialArray[i] = tSerialResult[i];
        printf("Serial %c", serialArray[i]);
    }
*/

    return 0;
}
