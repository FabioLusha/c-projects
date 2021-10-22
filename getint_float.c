#include <stdio.h>
#include <ctype.h> /* for isspace(int), isdigit(int) */
#include <math.h>

#define SIZE 10



int main(){
	int n, m, array[SIZE], getint(int *);
	float farray[SIZE], getfloat(float *);

	for(n = 0; n < SIZE && getfloat(&farray[n]) != EOF; n++)
		;

	int j;
	printf("\n");
	for(j = 0; j < n; j++)
		printf("%f\n", farray[j]);
}


int getch(void);
void ungetch(int);

int getint(int *pn){

	int c, sign;

	while( isspace( c = getch() ))
		;

	if( !isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0; /* not a number */
	}

	sign = c == '-' ? -1 : 1;
	if(c == '+' || c == '-')
		c = getch();

	if(isdigit(c)) {
		for(*pn = 0; isdigit(c); c = getch())
			*pn = 10 * *pn + (c - '0');
		*pn *= sign;
	}else
		ungetch(c);

	if( c != EOF)
		ungetch(c);
	return c;
}


float getfloat(float *pn){
	int c, sign, integer, exp;
	float decimal;

	while(isspace ( c = getch()))
		;

	if( !isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0; /* not a number */
	}
	
	sign = c == '-' ? -1 : 1;
	if(c == '+' || c == '-')
		c = getch();

	if(isdigit(c)) {
		for(integer = 0; isdigit(c); c = getch())
			integer = 10 * integer + (c - '0');
		decimal = 0.0;
		exp = 1;


		int mag_order;
		if( c == '.'){
			if( isdigit(c = getch()) ){
				for(decimal = 0, mag_order = 0; isdigit(c); c = getch(), mag_order++)
					decimal = 10 * decimal + (c - '0');
			}
			else {
				ungetch(c);
				return 0; /* format not correct */
			}
		}

		if( decimal != 0)
			decimal /= pow(10, mag_order);

		if( c == 'e' || c == 'E'){

			int expsign;
			expsign = (c = getch()) == '-' ? -1 : 1;

			if(c == '+' ||  c == '-')
				c = getch();


			if( isdigit(c) ){
				for(exp = 0; isdigit(c); c = getch())
					exp = 10 * exp + (c - '0');
			}
			else{
				ungetch(c);
				return 0; /* format not correct */
			}

		exp *= expsign;
		}
		

		*pn = pow( integer + decimal, exp);
	}else
		ungetch(c);

	if( c != EOF)
		ungetch(c);
	return c;
}

