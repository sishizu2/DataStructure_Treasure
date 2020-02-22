#include <stdio.h>
#include <stdlib.h>

// リストの要素（ノード）を表す構造体
typedef struct tagListNode{
    struct tagListNode *prev;   // 前の要素へのポインタ
    struct tagListNode *next;   // 次の要素へのポインタ
    int data;
} ListNode;

int main(void){

    int buf, sum;

    ListNode *firstnode, *lastnode, *newnode, *thisnode, *removenode;

    firstnode = lastnode = NULL;

    do{

        printf("\ninput integer:");
        scanf("%d", &buf);

        if(buf){    // 新たな入力があれば
            // 新しいノード作成
            newnode = (ListNode*)malloc(sizeof(ListNode));
            newnode -> data = buf;
            newnode -> next = NULL;

            
            printf("\n%d", buf);
            printf("\n%p", newnode);

            if(lastnode != NULL){
                // すでにあるノードの末尾に新しいノードを繋げる
                lastnode ->next = newnode;
                newnode -> prev = lastnode;
                lastnode = newnode;
            }else{
                // 最初の要素の場合
                firstnode = lastnode = newnode;
                newnode ->prev = NULL;
            }
        }
    }while(buf != 0);

    // 検索値を入力
    do{
        printf("what to search:");
        scanf("%d", &buf);

        if(buf != 0){
            // 最初に入力した値から検索し、見つかったら削除
            for(thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next){
                if(thisnode->data==buf){
                    printf("value %d found. The node is deleted\n", buf);

                    if(thisnode->prev != NULL){
                        thisnode->prev->next = thisnode->next;
                    }else{
                        firstnode = thisnode->next;
                    }

                    if(thisnode->next != NULL){
                        thisnode->next->prev = thisnode->prev;
                    }

                    free(thisnode);
                    break;
                }
            }
            if(thisnode == NULL){
                printf("%d is not input or already deleted\n", buf);
            }
        }
    }while(buf != 0);

    // リストの全ノードを削除
    for(thisnode = firstnode; thisnode != NULL;){
        removenode = thisnode;
        thisnode = thisnode->next;
        free(removenode);
    }

    return EXIT_SUCCESS;
}