#include <stdio.h>

int main(){

	int i = 2, pow = 1;
	
	while ( i > 0){
		i *= 2;
		pow++;
	}

	printf("pow: %d\n", ++pow);


	return 0;
}
