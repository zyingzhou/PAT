/*
 * pat1013
 * Author: zhiying
 * Date: 2020.3.21 20:58
 */

#include <stdio.h>
#include <stdlib.h>

int isprime(const int n);
int is_prime_v2(int num);
void print(const int *a,int len);

int main(){

    int m,n;
    scanf("%d %d",&m, &n);
    int a[n-m+1];

    int i = 2;
    int cnt = 0;
    int j = 0;

    for (;cnt <= n+1;i++){

        if (is_prime_v2(i)){
            cnt++;

            if (m<= cnt && cnt <=n){
                a[j] = i;
                j++;
            }

        }
    }
    print(a,n-m+1);
    return 0;
}

int is_prime_v2(int num){

	int ret = 1;

	if (num <= 1){
	    ret = -1;
	}

	for (int i = 2; i <= num / i;i++){

	    if (num % i == 0){
	        ret = 0;
            break;
	    }
	}
	return ret;
}
int isprime(const int a){

    int j=2;

    for (;j<a;j++){

        if((a%j)==0){

            return 0;
        }
    }
    return 1;

}

void print(const int *a,int len){

    int i;

    for (i=0;i<len;i++){

        printf("%d",a[i]);

        if ((i+1) % 10 == 0 || i == len - 1){

            printf("\n");
        }else{

            printf(" ");
        }

    }
}




