#include <stdio.h>

#define BUFSIZE 100

/* a method for implementig a lookahead logic without loosing the lookahead char */

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf*/


int getch(void){
	return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c){ /* push character back to input */
	if(bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("ungetch: too many characters\n");
}
