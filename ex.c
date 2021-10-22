#include <stdio.h>

int strend(char *, char *);
void strncpy(char *, char *, int );

int main(){
	char a[] = "abcde", b[] = "cde", c[] = "ade";
	printf("strend(abcde, cde): %d\n", strend(a,b));
	printf("strend(abcde, ade): %d\n", strend(a,c));

	strncpy(a,b,2);
	printf("strncpy(abcde, cde, 2): %s\n", a);

}
