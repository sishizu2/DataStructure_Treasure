#include <stdio.h>

void RoundError(){
    float f1, f2;
    f1 = 0.1f;
    f2 = 0.100000001f;

    printf("%20.18f \n%20.18f \n", f1, f2);
}

void main(void){
    RoundError();
}