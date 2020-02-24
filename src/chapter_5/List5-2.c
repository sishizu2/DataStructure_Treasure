#include <stdio.h>
#include <stdlib.h>

int num_of_one(unsigned long value){
    
    int ret;

    // Valueが0桁 これ以上解析する桁がない
    if(value==0){
        return 0;
    }

    if(value % 10 == 1){
        ret = 1;
    }else{
        ret = 0;
    }

    // 10で割って桁を1つずらし、再びnum_of_one()で調べる
    return ret + num_of_one(value / 10);

}

// 三項演算子[?]を使えば、再帰版num_of_one以下のように書ける
int num_of_oneL(unsigned long value){
    if(value==0){
        return 0;
    }

    return ( ((value % 10) == 1) ? 1:0) + num_of_one(value / 10);
}

int main(void){
    int i;

    scanf("%d", &i);
    printf("%d has %d of 1\n", i, num_of_oneL(i));

    // printf("\n%d", 10/10000); == 0

    return EXIT_SUCCESS;
}