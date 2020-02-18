#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define N 10    /* データ件数 */
#define N 6

int sort[N];

void CombSort(void){
    int i, temp, flag, gap;
    gap = N;

    do{
        gap = (gap * 10)/13;
        // 収縮率は1.3
        if(gap==0){
            gap=1;
        }

        flag=1;

        // 先頭から順に見る
        for(i=0; i<N-gap; i++){
            // 距離がGAP分離れた要素を比較
            if(sort[i] > sort[i+gap]){
                // 並びが逆であれば入替
                flag=0;
                temp=sort[i];
                sort[i]=sort[i+gap];
                sort[i+gap]=temp;
            }
        }

        for(i=0;i<N;i++){
            printf("\n");
            printf("%d ",sort[i]);
        }

    // 一度も並べ替えせずGAP=1で見終われば終了
    }while((gap>1) || flag != 1);
}

int main(void){
    
    int i;

    srand((unsigned int)time(NULL));

    printf("ソート準備:\n");
    for(i=0; i<N; i++){
        /* 配列にランダム値を格納 */
        sort[i] = rand();
        printf("%d ", sort[i]);
    }

    // 531246

    sort[0]=5;
    sort[1]=3;
    sort[2]=1;
    sort[3]=2;
    sort[4]=4;
    sort[5]=6;

    printf("\nStart sort:\n");
    // MergeSort(0, N-1, sort);
    CombSort();

    printf("\nSort end:\n");

    for(i=0;i<N;i++){
        printf("%d ",sort[i]);
    }

    return EXIT_SUCCESS;
}