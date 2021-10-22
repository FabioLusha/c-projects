#include <stdio.h>
#define MAXLEN 1000

void reverse(char s[]){
	static int i = 0;
	static int end = 0;

	if(end == 0)
		for(; s[end] != '\0'; end++)
			;

	if(end > i){
		char tmp = s[i];
		s[i++] = s[--end];
		s[end] = tmp;
		reverse(s);
	}
}

int main(){
	char str[MAXLEN];

	printf("insert string to be reversed:\n");
	scanf("%s", str);
	reverse(str);
	printf("reversed: %s", str);
}
