/**
  * pat1008
  * Author: zhiying
  * Date: 2020.3.19 20:32
  */

#include <stdio.h>
#include <stdlib.h>

void print(const int *a,int n,int offset);

int main(){
    int n;
	int offset;
	int i;
	scanf("%d %d",&n,&offset);
	int *a=(int *)malloc(sizeof(int)*n);

	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	print(a,n,offset);

	free(a);
	return 0;
}

void print(const int *a,int n,int offset){
    
	if (offset==n){
		int i;
		for (i=1;i<=n;i++){
			printf("%d",*a);
			if (i!=n){
			    printf(" ");
			}
			a++;
		}
	}

	if (offset > n){
		offset %= n;
	}

	if (offset < n){
		int i;
		int j;
		for (i=1;i<=offset;i++){
		    printf("%d ",*(a+n-1-offset+i));
		}

		for (j=0;j<(n-offset);j++){
			printf("%d",*(a+j));

			if (j != n-offset-1){
				printf(" ");
			}
		}

		
	}
	printf("\n");

}
