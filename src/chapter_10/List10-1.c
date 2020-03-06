#include <stdio.h>
#include <stdlib.h>

int board[8][8];

// x,yにクイーンをおけるかチェック
int check(int x, int y){
    int p, q;

    // 左方向にすでにクイーンがあるかチェック
    for(p = 0; p < x; p++){
        if(board[p][y] == 1){
            return 0;
        }
    }

    // 左上方向をチェック
    p = x;
    q = y;

    while(p > 0 && q > 0){
        if(board[--p][--q] == 1){
            return 0;
        }
    }

    // 左下方向をチェック
    p = x;
    q = y;
    while(p > 0 && q < 7){
        if(board[--p][++q] == 1){
            return 0;
        }
    }

    return 1;
}

// 現在の盤面表示
void showboard(void){
    int x, y;
    for(y = 0; y < 8; x++){
        for(x = 0; x < 8; x++){
            printf("%c ", board[x][y] ? 'Q': '.');
        }
        printf("\n");
    }
}

int solve(int x){
    int i;

    if(x == 8){
        return 1;
    }

    for(i = 0; i < 8; i++){
        if(check(x, i)){
            // 置けたら、置く
            board[x][i] = 1;
            // 次の列に置く
            if(solve(x + 1)){
                return 1;
            }else{
                board[x][i] = 0;    // クイーン置きなおし
            }
        }
    }
    return 0;
}

int main(void){
    if(solve(0)){
        showboard();
    }
    return EXIT_SUCCESS;
}