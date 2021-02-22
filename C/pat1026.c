/**
* pat1021
* Author: zhiying
* Date: 2021.2.23 6:50
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print(int hour, int minute, int second);

int main(){
    int c1=0;
    int c2=0;
    scanf("%d %d",&c1,&c2);
    // 时
    int hour = 0;
    // 分
    int minute = 0;
    // 秒
    int second = 0;

    int secs = (c2 - c1) / 100;
    if ((c2 - c1) % 100 >=50){
        secs += 1;
    }
    hour = secs / 3600;
    secs -= hour * 3600;
    minute = secs / 60;
    second = secs - minute * 60;
    print(hour,minute,second);
    return 0;
}

void print(int hour, int minute, int second){
    if (hour < 10){
        printf("0");
    }
    printf("%d:",hour);

    if (minute < 10){
        printf("0");
    }
    printf("%d:",minute);

    if (second < 10){
        printf("0");
    }
    printf("%d\n",second);

}
