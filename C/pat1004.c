/**
  * pat1004
  * Author: zhiying
  * Date: 2020.3.14
  * 
  */
#include <stdio.h>
#include <stdlib.h>
struct student
{
char name[11];
char no[11];
int score;
};

typedef struct student Student;

void swap(Student *a, Student *b);
void sort(Student *a[], int len);
void print(Student *a[], int len);
void free_m(Student *a[], int len);

int main(){
	int n;
	int i;
	scanf("%d",&n);
	Student *p[n];
	for (i=0;i<n;i++){
		p[i] = (Student *) malloc(sizeof(Student));
		scanf("%s %s %d",p[i]->name,p[i]->no,&p[i]->score);
		
	}
    sort(p, n);
	print(p, n);
	free_m(p, n);

	return 0;
}

void swap(Student *a, Student *b){

	Student t;
	t = *a;
	*a = *b;
	*b = t;
}

void sort(Student *a[],int len){

	int i,j;
	for (i=0;i<len;i++){
	
		for(j=i+1;j<len;j++){

			if (a[i]->score<a[j]->score){

				swap(a[i],a[j]);
			
			}
		

		}
	}


}

void print(Student *a[],int len){

	printf("%s %s\n",a[0]->name,a[0]->no);
	printf("%s %s\n",a[len-1]->name,a[len-1]->no);
}

void free_m(Student *a[], int len){

	int i;
	for (i=0; i<len;i++){
	
		free(a[i]);
	}
}
