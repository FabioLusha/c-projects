#include <stdio.h>
#define MAXLINE 1000


/* get_line: get line into s, return length */
int get_line(char s[], int lim){

	int c, i;

	i = 0;
	while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}


/* strindex: return the index of t in s, -1 if none */
int strindex(char s[], char t[]){

	int i,j,k;

	for( i = 0; s[i] != '\0'; i++){
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if(k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

/* strindexr: return the index of the rightmost t in s, -1 if none */
int strindexr(char s[], char t[]){

	int i,j,k, rightmost = 0;

	for( i = 0; s[i] != '\0'; i++){
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if(k > 0 && t[k] == '\0')
			rightmost = i;
	}

	return rightmost > 0 ? rightmost : -1;
}

char pattern[] = "ould";

int main(){

	char line[MAXLINE];
	int found = 0;

	while( get_line(line, MAXLINE) > 0 )
		if(strindexr(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}

	return found;
}


