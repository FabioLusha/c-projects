#include <stdio.h>
#include <stdlib.h>

typedef struct int_dynamic_list
{
    int size;
	/*TODO add struct to to keep trace of the empty positions*/
    int next_free;
    int* array;

} int_dynamic_list;

int_dynamic_list *new_dl(int size){
    if(size < 1)
        return NULL;

    int_dynamic_list *dl= (int_dynamic_list *) malloc(sizeof dl);
    if(dl == NULL)
        return NULL;

    void *int_dynamic_arr = malloc( sizeof(int) * size);
    if(int_dynamic_arr == NULL){
        free(dl);
        return NULL;
    }

    dl->array = int_dynamic_arr;
    dl->size = size;
    dl->next_free = 0;

    return dl;
}

int *add(int_dynamic_list *dl, int *elem, int pos){

	if(dl->size <= pos){
		int *dy_arr = realloc(dl->array, sizeof(int)*2*dl->size);
		if(dy_arr == NULL)
			return NULL;
		dl->size *= 2;
	}
	
	*(dl->array+pos) = *elem;

	return dl->array+pos;

}

int *get(int_dynamic_list *dl, int pos){
	if(pos >= dl->size)
		return NULL;

	return dl->array+pos;
};

void push(int_dynamic_list *dl, int* elem){
    
    if(dl->next_free < dl->size)
         *( (dl->array) + (dl->next_free++) ) = *elem;   

}

int *pop(int_dynamic_list *dl){
    return (dl->array)+(--(dl->next_free));
}

int main(){
	int size = 10;

	int_dynamic_list *dl = new_dl(size);
	
	if(dl == NULL)
		printf("error: couldn't initialize dynamic list\n");

	int a = 10, b = 2, c = 10;

	add(dl, &c, 11);
	int el = *get(dl, 11);
	printf("%d\n", el);

	return 0;
}
