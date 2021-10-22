#include <stdio.h>
#define MAXSIZE 1000

void squeeze(char s1[], char s2[]){

	int i, j, k;

	for(i = 0; s2[i] != '\0'; i++){
		for(j = k = 0; s1[j] != '\0'; j++){

			if( s1[j] != s2[i])
				s1[k++] = s1[j]; 
		}
		s1[k] = '\0';
	}

}


int main(){

	char str1[] = "aabbbccccddeeeffffcccgh", str2[] = "abc";
	
	printf("%s\n%s\n", str1, str2);
	
	squeeze(str1, str2);

	printf("%s\n", str1);

	return 0;
}
