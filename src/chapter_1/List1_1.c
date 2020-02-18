#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10    /* データ件数 */
int sort[N];

void BubbleSort(void){
    int i, j, flag;

    do{
        flag = 0;
        for(i=0; i<N; i++){
            /* 先頭から順にチェック */
            if(sort[i] > sort[i+1]){
                /* 左右の順がおかしければ入替 */
                flag = 1;
                j = sort[i];
                sort[i] = sort[i+1];
                sort[i+1] = j;
            }
        }
    }while(flag == 1);
}

int main(void){
    int i;

    srand((unsigned int)time(NULL));

    printf("Prepare:\n");
    for(i=0; i<N; i++){
        /* 配列にランダム値を格納 */
        sort[i] = rand();
        printf("%d ", sort[i]);
    }

    printf("\nStart:\n");
    BubbleSort();
    
    printf("\nEnd:\n");

    for(i=0;i<N;i++){
        printf("%d ",sort[i]);
    }

    return EXIT_SUCCESS;
}