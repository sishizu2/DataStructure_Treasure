#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 英単語&和訳を保持する構造体
typedef struct 
{
    /* data */
    char *english;
    char *japanese;
} WORDSET;

// ハッシュ表
typedef struct 
{
    /* data */
    WORDSET **data;
    unsigned int size;
} HASHTABLE;

// 文字列のASCIIコードに重率を掛けてハッシュ値生成
unsigned int MakeHash2(char* str, unsigned int hashmax){

    unsigned int n, length, hash, weight;

    length = strlen(str);

    for(n = weight = hash = 0; n < length; n++, weight++){

        // 重率がintの限界に達したら、一巡して元に戻す
        if(weight > 7){
            weight = 0;
        }

        hash += (int)str[n] << (4 * weight);
        // "<< (4 * weight)" は "256^weight"と同じ意味
    }

    return hash % hashmax;
}

// firsthashの位置が埋まっていた場合に再ハッシュを行う
unsigned int ReHash(HASHTABLE *hashtable, unsigned int firsthash){

    unsigned int hashval, k;

    /* firstvalからk^2だけ後ろにある空き位置を探す。
    　「k>ハッシュ表サイズの半分」となれば、それ以降の探索は無駄
    */

   for(k = 1; k <= hashtable->size / 2; k++){
       hashval = (firsthash + k * k) % hashtable->size;

       if(hashtable->data[hashval] == NULL){
           return hashval;
       }
   }

   // 空き位置が見つからなければ-1を返す
   return -1;
}

// newdataをhashtableに追加
void AddDataToMap(HASHTABLE *hashtable, WORDSET *newdata){
    unsigned int hashval;

    // 英単語をもとにハッシュ値生成
    hashval = MakeHash2(newdata->english, hashtable->size);

    // もしhashの位置がすでに埋まっていれば、再ハッシュ
    if(hashtable->data[hashval] != NULL){

        hashval = ReHash(hashtable, hashval);

        // 再ハッシュ結果が-1であれば、空き位置が見つからなかった＝マップ満杯
        if(hashval == -1){
            printf("map is full");
            return;
        }
    }

    // hashvalの位置にnewdataのポインタ格納
    hashtable->data[hashval] = newdata;
}

// 英単語keyに対応する和訳をhashtableから探し出して返す
char *GetDataFromMap(HASHTABLE *hashtable, char *key){

    unsigned int hashval, k;
    WORDSET *word;

    // 探索を開始するハッシュ値を求める
    hashval = MakeHash2(key, hashtable->size);

    // その位置から順番に、keyと同じ値を持つデータが現れるまで探索
    for (k = 0; k <= hashtable->size / 2; k++){
        word = hashtable->data[(hashval + k * k) % hashtable->size];

        if(word != NULL){
            if(strcmp(key, word->english) == 0){
                return word->japanese;
            }
        }
    }

    // ハッシュ表サイズの半分に相当する回数探し続けても見つからない場合は、該当するデータがハッシュ表にない
    return NULL;
}

// 英単語keyに関するデータをhashtableから取り除く (データは削除しない)
WORDSET *DeleteDataFromMap(HASHTABLE *hashtable, char *key){
    unsigned int hashval, k;
    WORDSET *word;

    // 探索を開始するハッシュ値を求める
    hashval = MakeHash2(key, hashtable->size);

    // その位置から順に、keyと同じ値をもつデータが現れるまで探索する
    for(k = 0; k <= hashtable->size / 2; k++){
        word = hashtable->data[(hashval + k * k) % hashtable->size];

        if(strcmp(key, word->english) == 0){
            hashtable->data[(hashval + k * k) % hashtable->size] = NULL;
            // ハッシュテーブルから取り除いたデータを返す
            return word;
        }
    }

    // 該当データなし
    return NULL;
}

// ハッシュテーブルを指定したサイズに初期化
void InitHashTable(HASHTABLE *hashtable, unsigned int size){
    hashtable->data = (WORDSET**)malloc(sizeof(WORDSET*) * size);
    
    // ハッシュテーブルをNULL埋め
    memset(hashtable->data, NULL, sizeof(WORDSET*) * size);

    hashtable->size = 0;
}

// ハッシュテーブルのクリーンナップ
void CleanupHashTable(HASHTABLE *hashtable){
    free(hashtable->data);
    hashtable->size = 0;
}

// hashtable中の全データ表示
void PrintAllData(HASHTABLE *hashtable){
    unsigned int n;

    for(n = 0; n < hashtable->size; n++){

        if(hashtable->data[n] != NULL){
            printf("%d:\t%s\t%s\n", n, hashtable->data[n]->english, hashtable->data[n]->japanese);
        }
    }
}

int main(void){
    unsigned int n;
    char key[64], *japanese;
    HASHTABLE hashtable;
    WORDSET *wordfound;
    WORDSET words[5] = {
        {"dolphin","イルカ"}, {"beluga","シロイルカ"},
        {"grampus","シャチ"}, {"medusa","海月"},
        {"otter","カワウソ"}
    };

    // ハッシュテーブル初期化
    InitHashTable(&hashtable, 503);

    // データ追加
    for(n = 0; n < 5; n++){
        AddDataToMap(&hashtable, &words[n]);
    }

    do{
        printf("1: search 2: delete 3: print 0:end \n");

        scanf("%d", &n);
        switch(n){
            case 1:
                printf("search keyword:");
                scanf("%s", key);
                japanese = GetDataFromMap(&hashtable, key);

                if(japanese != NULL){
                    printf("%s is %s in japanese\n", key, japanese);
                }else{
                    printf("%s is not found\n", key);
                }
                break;
            case 2:
                printf("what to delete: ");
                scanf("%s", key);
                wordfound = DeleteDataFromMap(&hashtable, key);
                if(wordfound != NULL){
                    printf("%s is deleted\n", key);
                }else{
                    printf("%s was not found\n", key);
                }
                break;
            case 3:
                PrintAllData(&hashtable);
                break;
        }

    }while(n != 0);

    CleanupHashTable(&hashtable);

    return 0;
}


