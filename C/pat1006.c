/**
  * pat1006
  * Author: zhiying
  * Date: 2020.3.16 20:15
  * 
  */

#include <stdio.h>
#include <stdlib.h>

int split(int n,int *a);
void print(int *a, int len);

int main(){

	int n;
	int len;
	int *a=(int*)malloc(sizeof(int)*4);
	scanf("%d",&n);
	len = split(n,a);
	print(a,len);
	free(a);
	return 0;
}

int split(int n, int *a){

	int *b=a;

	while (n != 0){
	    
		*a=(n%10);
		n/=10;
		a++;
	}
    return a-b;
}

void print(int *a,int len){

	while (len != 0){
        
		int i;

		for(i=0;i<*(a+len-1);i++){
			
			switch(len)
			{

				case 3: printf("B");break;
				case 2: printf("S");break;
				case 1: printf("%d",i+1);break;
				default:break;
			}
			
		}
		//a++;
		len--;
	}
	printf("\n");

}
