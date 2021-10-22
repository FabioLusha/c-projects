#include <stdio.h>

int main(){

	int alphabetDim = 'Z' - 'A' + 1;
	int nletter[alphabetDim];

	for(int i = 0; i < alphabetDim; i++)
		nletter[i] = 0;
	

	int c;
	while( (c = getchar()) != EOF ){
		if(c >= 'a')
			c = c - 'a' + 'A';

		if( c >= 'A' && c <= 'Z' )
			nletter[c-'A']++;
	}

	for(int i = 0; i < alphabetDim; i++){
		printf("%c\t", i + 'A');

		for(int j = 0; j < nletter[i]; j++)
			printf("|");

		printf("\n");
	}

	return 0;
}
