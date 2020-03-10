/**
  pat1001
Author: zhiying
Date: 2020.3.10

*/

#include <stdio.h>

int main(){

	int n;
	int count = 0;
	scanf("%d",&n);
	if (n==1){
	    count = 0;
	//	printf("%d\n",&count);

	}else{
	
		while(n != 1){
		
			if (n % 2== 0){
			
				n = n / 2;
			}else{
			
				n = (3*n + 1)/2;
			}
			count += 1;
		}
	}

    printf("%d\n",count);
	return 0;
}
