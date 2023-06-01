/**
  * pat1007
  * Author: zhiying
  * Date: 2020.3.17 7:36
  *
  */

#include <stdio.h>
#include <stdlib.h>

void look_prime(const int n,int *a,int *len);
int look_prime_couples(const int *a, int len);
int isprime(const int n);
int is_prime_v2(int a);

int main(){

    int n;
    int *primes=(int*)malloc(sizeof(int)*9593);
    int *len;
    scanf("%d",&n);
    look_prime(n,primes,len);
    int count = look_prime_couples(primes,*len);
    printf("%d\n",count);
    free(primes);
    return 0;
}

void look_prime(const int n, int *a,int *len){

    int i;
    int cnt=0;

    for (i=2;i<=n;i++){
        if(is_prime_v2(i)){

            *a = i;
            a++;
            cnt++;
        }
    }
    *len = cnt;
}

int isprime(const int a){

    int j=2;

    while(j<a){

        if((a%j)==0){

            return 0;
        }
        j++;
    }
    return 1;

}

int is_prime_v2(int a){
    int ret = 1;

    if (a <= 1){
        ret = -1;
    }

    for (int i = 2; i <= a / i;i++){

        if ( a % i == 0){
            ret = 0;
            break;
        }
    }

    return ret;
}

int look_prime_couples(const int *a,int len){

    int i;
    int cnt=0;
    for (i=0;i<len-1;i++){

        if ((*(a+i+1)-*(a+i)) ==2){

            cnt++;
        }
    }
    return cnt;
}
