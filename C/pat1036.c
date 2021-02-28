/**
* pat1036
* Author: zhiying
* Date: 2021.2.28 7:59
*/

#include <stdio.h>
#include <stdlib.h>

void print_rect(int width, int height, char ch);
//void print_blankline(int width);
void print_row_head(int width, char ch);
void print_row_next(int width, char ch);

int main(){
    int n = 0;
    char ch;
    scanf("%d %c",&n, &ch);
    int height = n / 2;
    if ( n % 2 == 1){
        height ++;
    }
    print_rect(n, height, ch);
    return 0;
}

void print_rect(int width, int height, char ch){

    for (int i = 0; i < height; i ++){

        if (i == 0 || i == height - 1){
            print_row_head(width, ch);
            continue;
        }
        print_row_next(width, ch);
        /*if (i % 2 == 1){
            print_blankline(width);
        } else{
            print_row_next(width, ch);
        }*/

    }

}

void print_blankline(int width){
    char space = ' ';

    for (int i = 0; i < width; i ++){
        printf("%c", space);
    }
    printf("\n");
}
void print_row_head(int width, char ch){
    for (int i = 0; i < width; i ++){
        printf("%c",ch);
    }

    printf("\n");
}
void print_row_next(int width, char ch){
    char space = ' ';
    int space_len = width - 2;

    for (int i = 0; i < width; i++){
        if (i == 0 || i == width - 1){
            printf("%c", ch);
            continue;
        }
        printf("%c", space);
    }
    printf("\n");
}