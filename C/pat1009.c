/*
 * pat1009
 * Author: zhiying
 * Date: 2020.3.20 20:49
 *
 */

#include <stdio.h>
#include <stdlib.h>

void reverse(char *s);

int main(){

	char a[81];
	int i=0;
    char ch;
	scanf("%c",&ch);

	/* End input when encount LR，write'\0' at the end of array,the ASCII value of LF is 10 */
	while ((int)(ch) != 10){
	
		a[i] = ch;
		i++;
		scanf("%c",&ch);
	}

	a[i] = '\0';
	reverse(a);
	printf("%s\n",a);
	return 0;

}

/**
 * reverse - Reverse the words(space splited) in a string.
 * @s: One string
 */
void reverse(char *s){

	char a[81];
	int words_index[81];
	int count=0;
	int index = 0;
	words_index[count] = index;

	while (*s != '\0'){
	
		a[index] = *s;
		if ((int)(*s) == 32){
		    count++;
			words_index[count] = index;
		
		}
		s++;
		index++;
	}

	count++;
	words_index[count] = index;
	int j;

	for (j=0;j<count;j++){

		int m=words_index[j+1]-1;
        
		for (;m>=words_index[j];m--){

			/* Ignore the space before the last word */
			if (m==words_index[j] && j == (count - 1)){
			
				continue;
			}

			s--;
			*s = a[m];
		    
			/* Add one space before the first word */
			if (m==words_index[j] && j == 0){
				s--;
				*s = (char)(32);
			}
		}
	}

}
