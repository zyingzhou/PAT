/*
 * pat1014
 * Author: zhiying
 * Date: 2020.3.27 10:17 
 */

#include <stdio.h>
#include <stdlib.h>

void free_m(char *a[]);
void print_value(char *a[],int len);
void cmp(char *a[],char *b, int *offset);
void print(char *b,int offset);

int main(){

    char *a[4];
	int i=0;
	char b[2];
	int offset;

	for (i=0;i<4;i++){
	    a[i] = (char *)malloc(sizeof(char)*61);
        if (a[i] !=NULL){
		
	    	scanf("%s",a[i]);
		}
	}
    cmp(a,b,&offset);
	free_m(a);
	print(b,offset);
	return 0;
}

void free_m(char *a[]){

	for (int i=0;i<4;i++){
	
		free(a[i]);
	}
}

void cmp(char *a[],char *b,int *offset){
	
	char *a1 = a[0];
	char *a2 = a[1];
	char *a3 = a[2];
	char *a4 = a[3];

	int idx = 0;

	while (*a[0] != '\0'&& *a[1] != '\0'){

		if (*a[0]==*a[1] && *a[0] >='A' && *a[0]<='G' && idx==0){
		
			*b = *a[0];
			b++;
			idx++;
			a[0]++;
			a[1]++;
			continue;
		}
        
		if (*a[0]==*a[1] && ((*a[0] >= 'A'&& *a[0]<='N') || (*a[0] >= '0'&& *a[0] <='9')) && idx==1){
			*b = *a[0];
            break;
		}

		a[0]++;
        a[1]++;	
	}

	int j=0;
	
	while (*a[2] != '\0' && *a[3] != '\0'){
	
		if (*a[2]==*a[3] && ((*a[2]>='A' && *a[2]<='Z') || (*a[2]>='a' && *a[2]<='z'))){
		
			*offset = j;
			break;
		}
        j++;		
		a[2]++;
		a[3]++;
	}
    /* pointer array return to the original position */
	a[0] = a1;
	a[1] = a2;
	a[2] = a3;
	a[3] = a4;
}

void print(char *b,int offset){

	char hours[] = "0123456789ABCDEFGHIJKLMN";

	/* DAY */
	switch (b[0]){
	
		case 'A': printf("MON ");break;
		case 'B': printf("TUE ");break;
		case 'C': printf("WED ");break;
		case 'D': printf("THU ");break;
		case 'E': printf("FRI ");break;
		case 'F': printf("SAT ");break;
		default:printf("SUN ");
	}

	/* hour */
	for (int j=0;j<24;j++){
	
		if (b[1]==hours[j]){
            if (j<10){
			
				printf("0%d:",j);    //format: DAY HH:MM
				break;
			}else{		
			    printf("%d:",j);
			    break;
			}
		}
	}

	/* minute */
	if (offset<10){
	
		printf("0%d\n",offset);
	}else{
	
		printf("%d\n",offset);
	}
}
