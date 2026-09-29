/*
testDynArray.c
This file is used for testing the dynArr.c file
 */
#include <stdio.h>
#include <stdlib.h>
#include "dynArr.h"

void assertTrue(int predicate, char *message) {
	printf("%s: ", message);
	if (predicate)
		printf("Pass \n");
	else
		printf("Fail \n");
}

/*this main function contains some tests for your dynamic array and stack implementations*/
int main(int argc, char* argv[]){
	DynArr *dyn;
	dyn = createDynArr(2);

	printf("------------Inserting using addDynArr------------\n");
	addDynArr(dyn, 5);
	addDynArr(dyn, 6);
	addDynArr(dyn, 9);

	printf("The array's contents should be: [5, 6, 9] \n");
	dispArr(dyn);

	assertTrue(getDynArr(dyn, 0) == 5, "Test 0th element == 5");
	assertTrue(getDynArr(dyn, 1) == 6, "Test 1st element == 6");
	assertTrue(getDynArr(dyn, 2) == 9, "Test 2nd element == 9");
	assertTrue(sizeDynArr(dyn) == 3, "Test size = 3");

	printf("------------Testing putDynArr------------\n\n");
	putDynArr(dyn, 2, 7);
	printf("The array's content: [5, 6, 7] \n");
	dispArr(dyn);
	assertTrue(getDynArr(dyn, 2) == 7, "Test 2nd element == 7");
	assertTrue(sizeDynArr(dyn) == 3, "Test size = 3");

	printf("------------Testing removeAtDynArr------------\n\n");
	removeAtDynArr(dyn, 1);
	printf("The array's content: [5, 7] \n");
	dispArr(dyn);
	assertTrue(getDynArr(dyn, 0) == 5, "Test 0th element == 5");
	assertTrue(getDynArr(dyn, 1) == 7, "Test 1st element == 7");
	assertTrue(sizeDynArr(dyn) == 2, "Test size = 2");

	deleteDynArr(dyn);

	printf("------------***** TESTING STACK INTERFACE *****------------\n");

	DynArr *stack;
	stack = createDynArr(2);

	printf("Testing push........... \n");
	push(stack, 12);
	push(stack, 6);
	push(stack, 13);

	printf("The stack's content: [12, 6, 13]\n");
	dispArr(stack);

	printf("Testing peek........... \n");
	assertTrue(peek(stack) == 13, "Test peek == 13");

	printf("pop........... \n");
	pop(stack);

	printf("The stack's content: [12, 6]\n");
	dispArr(stack);

	printf("Testing peek........... \n");
	assertTrue(!(peek(stack) == 13), "Test peek == 13");
	assertTrue(peek(stack) == 6, "Test peek == 6");

	return 0;
}
