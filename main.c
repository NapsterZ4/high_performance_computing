#include <stdio.h>
#include <math.h>

double *tSerial(double n[7]){
    static double result[7];

    for (int i = 0; i <= sizeof(result); ++i){
        result[i] = pow(n[i], 2.0);
    }

    for(int j = 0; j <= sizeof(result); ++j){
        printf("%f\n", result[j]);
    }

    return result;
}

int main(int argc,  char * argv[]) {
    //Napster
    double n[7] = {10.0, 20.0, 30.0, 40.0, 80.0, 160.0, 320.0};
    double p[8] = {1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0};

    double *tSerialResult = tSerial(n);

    for (int i=0; i < sizeof(tSerialResult); ++i){
        printf("%f\n", tSerialResult[i]);
    }

    return 0;
}
