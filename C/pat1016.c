/*
 * pat1016
 * Author: zhiying
 * Date: 2020.3.25 21:55
 */

#include <stdio.h>
#include <math.h>

void split_num(int n,int *nums,int *len);
int caculate(int *nums,int n,int len);

int main(){

	int a,da,b,db,pa,pb;
	int len;
	int nums[10];
	scanf("%d %d %d %d",&a,&da,&b,&db);
    split_num(a,nums,&len);
    pa = caculate(nums,da,len);
    split_num(b,nums,&len);
    pb = caculate(nums,db,len);	
	printf("%d\n",pa+pb);
	return 0;
}

void split_num(int n,int *nums,int *len){

	int cnt=0;

	while (n != 0){
	    
		*nums = n % 10;
		nums++;
		cnt++;
		n /= 10;
	}

	*len = cnt;
}

int caculate(int *nums,int n, int len){

	int i=0;
	int sum=0;

	while (len){
	
		if (*nums==n){
			sum += (n * pow(10.0,i));
			i++;
		}
		nums++;
		len--;
	}
	return sum;
}
