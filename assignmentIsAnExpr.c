#include <stdio.h>

main() {

	int c = 2,a;
	
	printf("c is: %d\n", c);
	a = 2 * (c = 3);
	printf("after a = 2 * (c = 3), c is: %d", c);

}
