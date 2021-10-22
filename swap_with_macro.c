#include <stdio.h>
#define swap(t,x,y) t SWAP = x;x = y; y = SWAP; 
int cast(int num);

int main(){
	float a = 0.5, b = 0.7;

	printf("before swap\na: %f\tb: %f\n",a,b);
	swap(float, a, b);
	printf("after swap\na: %f\tb: %f\n",a,b);
}
