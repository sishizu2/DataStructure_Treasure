#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int N[MAX] = {98, 140, 84, 28, 42, 126};

int gcd(int a, int b){
    int i;
    for(i = a; i > 0; i--){

        if(a % i == 0 && b % i == 0){
            break;
        }
    }
    return i;
}

int multi_gcd(int n){

    // n==1（数が2つしかない）の場合は、gcdを呼ぶだけ
    if(n == 1){
        return gcd(N[0], N[1]);
    }

    // n>1の場合は、N[n]とN[0]...N[n-1]のgcdを呼び出す
    return gcd(N[n], multi_gcd(n - 1));
}

int main(void){
    printf("Ansewer is %d\n", multi_gcd(MAX-1)); // MAX-1 is number of n
    return EXIT_SUCCESS;
}