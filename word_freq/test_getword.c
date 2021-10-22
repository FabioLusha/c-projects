#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

int getword(char *, int);

int main(){
	char word[MAXWORD], *words[MAXWORD];
	int i, f;

	f = 0;
	while( getword(word, MAXWORD) != EOF){
		words[f++] = strdup(word);
	}


	for(i = 0; i < f; i++){
		printf("%s\n", words[i]);
	}
}
	
int getch(void);
void ungetch(int);

int getword(char *word, int max){
	
	char c, *w = word;

	while( isspace(c = getch()) )
		;
	if( c == EOF){
		*w = '\0';
		return c;
	}
	for( ; !isspace(c); c = getch())
		*w++ = c;

	*w = '\0';
	return *word;
}
