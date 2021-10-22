#include <stdio.h>

void qsort(int *, int, int);

int main(){
	int len = 10, array[10] = {4, 9, 2, 5, 6, 1, 4, 7};

	qsort(array, 0, len);

	for(int i = 0; i < len; i++)
		printf("%d\n", array[i]);
}

void qsort(int *v, int left, int right){

	int i, last; 
	void swap(int *, int *);

	if(right <= left)
		return;

	swap(v+left, v+(left+right)/2);
	last = left;

	for(i = left+1; i < right; i++)
		if(v[i] < v[left])
			swap(v+i, v+(++last));

	swap(v+left, v+last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(int *i, int *j){
	int tmp = *j;
	*j = *i;
	*i = tmp;
}
