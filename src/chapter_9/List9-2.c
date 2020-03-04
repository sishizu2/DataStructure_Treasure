#include <stdio.h>
#include <stdlib.h>

#define PATTERN_LENGTH 13

unsigned char original_text[] = "a eighty-eighty-eighty key";
unsigned char original_pattern[PATTERN_LENGTH + 1] = "eighty-eighth"

#define _SHOW_WORKING_

unsigned char *kmp_search(unsigned char *text, unsigned char *pattern){

    int table[PATTERN_LENGTH + 1] = {0, 0};
    int text_index = 1, pattern_index = 0;
    int i = 0, j;

    // KMP検索に必要な情報を集め、テーブルとして保存
    while((pattern[text_index]) != '\0'){
        
        if(pattern[text_index] == pattern[pattern_index]){
            // 一致したら、再検索はpattern_index文字から開始
            table[++text_index] = ++pattern_index;

        }else if(pattern_index == 0){
            // パターン1文字目で不一致ならば再検索は先頭から
            table[++text_index] = 0;

        }else{
            // パターン1文字目以外で不一致ならば再検索の位置はtableから参照
            pattern_index = table[pattern_index];
        }
    }
    // テーブル完成、実際の検索に進む

    while((*text) != '\0'){

#ifdef _SHOW_WORKING_

        // 現在、何を比較しているか表示
        printf("    text:%s \n pattern:", original_text);

        for(j = 0; i < text-original_text; ++j){
            printf(" ");
        }

        printf("%c \n", pattern[i]);

#endif
        if((*text) == pattern[i]){
            // テキストとパターンが一致していれば、1文字ずつ比較を続ける
            text++;
            if(pattern[++i] == '\0'){
                // 全て一致すれば正解
                return text - PATTERN_LENGTH;
            }
        }
        else if(i == 0){
            // パターン最初の文字で失敗した場合は、比較場所を1つ進める
            text++;
        }else{
            // 最初の文字でない場合はテーブルから比較位置を取得
            i = table[i];
        }

    }
    return NULL;
}

int main(void){
    unsigned char *result;
    result = kmo_search(original_text, original_pattern);
    if(result == NULL){
        printf("not found");
    }else{
        printf("found");
    }

    return EXIT_SUCCESS;
}