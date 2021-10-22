#include <stdio.h>

float atof(int *);

int main(){
	
	char *str[2];
	str[0] = "abc";
	str[1] = "def";

	printf("%c\n", (*str)[1]); /* prints b. = *(++(*str)) */
							   /* get the value pointed by str, which is a pointer */
							   /* pointing to the array "abc\0". from which it extract the value in [1] */

	printf("%c\n", *str[1]); /* printf d */
							 /* str[1] returns the pointer to "def" */
							 /* * dereference it to give d */
	return 0;
}
