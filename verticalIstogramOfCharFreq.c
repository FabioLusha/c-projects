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

	printf("%4d ", 0);
	for(int i = 0; i < alphabetDim; i++){
		printf("%c ", i + 'A');
	}
	
	printf("\n\n");
	
	int max = 0;
	
	for(int i = 0; i < alphabetDim; i++){
		if(nletter[i] > max)
			max = nletter[i];
	}

	for(int i = max; i > 0; i--){
		printf("%4d ", i);
		for(int j = 0; j < alphabetDim; j++)
			if(nletter[j] >= i)
				printf("# ");
			else
				printf("  ");
		printf("\n");
	}

	return 0;
}
