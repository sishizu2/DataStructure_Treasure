#include <stdio.h>
#include <string.h>

#define MAX_STATION (10)

typedef struct TAG_STATION{

    char name[256];
    struct TAG_STATION *transitions[MAX_STATION];   // 1駅につき10駅まで

} STATION;

void init_station(STATION* station, char* name){
    int i;
    for(i = 0; i < MAX_STATION; i++){
        station->transitions[i] = NULL; // 最初はどの駅にも繋がっていない

    }

    strncpy(station->name, name, sizeof(station->name) - 1);
    station->name[sizeof(station->name) - 1] = '\0';
}

void add_station(STATION* station, STATION* transition){
    int i;

    // transitionsで、まだ登録されていない場所を探す
    for(i = 0; i < MAX_STATION; i++){
        if(station->transitions[i] == NULL){
            break;
        }

        // すでに登録されているので、何もせず終了
        if(station->transitions[i] == transition){
            return;
        }
    }
    // 10駅すべて登録済なら何もしない
    if(i == MAX_STATION){
        return;
    }

    // 新しい乗り換え駅を登録
    printf("register %s", transition);
    station->transitions[i] = transition;
}

void print_station(STATION* station){
    int i;
    printf("%s:", station->name);

    for(i = 0; i < MAX_STATION; i++){
        if(station->transitions[i] == NULL){
            break;
        }
        printf("->%s  ", station->transitions[i]->name);
    }
    printf("\n");
}

int main(void){
    int i;
    STATION station[6];

    init_station(&station[0], "Kamakura");
    init_station(&station[1], "Fujisawa");
    init_station(&station[2], "Yokohama");
    init_station(&station[3], "Yokosuka");
    init_station(&station[4], "Chigasaki");
    init_station(&station[5], "Tokyo");

    // Kamakura
    add_station(&station[0], &station[3]);
    add_station(&station[0], &station[1]);
    add_station(&station[0], &station[2]);

    // Fujisawa
    add_station(&station[1], &station[0]);
    add_station(&station[1], &station[4]);
    add_station(&station[1], &station[2]);

    // Yokohama
    add_station(&station[2], &station[1]);
    add_station(&station[2], &station[0]);
    add_station(&station[2], &station[5]);

    // Others
    add_station(&station[3], &station[0]);
    add_station(&station[4], &station[1]);
    add_station(&station[5], &station[2]);

    // グラフ構造を表示
    for(i = 0; i < 6; i++){
        print_station(&station[i]);
    }
    return 0;

}