/* 	testDynArray.c
	This file is used for testing the dynamicArray.c file
 */
#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"


void assertTrue(int predicate, char *message) {
	printf("%s: ", message);
	if (predicate)
		printf("Pass \n");
	else
		printf("Fail \n");
}


/*this main function contains some*/
int main(){
	DynArr *dyn;
	dyn = createDynArr(2);

	printf("Testing addDynArr........... \n");
	addDynArr(dyn, 5);
	addDynArr(dyn, 8);
	addDynArr(dyn, 10);
	addDynArr(dyn, 12);
	addDynArr(dyn, 3);

	printf("The array's contents should be: [5, 8, 10 , 12, 3] \n");

	assertTrue(getDynArr(dyn, 0) == 5, "Test 0th element == 5");
	assertTrue(getDynArr(dyn, 1) == 8, "Test 1st element == 8");
	assertTrue(getDynArr(dyn, 2) == 10, "Test 2nd element == 10");
	assertTrue(getDynArr(dyn, 3) == 12, "Test 3rd element == 12");
	assertTrue(getDynArr(dyn, 4) == 3, "Test 4th element == 3");
	assertTrue(sizeDynArr(dyn) == 5, "Test size = 5");


	printf("------------Testing putDynArr------------\n Calling putDynArr(dyn, 2, 7) \n");
	putDynArr(dyn, 2, 7);
	printf("The array's content: [5, 8, 7, 12, 3] \n");
	assertTrue(getDynArr(dyn, 2) == 7, "Test 2nd element == 7");
	assertTrue(sizeDynArr(dyn) == 5, "Test size = 5");

	printf("-------------Testing swapDynArr------------\n Calling swapDynArr(dyn, 1, 3) \n");
	swapDynArr(dyn, 1, 3);
	printf("The array's content: [5, 12, 7, 8, 3] \n");
	assertTrue(getDynArr(dyn, 1) == 12, "Test 2nd element == 12");
	assertTrue(getDynArr(dyn, 3) == 8, "Test 4th element == 8");

	printf("------------Testing removeAtDynArr------------\n Calling removeAtDynArr(dyn, 1) \n");
	removeAtDynArr(dyn, 1);
	printf("The array's content: [5, 7, 8, 3] \n");
	assertTrue(getDynArr(dyn, 0) == 5, "Test 0th element == 5");
	assertTrue(getDynArr(dyn, 3) == 3, "Test 3rd element == 3");
	assertTrue(sizeDynArr(dyn) == 4, "Test size = 4");

	deleteDynArr(dyn);

	printf("------------***** TESTING BAG INTERFACE *****------------\n");

	DynArr *bag;
	bag = createDynArr(2);

	printf("Testing addBag........... \n");
	addBag(bag, 12);
	addBag(bag, 6);
	addBag(bag, 13);


	printf("The bag's content: [12, 6, 13]\n");

	printf("Testing containsBag........... \n");
	assertTrue(containsBag(bag, 12), "Test containing 12");
	assertTrue(containsBag(bag, 6), "Test containing 6");
	assertTrue(containsBag(bag, 13), "Test containing 13");
	assertTrue(!containsBag(bag, 10), "Test containing 10");


	removeBag(bag, 6);
	printf("Removing 6...\n The bag's content: [12,13] \n");

	printf("Testing containsBag........... \n");
	assertTrue(containsBag(bag, 12), "Test containing 12");
	assertTrue(containsBag(bag, 13), "Test containing 13");
	assertTrue(!containsBag(bag, 6), "Test containing 6");

	return 0;
}
