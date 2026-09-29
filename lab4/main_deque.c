/*#include <malloc.h>*/
#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main() {
	struct Deque *d = malloc(sizeof(struct Deque));
	initList(d);

	printf("------------testing addFront()------------\n");
	addFront(d, 2);
	print(d);
	addFront(d, 8);
	print(d);

	printf("------------testing getFront() / getBack()------------\n");
	printf("Testing getFront(): %.1f\n", getFront(d));
	printf("Testing getBack(): %.1f\n", getBack(d));

	printf("------------testing addBack()------------\n");
	addBack(d, 1);
	print(d);
	addBack(d, 7);
    print(d);

	printf("------------testing getFront() / getBack()------------\n");
	printf("Testing getFront(): %.1f\n", getFront(d));
	printf("Testing getBack(): %.1f\n", getBack(d));

	printf("Printing in reverse: ");
	printReverse(d->head);
	printf("\n");

	printf("------------testing removeFront()------------\n");
	removeFront(d);
	print(d);
	removeFront(d);
	print(d);

    printf("------------testing removeBack()------------\n");
	removeBack(d);
	print(d);
	removeBack(d);
	print(d);

	freeDeque(d);

	return 0;
}
