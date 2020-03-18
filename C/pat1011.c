/**
* pat1011
* Author: zhiying
* Date: 2020.3.18
*/
#include <stdio.h>
#include <stdlib.h>

void check(long long *a[],int len);
void free_m(long long *a[],int len);

int main(){
    int n;
    int i;
    scanf("%d",&n);
    //int *nums[]=(int*)malloc(sizeof(int*)*n);
    long long *nums[n];
    
    for (i=0;i<n;i++){
    	// 初始化指针数组
		nums[i] = (long long *)malloc(sizeof(long)*3); 
    	scanf("%lld %lld %lld",&nums[i][0],&nums[i][1],&nums[i][2]);
	}
	check(nums,n);
	free_m(nums,n);
	return 0;
}

void check(long long *a[],int len){
	int i;
	
	for (i=0;i<len;i++){
		
		if ((a[i][0] + a[i][1]) > a[i][2]){
			printf("Case #%d: true\n",i+1);
		}else{
			printf("Case #%d: false\n",i+1);
		}
	}
}

// 释放内存 
void free_m(long long *a[],int len){
	int i;
	
	for (i=0;i<len;i++){
		free(a[i]);
	}
}
