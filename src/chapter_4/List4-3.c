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

int main(void){
    char buffer[256];

    double cal1, cal2;

    int i;

    do{
        printf("current stack ( %d )", stack_top);

        for(i=0; i<stack_top; i++){
            printf("%0.3f", stack[i]);
        }

        printf("\n>");
        gets(buffer);
        switch(buffer[0]){
            case '+':
                cal1 = stack_pop();
                cal2 = stack_pop();
                stack_push(cal2 + cal1);
                break;
            case '-':
                cal1 = stack_pop();
                cal2 = stack_pop();
                stack_push(cal2 - cal1);
                break;
            case '*':
                cal1 = stack_pop();
                cal2 = stack_pop();
                stack_push(cal2 * cal1);
                break;
            case '/':
                cal1 = stack_pop();
                cal2 = stack_pop();
                stack_push(cal2 / cal1);
                break;
            case '=':
                break;
            default:
                stack_push(atoi(buffer));
                break;
        }
    }while(buffer[0] != '=');

    printf("result is %f \n", stack_pop());

    if(stack_top != 0){
        printf("number still left");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
