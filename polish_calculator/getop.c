#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]){
	int i,c;

	while ((s[0] = c = getch()) == ' ' || c == 't')
		;
	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c; /* not a number*/

	i = 0;
	if (isdigit(c))
		while(isdigit(s[++i] = c = getch())) /* collect integer part */
			;
	if ( c == '.' )
		while(isdigit(s[++i] = c = getch())) /* collect decimal part */
			;
	s[i] = '\0';

	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

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
