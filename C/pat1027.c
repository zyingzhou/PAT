/**
* pat1027
* Author: zhiying
* Date: 2021.2.23 23:17
*/
#include <stdio.h>

void print_sandglass(int len, char c);
int calculate_height(int sands, int *remain);


int main(){
    int remain = 0;
    int sands = 0;
    char shape;
    scanf("%d %c", &sands, &shape);
    int height = calculate_height(sands, &remain);
    print_sandglass(height,shape);
    printf("%d\n",remain);

    return 0;
}

void print_sandglass(int len, char c){
    char space = ' ';

    // 沙漏上部分
    for (int i = 0;i < len;i++){
        for (int m = 0;m < i;m++){
            printf("%c",space);
        }

        for (int n =0;n<(1+(len-i-1)*2);n++){
            printf("%c",c);
        }
        printf("\n");
    }

    // 沙漏下部分
    for (int i = 1;i <= len;i++){
        if (i == 1){
            continue;
        }

        for (int n =1;n<=(len - i);n++){
            printf("%c",space);
        }

        for (int m = 1;m <=(1+(i-1)*2);m++){
            printf("%c",c);
        }

        printf("\n");
    }
}

int calculate_height(int sands, int *remain){
    int height = 1;
    int sn = 1;

    while (sn <= sands){
        height ++;
        sn = height * height * 2 - 1;
    }

    height--;
    *remain = sands - (height * height * 2 - 1);

    return height;
}
