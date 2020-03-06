#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int (*p[4]) (int x, int y);

int main(void){
    int result;
    int i, j, op;

    p[0] = sum;
    p[1] = subtract;
    p[2] = mul;
    p[3] = div;

    printf("input two numbers\n");
    scanf("%d%d", &i, &j);
    printf("0:add 1:subtract 2:mul 3:div");
    
    do{
        printf("number");
        scanf("%d", &op);
    }while((op < 0) || (op>3));

    result = (*p[op]) (i, j);
    printf("%d", result);

    return 0;
}

int sum(int a, int b){
    return a+b;
}
int subtract(int a, int b){
    return a - b;
}
int mul(int a, int b){
    return a*b;
}
int div(int a, int b){
    if(b) return a/b;
    else return 0;
}
