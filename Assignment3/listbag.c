#include "listbag.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/*Kate Bohning
Data Structures Week 3
Linked Lists Assignment 3 */

/*Turn on for debugging messages*/
int debug = 0;

/*
	initlist: initialize the list - create the head and initialize pointers
	param: lst is the list
	pre: lst is not null
	post: memory has been dynamically allocated for the head
	post: head next is initialized to NULL
*/
void initList (struct List *lst) {
	assert(lst != NULL);
	lst->head = malloc(sizeof(struct Link));
	lst->head->next = NULL;
}

/*
	addFrontList: add a value to the front of the list
	param: head is the head of the list
	param: e is the value to add to the list
	pre: head is not null
	post: memory has been dynamically allocated for a new link
	post: new link is added to the front of the list
	HINT - Notice that we are passing the head of the list as opposed ot the list
*/
void addFrontList (struct Link *head, TYPE e) {
	if(debug)printf("Inserting %d at head of list\n", e);
	/* FIX ME*/
	struct Link *newNode = malloc(sizeof(struct Link));
	newNode->value = e;
	newNode->next = head->next;
	head->next = newNode;
}

/*
	addBackList: add a value to the back of the list
	param: head is the front of the list
	param: e is the value to add to the list
	pre: head is not null
	post: memory has been dynamically allocated for a new link
	post: new link is added to the back of the list
*/
void addBackList(struct Link *head, TYPE e) {
	if(debug) printf("Inserting %d at back of list\n", e);
	/* FIX ME*/
	struct Link *newNode = malloc(sizeof(struct Link));
	newNode->value = e;
	newNode->next = NULL;
	struct Link *curr = head;
	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = newNode;


}

/*
	displayList: print the contents of the list
	param: head is the front of the list
	pre: head is not null
	pre: list is not empty
	post: list contents are displayed - separated by spaces
	post: no changes to the list
*/
void displayList (struct Link *head) {
    printf("List Contents: ");
	/* FIX ME*/
	struct Link *curr = head;
	while(curr != NULL)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n");
}

/*
	frontList: return the element at the head of the list
	param: head is the front of the list
	return: return value at front of the list
	pre: head is not null
	pre: list is not empty
	post: no changes to the list
*/
TYPE frontList (struct Link *head) {
	/* FIX ME*/
	return head->value;
}

/*
	backList: return the element at the back of the  list
	param: head is the front of the list
    return: return value at back of the list
	pre: head is not null
	pre: list is not empty
	post: no changes to the list
*/
TYPE backList(struct Link *head) {
	/* FIX ME*/
	struct Link *curr = head;
	while(curr->next != NULL)
	{
		curr = curr->next;
	}
    return curr->value;
}


/*
	removeFrontList: remove element from front of list
	param: head is the front of the list
	pre: head is not null
	pre: list is not empty
	post: head points to head->next
	post: old head has been freed
*/
void removeFrontList(struct Link *head) {
	if(debug) printf("remove front of list: \n");
	/* FIX ME*/
	struct Link *curr = head->next;
	head->next = curr->next;
	free(curr);
	/* every time i free(curr) it breaks my displayList function. */
}

/*
	removeBackList:	remove element from back of list
	param: head is the front of the list
	pre: head is not null
	pre: list is not empty
	post: link before the end points to NULL
	post: old head has been freed
*/
void removeBackList (struct Link *head) {
	if(debug) printf("remove back of list: \n");
	/* FIX ME*/
	if (head->next == NULL)
	{
		free(head);
		return;
	}
	struct Link *curr = head;
	while (curr->next->next != NULL)
	{
		curr = curr->next;
	}
	free(curr->next);
	curr->next = NULL;
}

/*
	listRemove: remove the first occurrence of the value from the list
	param: head is the front of the list
	param: e is the value to remove
	pre: head is not null
	pre: list is not empty
	post: link containing  first occurrence of value e has been freed
	post: pointer before link containing  first occurrence of value has been updated
*/
void listRemove (struct Link *head, TYPE e) {
	if(debug) printf("remove %d from list: \n", e);
	/* FIX ME*/
	struct Link *curr = head;
	struct Link *prev = NULL;
	while (curr != NULL && curr->value != e)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL) return;
	if (prev == NULL)
	{
		head->next = curr->next;
	}
	else {
		prev->next = curr->next;
	}
	free(curr);
}

/*
	isEmptyList: checks whether the list is empty or not
	param: head is the front of the list
    return: Return 1 if empty, 0 if not
	pre: head is not null
	post: no changes to the list
*/
int isEmptyList(struct Link *head) {
	assert(head != NULL);
	if(head->next == NULL) {
		return 1;
	}
	return 0;
}

/*
	freeList: Free the list
	param: head is the front of the list
	pre: head is not null
	post: each link of the list has been freed
	post: lst has been freed
	post: lst points to nothing
*/
void freeList(struct List *lst) {
	/* FIX ME*/
	struct Link *curr = lst->head;
	struct Link *next;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	lst = NULL;
}


/* -----------------------ListBag functions begin here---------------------- */


/*
	initBag: initialize bag
	param: b is the bag
	pre: b is not null
	post: memory for list is dynamically allocated
	post: lst is initialized using initList()
	post: size  is initialized to 0
*/
void initBag(struct bag* b) {
	assert( b != NULL);
	b->lst = (struct List*)malloc(sizeof(struct List));/*Allocate for the list part of the bag*/
	initList(b->lst);/*Initialize list*/
	b->size=0;
}

/*
	addToBag: add an element to the bag
	param: b is the bag
	param: val is the value added to the bag
	pre: b is not null
	post: val is added to the bag (list implementing the bag)
	post: size is incremented
	HINT: use linked list functions to manipulate the list
	HINT: You will pass the head of the list which is part of the bag (b->list->head)
*/
void addToBag(struct bag* b, TYPE val) {
 	/* FIX ME*/
	addFrontList(b->lst, val);
	b->size++;
}

/*
	bagContains: test if an element exists in the bag
	param: b is the bag
	param: val is the value to search for
    return: return 1 if found, otherwise return 0
	pre: b is not null
	post: no changes to the bag
*/
int bagContains(struct bag* b, TYPE val) {
	/* FIX ME*/
	assert(b != NULL);
	struct Link* curr = b->lst->head;
	while (curr != NULL)
	{
		if (curr->value == val)
		{
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

/*
	removeFromBag: remove an element from the bag
	param: b is the bag
	param: val is the value to remove from the bag
	pre: b is not null
	pre: b contains val - use bagContains()
	post: link is removed from bag
	post: size is decremented
	HINT: use linked list functions to manipulate the list
*/
void removeFromBag(struct bag* b, TYPE val) {
	/*FIX ME*/
	assert(b != NULL);
	struct Link *curr = b->lst->head;
	struct Link *prev = NULL;
	while (curr != NULL)
	{
		if (curr->value == val)
		{
			if (prev == NULL)
			{
				b->lst->head = curr->next;
			}
			else
			{
				prev->next = curr->next;
			}
			free(curr);
			b->size--;
			return;
		}
		prev = curr;
		curr = curr->next;
	}

}

/*
	isEmptyBag: test if the bag is empty
	param: b is the bag
	return: return 1 if found, otherwise return 0
	pre: b is not null
	post: no changes to the bag
*/
int isEmptyBag(struct bag* b) {
	/* FIX ME*/

    return (b->size == 0) ? 1 : 0;
}

/*
	freeBag: deallocate bag memory
	param: b is the the bag
	pre: b is not null
	post: bag is freed
	post: list is freed
	HINT: use linked list functions to manipulate the list
*/
void freeBag(struct bag *b) {
	/* FIX ME*/
	freeList(b->lst);
	free(b);

}

/*-------------------- Pt II - Algorithm Analysis --------------------------*/

/*

#1 - What is the worst case performance of the removeFromBag() operation expressed in terms of the size of the bag(n)? Describe the worst case in words.(2 Pt)
worst case - O(n) when the value is not present or it is at the end of the list.

#2 - What is the best case performance of the removeFromBag() operation expressed in terms of the size of the bag(n)? Describe the best case in words. (2 Pts)
Best case - o(1) the value is the first item in the list.
#3 - What is the average number of comparisons that removeFromBag() performs expressed in terms of the size of the bag(n)? (1 Pt)
about one half of the size of the bag, where n is the number of items in the bag. (n+1/2)
#4 - What is the worst case performance for the addToBag() operation?  (1 Pts)
it is 0(1). it allocates space, and then adds the value no matter the size to the top of the bag.
#5 - What is the best case performance for the addToBag() operation? (1 Pts)
it is the same as worst case. both operations are exactly the same.
#6 - Did you use addFrontList() or addBackList() to add elements to your bag? Why was this the best choice? (2 Pts)
addFrontList() simply because it has less margine for error in my code and does not require traversing the list.
#7 - Is a linked list or a dynamic array a better choice for adding elements to a bag? Explain your answer. (3 Pts)
a Linked list is better because it is o(1) in complexity while a dynamic array is o(n) in complexity as it has to shift
all its elements around as you add things to the list. the linked list simply updates two pointers per addition.
*/



