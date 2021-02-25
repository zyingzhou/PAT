/**
* pat1018
* Author: zhiying
* Date: 2021.2.24 21:36
*/
#include <stdio.h>
#include <stdlib.h>
// 手势
typedef struct {
    int gesture_C;    // 锤子
    int gesture_J;    // 剪刀
    int gesture_B;    // 布
}Gesture;
// 运动员
typedef struct {
    int win;
    int fail;
    int equal;
    Gesture win_gesture;
}Player;

int cmp(char c1, char c2, char* win);
char sort_c(int gesture_B, int gesture_C, int gesture_J);

int main(){
    int N;
    scanf("%d", &N);
    //　指针数组
    char *games[N];

    for (int i=0;i < N;i++) {
        games[i] = (char *) malloc(sizeof(char) * 2);
        char *tmp = games[i];
        if (tmp != NULL) {
            for (int j = 0; j < 2; j++){
                scanf("%s", tmp+j);
            }
        }
    }

    Player player[2];
    // 初始化
    for (int i = 0;i < 2;i++){
        player[i].win = 0;
        player[i].fail = 0;
        player[i].equal = 0;
        player[i].win_gesture.gesture_B = 0;
        player[i].win_gesture.gesture_C = 0;
        player[i].win_gesture.gesture_J = 0;
    }

    for (int i=0;i < N;i++){
        char win = ' ';
        int result = cmp(*(games[i]), *(games[i] + 1), &win);

        if (result == 1){
            player[0].win += 1;
            player[1].fail += 1;

            if (win == 'C'){
                player[0].win_gesture.gesture_C += 1;
            } else if (win == 'J'){
                player[0].win_gesture.gesture_J += 1;
            } else{    // win == 'B'
                player[0].win_gesture.gesture_B += 1;
            }
        } else if (result == -1){
            player[1].win += 1;
            player[0].fail += 1;

            if (win == 'C'){
                player[1].win_gesture.gesture_C += 1;
            } else if (win == 'J'){
                player[1].win_gesture.gesture_J += 1;
            } else {    // win == 'B'
                player[1].win_gesture.gesture_B += 1;
            }
        } else{
            player[0].equal += 1;
            player[1].equal += 1;
        }
    }
    // 释放指针
    for (int i =0; i < N; i++){
        free(games[i]);
    }



    for (int i=0;i< 2;i++){
        printf("%d %d %d\n", player[i].win, player[i].equal, player[i].fail);
    }

    for (int i=0;i< 2;i++){
        printf("%c", sort_c(player[i].win_gesture.gesture_B, player[i].win_gesture.gesture_C, player[i].win_gesture.gesture_J));
        if (i == 0){
            printf(" ");
        } else{
            printf("\n");
        }
    }

    return 0;
}

/**
 * C:锤子     J:剪刀　　 B:布
 * @param c1: 手势
 * @param c2: 手势
 * @param win: 获胜的手势
 * @return  甲胜返回１,乙胜返回-1,平手返回0
 */
int cmp(char c1, char c2, char* win){
    if (c1 == 'C' && c2 == 'C'){
        *win = ' ';
        return 0;
    } else if (c1 == 'C' && c2 == 'J'){
        *win = c1;
        return 1;
    } else if (c1 == 'C' && c2 == 'B'){
        *win = c2;
        return -1;
    } else if (c1 == 'B' && c2 == 'C'){
        *win = c1;
        return 1;
    } else if (c1 == 'B' && c2 == 'J'){
        *win = c2;
        return -1;
    } else if (c1 == 'B' && c2 == 'B'){
        *win = ' ';
        return 0;
    } else if (c1 == 'J' && c2 == 'C'){
        *win = c2;
        return -1;
    } else if (c1 == 'J' && c2 == 'J'){
        *win = ' ';
        return 0;
    } else{ // c1 == 'J' && c2 == 'B'
        *win = c1;
        return 1;
    }
}

char sort_c(int gesture_B, int gesture_C, int gesture_J){
    if (gesture_B >= gesture_C){
        if (gesture_B >= gesture_J){
            return 'B';
        } else{
            return 'J';
        }
    } else {
        if (gesture_C >= gesture_J){
            return 'C';
        } else {
            return 'J';
        }
    }
}
