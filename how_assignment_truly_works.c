#include <stdio.h>

int main(){
	int a = 0x3, b = 0x5;
	int *pa = &a, *pb = &b;

	printf("value of a: %d\n", a);
	printf("value of b: %d\n", b);

	printf("addr of a: 0x%x\n", pa);
	printf("addr of b: 0x%x\n", pb);

	a = b;

	printf("a = b;\n");

	printf("value of a: %d\n", a);
	printf("value of b: %d\n", b);

	printf("addr of a: 0x%x\n", pa);
	printf("addr of b: 0x%x\n", pb);

	return 0;
}
