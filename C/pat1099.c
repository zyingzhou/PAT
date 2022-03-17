/**
* pat1099
* Author: zhiying
* Date: 2022/1/22  update:2022/3/17
* Copyright (c) 2022 All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
int is_prime(int num);
int is_prime_v2(int num);
int find_next_prime(int num);
int is_sexy_primes(int num, int *another);

int main(){
    int n = 0;
    scanf("%d", &n);
    int another = 0;
    if (is_sexy_primes(n, &another)){
        printf("Yes\n%d\n",another);
    } else{
        printf("No\n");
        int next = find_next_prime(n);
        printf("%d\n", next);
    }
    return 0;
}
/*
 * return -1 既不是素数也不是合数
 * 　　　　　1 是素数
 * 　　　　　0 不是素数
 * */
int is_prime(int num){
    // 1既不是素数也不是合数
    if (num <= 1){
        return -1;
    }
    int ret = 1;
    int idx = 2;
    // num > 1  and integer
    while (idx < num){

        if (num % idx == 0){
            ret = 0;
            break;
        }
        idx++;
    }

    return ret;
}
int is_prime_v2(int num){
    // 1既不是素数也不是合数
    if (num <= 1){
        return -1;
    }
    int ret = 1;

    for(int idx = 2; idx <= num / idx; idx++){
        if (num % idx == 0){
            ret = 0;
            break;
        }
    }
    return ret;
}
int find_next_prime(int num){

    int next = num + 1;
    while (1){
        if(is_prime_v2(next) == 1 && (is_prime_v2(next-6) == 1 || is_prime_v2(next + 6) == 1)){
            break;
        }
        next++;
    }
    return next;
    /* wrong
     * int start = num -5;
    int flag = 0;
    int base = 0;
    int next = 0;

    while (1){
        if (is_prime(start) == 1 && flag == 0){
            base = start;
            start++;
            flag = 1;
            continue;
        }
        if (is_prime(start) == 1 && flag == 1){

            if (start - base == 6){
                if (base <num){
                    next = start;
                } else{
                    next = base;
                }
                break;
            }
            flag = 0;
        }
        start ++;
    }
    return next;*/
    /* four right
     * int next = num;
    do{
        next++;
    }while (!(is_prime(next) == 1 && (is_prime(next-6) == 1 || is_prime(next + 6) == 1)));
    return next;*/
    /*Third
     * int next = num + 1;
    while (1){
        if (is_prime(next) == 1 && (is_prime(next - 6)==1 || is_prime(num + 6) == 1)){
            return next;
        }
        next++;
    }*/

    /*int next = num-5;

    while (1){

        if (is_prime(next) == 1 && is_prime(next+6) == 1){
            if (next < num){
                next = next + 6;
            }
            break;
        }
        next++;
    }*/
    /*int next = num + 1;
    int another = 0;
    // O(n * n) -> O(n)
    while (1){
        if (is_sexy_primes(next, &another)){
            break;
        }
        next++;
    }
    return next;*/
}

int is_sexy_primes(int num, int *another){
    int ret = 0;
    *another = 0;

    if (is_prime(num) == 1 && (is_prime(num-6)== 1 || is_prime(num + 6) == 1)){
         ret = 1;

         if (is_prime(num-6) == 1){
             *another = num - 6;
         } else{
             *another = num + 6;
         }
    }
    /*if (num < 2 ){
        ret = 0;

    } else {

        if (is_prime(num)== 1){

            if (num - 6 > 0) {

                if (is_prime(num - 6) == 1 || is_prime(num + 6) == 1) {
                    ret = 1;

                    if (is_prime(num - 6) == 1){
                        *another = num - 6;
                    } else{
                        *another = num + 6;
                    }

                }
            }else{
                if (is_prime(num + 6) == 1){
                    ret = 1;
                    *another = num + 6;
                }
            }
        }
    }*/
    return ret;
}