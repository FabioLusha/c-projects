#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000

char *lineptr[MAXLINES]; /* max #lines to be sorted */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

// void qsort(char *lineptr[], int left, int right);

int main(){
	int nlines;

	if(( nlines = readlines(lineptr, MAXLINES) ) > 0 ) {
		// qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input to big to sort or no input\n");
		return 1;
	}
}


#define MAXLEN 1000 	/*max length of any input line */

int my_getline(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while( (len = my_getline(line, MAXLEN)) > 0)
		if(nlines >= maxlines || (p = (char *) malloc(len) ) == NULL )
			return -1;
		else {
			line[len-1] = '\0'; /* substitute new linw with end of line */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines){

	int i;
	while(nlines-- > 0 )
		printf("%s\n", *lineptr++);
}
