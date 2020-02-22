#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX (5 + 1)   //キューのサイズ+1
#define QUEUE_EMPTY - 1

// 配列によるキュー構造
int queue[QUEUE_MAX];

// キュー先頭位置（配列先頭からのオフセット）
int queue_first = 0;

// キュー末尾位置（配列先頭からのオフセット）
int queue_last = 0;

// キューにデータを追加
void enqueue(int val){
    // lastの次がfirstならば
    if((queue_last+1) % QUEUE_MAX == queue_first){
        // 配列の中身は全て埋まっている
        printf("job is full");
    }else{
        // キューに新しい値を入れる
        queue[queue_last] = val;

        // queue_lastを一つずらす。一番後ろの場合は、先頭に
        queue_last = (queue_last + 1) % QUEUE_MAX;

    }
}

// キューからデータを取り出す
int dequeue(void){
    int ret;

    if(queue_first == queue_last){
        // 現在キューは一つもない
        return QUEUE_EMPTY;
    }else{
        // 一番先頭のキューを出す
        ret = queue[queue_first];

        // キューの先頭を次に移動する
        queue_first = (queue_first + 1) % QUEUE_MAX;
        return ret;
    }
}