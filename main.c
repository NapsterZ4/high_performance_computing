#include <stdio.h>
#include "math.h"

int tamArray(int n[]){
    size_t a = (int) (sizeof(n) - 1);
    return a;
}

int tSerial(int n[]){
    int tam = tamArray(n);

    for (int i = 0; i <= tam; ++i){

    }
}

int main(int argc,  char * argv[]) {
    int n[6] = {10, 20, 30, 40, 80, 160, 320};
    int p[6] = {1,2,4,8,16,32,64,128};
    tSerial(n);
    return 0;
}