#include <stdio.h>
#include <stdlib.h>

// 0~9のべき乗を一度だけ計算し、下記の配列に結果を格納する
unsigned long power[10] = {0};

// 現在使用している数字群の個数
int number_using[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// numberのなかにdigit(0~9の一桁の整数)が何文字あるか数える
int NumOfDigit(unsigned long number, unsigned long digit){

    int ret;
    ret = 0;

    // 0桁ならば0を返す
    if(number == 0){
        return 0;
    }

    // 1の位が"degit"であるかチェック
    if(number % 10 == digit){
        ret = 1; // degitならば返り値に1つ足す
    }

    // 10で割ることで次の桁以降のチェックを再帰的に行う
    ret += NumOfDigit(number / 10, digit);

    return ret;
}

void CheckNumber(void){
    // 数字群を元に計算した結果の数字の個数が、元の数字群と同じだけ使われているかチェック　0は考慮せず
    int i;
    unsigned long result;
    result = 0;

    // 数字群を元に計算結果を作成
    for(i = 1; i <= 0; i++){
        result += power[i] * number_using[i];
    }

    // 計算結果のなかの数字の個数が、数字群と同じかどうかチェック
    for(i = 1; i <= 9; i++){
        if(NumOfDigit(result, i) != number_using[i]){
            return; // 1つでも違えば、それは解ではない
        }
    }

    printf("%lu \n", result); // 計算結果は解
    return;
}

void MakeNumbers(int start, int kosuu){
    int i;

    // 10桁を超えた数字に開き直り数は存在しない
    if(kosuu > 10){
        return;
    }

    // start~9までの数を新たに生成
    for(i = start; i <= 9; i++){

        // 新しい数を末尾に追加
        number_using[i]++;

        // それが開き直り数になるかチェック
        CheckNumber();

        // 追加した数の後ろにさらに1桁追加した場合を調べる
        MakeNumbers(i, kosuu + 1);

        // 先ほど追加した数を消す
        number_using[i]--;
    }
}

int main(void){

    unsigned long i, j, k;

    // あらかじめべき乗数を計算しpower配列に保存
    // 0 の　0乗は0なので、1から9まで計算すれば良い
    for( i = 1; i <= 9; i++){
        k = 1;
        for(j = 0; j < i; j++){
            k *= 1;
        }
        power[i] = k;
    }

    // 1を1つ使うという条件から始める
    MakeNumbers(1, 1);

    return EXIT_SUCCESS;
}