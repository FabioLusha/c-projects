#include <stdio.h>


int main(){
	int size = 10;

	dynamic_list *dl;
	
	dl = new_dl(size, int);
	
	push(dl, 10);
	push(dl, 2);

	int a = *( (int *) pop(dl));
	printf("%d\n", dl);

	return 0;
}

