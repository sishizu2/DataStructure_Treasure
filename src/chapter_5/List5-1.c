#include <stdio.h>
#include <stdlib.h>

int num_of_one(int value){

    int ret;
    // valueを次々に10で割って桁をずらし、最下位の桁が1か調べる

    for(ret = 0; value > 0; value /= 10){
        
        if(value % 10 == 1){
            ret++;
        }
    }
    return ret;
}

int main(void){
    int i;

    scanf("%d", &i);
    printf("%d has %d of 1\n", i, num_of_one(i));
    return EXIT_SUCCESS;
}