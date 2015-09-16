/*
 ============================================================================
 Name        : ECG.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"
//#include "Filters.h"


#define MAX 50
int size;

// Defining the stack structure
struct stack {
   int arr[MAX];
   int top;
};

 //Initializing the stack(i.e., top=-1)
void initializestack(struct stack *st, int n) {
   st->top = n -1;
   for (int i = st->top ; i >= 0; i--) {
        st->arr[i] = 0;
  }
}

// Entering the elements into stack
void newSignal(struct stack *st, int num) {

	for (int i = st->top; i > 0; i--){
		st->arr[i] = st ->arr[i-1];
	}
	st->arr[0] = num;


}

int sum(struct stack *st) {
	int sum;
	for (int i = st->top ; i >= 0; i--) {
		//printf("Sum %i: %i",i +1, sum );
	        sum = sum + st->arr[i] ;
	        //printf("Sum %i: %i\n",i +1, sum );
	  }
	return sum;
}

//Deleting an element from the stack.

void display(struct stack *st) {
	int i;
	for (i = 0; i < st->top; i++){
		printf("%d, ", st->arr[i]);
	}
   printf("%d\n", st->arr[i]);
}

int main() {

	//int n = 2500;

	struct stack signal;
	initializestack(&signal, 13);

	struct stack lp;
	initializestack(&lp, 33);

	struct stack hp;
	initializestack(&hp, 5);

	struct stack der;
	initializestack(&der, 1);

	struct stack sq;
	initializestack(&sq, 30);

	struct stack mwi;
	initializestack(&mwi, 30);

	int i = 0;
	while(fileNotEmpty()) {
		newSignal(&signal, getNextData());
		newSignal(&lp, lowpass(lp.arr[1-1], lp.arr[2-1], signal.arr[0], signal.arr[6], signal.arr[12]));
		newSignal(&hp, highpass(hp.arr[0], lp.arr[0], lp.arr[16], lp.arr[17], lp.arr[32]));
		newSignal(&der, derivative(hp.arr[0], hp.arr[1], hp.arr[3], hp.arr[4]));
		newSignal(&sq, squared(der.arr[0]));
		newSignal(&mwi, mwiFilter(sum(&sq)));

		printf("%i. = %i\n",i +1, mwi.arr[0]);
		i++;
	}
	display(&mwi);

}

