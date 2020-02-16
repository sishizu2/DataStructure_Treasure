#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10    /* データ件数 */
int sort[N];

int main(void){
    int i;

    srand((unsigned int)time(NULL));

    printf("ソート準備:\n");
    for(i=0; i<N; i++){
        /* 配列にランダム値を格納 */
        sort[i] = rand();
        printf("%d ", sort[i]);
    }

    printf("\nソート開始:\n");
    BubbleSort();

    printf("\nソート終了:\n");

    for(i=0;i<N;i++){
        printf("%d ",sort[i]);
    }

    return EXIT_SUCCESS;
}