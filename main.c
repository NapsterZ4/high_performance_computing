#include <stdio.h>
#include <math.h>

void *results(){
    double n[6] = {10.0, 20.0, 40.0, 80.0, 160.0, 320.0};
    double p[8] = {1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0};

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            double tserial = pow(n[i], 2.0);
            double tparallel = (pow(n[i], 2.0) / p[j]) + log2(p[j]);
            double speedup = tserial/tparallel;
            double effi = speedup/p[j];


            if (j == 0 && i == 0){
                printf("n,p,speedup,efficiency\n%f,%f,%f,%f\n", n[i], p[j], speedup, effi);
            } else {
                printf("%f,%f,%f,%f\n", n[i], p[j], speedup, effi);
            }
        }
    }
    return 0;
}


int main(int argc,  char * argv[]) {
    //Napster
    results();
    return 0;
}
