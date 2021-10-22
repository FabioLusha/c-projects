#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

int getword(char *, int);

int main(){

	struct tnode *root;
	char word[MAXWORD];

	root = NULL;

	while (getword(word, MAXWORD) != EOF )
		if (isalpha(*word))
			root = addtree(root, word);
	treeprint(root);
	
	return 0;
}

int getch(void);
void ungetch(int);

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
