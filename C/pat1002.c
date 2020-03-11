/**
  pat1002
Author: zhiying
Date: 2020.3.10

*/

#include <stdio.h>

void split_numbers(int n,int *splited_numbers,int *len){

	int array_len;
	int i=0;
    if (n<10){
		splited_numbers[i] = n;
		
    }else{
		while(n != 0){
		
			splited_numbers[i] = n % 10;
			i++;
			n /= 10;
			if (n <10){
			
				splited_numbers[i] = n;
				n /= 10;
			}
		}
    }

	array_len = i + 1;
	
	*len = array_len;
}

void make_sum(int *splited_numbers, int len, int *all_sum){
	
	int numbers_sum=0;
	int i;

	for (i=0;i<len;i++){

		numbers_sum += splited_numbers[i];
		
	}

	*all_sum = numbers_sum;

}

void print_values(char *a[],int *b,int len){
	int i;
	int index;
	for(i=len-1;i>=0;i--){
	
		index = b[i];
		printf("%s",a[index]);
		if (i != 0){
			printf(" ");

		}
	}


}

int main(){

    char n[100];
    char *p;	
	p = n;
	char *all_sum[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int a[100];
	int b[100];
	int len=0;
	int sum_len;
	int result;
	scanf("%s",p);
	while(*p != '\0'){
	
		a[len] = (int)(*p) - 48;
		p++;
		len++;
	}
    make_sum(a,len,&result);
	split_numbers(result,b,&sum_len);
	print_values(all_sum,b,sum_len);

	return 0;
}
