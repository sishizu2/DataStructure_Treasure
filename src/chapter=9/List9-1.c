#include <stdio.h>
#include <stdlib.h>

unsigned char original_text[] = "Team Swift";
unsigned char original_pattern[] = "if";

#define _SHOW_WORKING_

unsigned char *simple_search(unsigned char *text, unsigned char *pattern){

    int i;
    while((*text) != '\0'){

#ifdef _SHOW_WORKING_
        // 分かりやすいように、いま何を比較しているか表示
        printf("    main passage: %s \n pattern:", original_text);
        for(i = 0; i < text - original_text; i++){

            printf(" ");
        }

        printf("%s \n", pattern);

#endif
        // パターン先頭から比較開始
        for(i = 0; pattern[i] != '\0'; i++){

            if(pattern[i] != text[i]){
                // 一致しない
                break;
            }
        }

        if(pattern[i] == '\0'){
            // 一致
            return text;
        }

        // 一致しなかったのでテキストを1つずつずらして再度挑戦
        text++;
    }
    return NULL;
}

int main(void){
    unsigned char *result;
    result = simple_search(original_text, original_pattern);

    if(result == NULL){
        printf("not found");
    }else{
        printf("found");
    }
    return EXIT_SUCCESS;
}