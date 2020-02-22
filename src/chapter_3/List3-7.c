#include <stdio.h>
#include <stdlib.h>

// リストの要素（ノード）を表す構造体
typedef struct tagListNode{
    struct tagListNode *prev;   // 前の要素へのポインタ
    struct tagListNode *next;   // 次の要素へのポインタ
    int data;
} ListNode;

int main(void){

    int buf;
    ListNode *firstnode, *lastnode, *newnode, *thisnode, *tmpnode;

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

    do{
        printf("current sequence\n");

        for(thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next){
            printf("%d\t", thisnode->data);
        }

        // 検索値を入力
        printf("\ninput value of search");
        scanf("%d", &buf);

        if(buf != 0){
            // 最初に入力した値から検索
            for(thisnode = firstnode; thisnode != NULL; tmpnode = thisnode, thisnode = thisnode->next){

                if(thisnode->data == buf){
                    printf("input value %d is found\n", buf);

                    if(thisnode != firstnode){
                        // 検索で見つかったノードを先頭に
                        tmpnode->next = thisnode->next;

                        if(lastnode == thisnode){
                            lastnode = tmpnode;
                        }

                        thisnode->next = firstnode;
                        firstnode = thisnode;
                    }
                    break;
                }
            }
            if(thisnode == NULL){
                printf("%d was not in the list\n", buf);
            }
        }
    }while(buf != 0);

    thisnode = firstnode;

    while(thisnode != NULL){
            tmpnode = thisnode->next;
            free(thisnode);
            thisnode = tmpnode;
    }

    return EXIT_SUCCESS;
}