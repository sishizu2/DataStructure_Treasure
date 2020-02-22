#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 10

// double型格納スタック
double stack[STACK_MAX];

// スタック頂上の位置（最下部からのオフセット）
int stack_top = 0;

// スタックへpush
void stack_push(double val){

    if(stack_top == STACK_MAX){
        // スタック満杯
        printf("stack is full");
        exit(EXIT_FAILURE);
    }else{
        // スタック空き有　渡された値をスタックに積む
        stack[stack_top] = val;
        stack_top++;
    }
}

// pop
double stack_pop(void){
    if(stack_top == 0){
        // nothing in stack
        printf("stack is empty");
        exit(EXIT_FAILURE);
        return 0;
    }else{
        // 一番上の値を出す
        stack_top--;
        return stack[stack_top];
    }
}

