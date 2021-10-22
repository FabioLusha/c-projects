#include <stdio.h>
#define SIZE 100 /* stack size*/

double stack[SIZE];
int sp = 0;  /* next free stack position*/

void push(double f){
	if( sp < SIZE)
		stack[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void){
	if(sp > 0)
		return stack[--sp]; /* return the first avilable element, sp points to the next free cell */
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
