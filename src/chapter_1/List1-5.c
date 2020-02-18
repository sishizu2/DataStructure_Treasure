#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define N 10    /* データ件数 */
#define N 6

int sort[N];
int buffer[N];

void MergeSort(int n, int x[]){
    int i, j, k, m;
    if(n <= 1){
        return;
    }
    m = n/2;    // ブロックを半分に分ける

    // ブロックを前半・後半に分ける
    MergeSort(m, x);
    MergeSort(n-m, x+m);

    // マージ
    for(i=0; i<m; i++){
        buffer[i]=x[i];
    }
    j=m;
    j=k=0;

    while(i<m && j<n){
        if(buffer[i] <= x[j]){
            x[k++] = buffer[i++];
        }else{
            x[k++] = x[j++];
        }
    }
    while(i<m){
        x[k++]=buffer[i++];
    }
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
    MergeSort(N, sort);

    printf("\nSort end:\n");

    for(i=0;i<N;i++){
        printf("%d ",sort[i]);
    }

    return EXIT_SUCCESS;
}