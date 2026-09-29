/***********************

WEEK 3 Lab - SKELETON

Kate Bohning
Data Structures Week 3, Lab 3
Linked lists/Doubly linked lists

**********************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TYPE double

/*links with forward (next) and back (prev) pointers*/
struct DLink {
    TYPE value;
    struct DLink *next;
    struct DLink *prev;
};

/*doubly linked list contains a sentinel (head) link along with size*/
struct List {
    struct DLink *head;
    int size;
};

/*
    function: initList - memory is allocated for head sentinel and the doubly linked list is initialized
    param1 - lst - doubly linked list
    pre: lst is not null
    post: memory has been allocated for head
    post: head->next points to NULL
    post: head->prev points to NULL
    post: size set to 0
*/
void initList(struct List *lst) { /* lst is the pointer, List is the name of the list */
    printf("List initialized\n");
    /* FIX ME */
    lst->head = malloc(sizeof(struct DLink)); /* Allocate size */
    lst->head->next = NULL; /* nothing in the head of list */
    lst->head->prev = NULL;

    lst->size = 0;
}

/*
    function: addFront - add new DLink to the front of the doubly linked list
    param1 - lst - doubly linked list
    param2 - val - value to insert
    pre: lst is not null
    post: memory for a new DLink has been allocated dynamically
    post: new DLink has value - val
    post: new DLink has been added to the front of the doubly linked list - pointers have been updated
    post: head->next points to the new link
*/
void addFront(struct List *lst, TYPE val) {
    printf("addFront: %.1f \n", val);
    /* FIX ME */
    struct DLink *temp = malloc(sizeof(struct DLink));
    temp->value = val;
    temp->next = lst->head->next;
    temp->prev = lst->head;

    if(lst->size == 0)
    {
        printf("empty list\n");
        lst->head->next = temp;
    }
    else
    {
        printf("non-empty list\n");
        lst->head->next->prev = temp;
        lst->head->next = temp;
    }
    lst->size++;
}

/*
    function: addBack- add new DLink to the back of the doubly linked list
    param1 - lst - doubly linked list
    param2 - val - value to insert
    pre: lst is not null
    post: memory for a new DLink has been allocated dynamically
    post: new DLink has value - val
    post: new DLink has been added to the back of the doubly linked list - pointers have been updated
*/
void addBack(struct List *lst, TYPE val) {
    printf("addBack: %.1f \n", val);
    /* FIX ME */
    struct DLink *temp = malloc(sizeof(struct DLink));
    temp->value = val;
    temp->next = NULL;

    if (lst->size == 0)
    {
        printf("empty list\n");
        lst->head->next = temp;
        temp->prev = lst->head;

    }
    else
    {
        printf("non-empty list\n");
        struct DLink *iter = lst->head;
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        temp->prev = iter;
        iter->next = temp;
    }
    lst->size;
}

/*
    function: printForward - print from front DLink to back DLink
    param1 - lst - doubly linked list
    pre: lst is not null
    post: lst has been printed forward to standard output -  output is separated by spaces
    post: no changes to the list
*/
void printForward(struct List *lst) {
    printf("Print list: ");
    /* FIX ME */
    struct DLink *curr = lst->head->next;
    while (curr != NULL)
    {
        printf("%.1f ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

/*
    function: printBackward - print from back DLink to front DLink
    param1 - lst - doubly linked list
    pre: lst is not null
    post: lst has been printed backwards to standard output -  output is separated by spaces
    post: no changes to the list
*/
void printBackward(struct List *lst) {
    printf("Print list backwards: ");
    /* FIX ME */
    struct DLink *curr = lst->head;
    while (curr->next != NULL)
    {
        curr = curr->next;

    }
    while (curr != lst->head)
    {
        printf("%.1f ",curr->value);
        curr = curr->prev;
    }
    printf("\n");
}

/*
    function: removeFront - front DLink is removed from the doubly linked list
    param1 - lst - doubly linked list
    pre: lst is not null
    pre: lst is not empty
    post: a DLink has been removed from front of the doubly linked list - pointers have been updated
    post: the DLink has been freed
*/
void removeFront(struct List *lst) {
    printf("removeFront\n");
    /* FIX ME */
    struct DLink *del_iter = lst->head->next;
    lst->head->next = del_iter->next;

    if (lst->size > 1)
    {
        del_iter->next->prev = lst->head;
    }
    free(del_iter);
    lst->size--;

}

/*
    function: removeBack - back DLink is removed from the doubly linked list
    param1 - lst - doubly linked doubly linked list
    pre: lst is not null
    pre: lst is not empty
    post: a DLink has been removed from back of the doubly linked list - pointers have been updated
    post: the DLink has been freed
*/
void removeBack(struct List *lst) {
    printf("removeBack\n");
    /* FIX ME */
    struct DLink *del_iter = lst->head;
    struct DLink *prev = del_iter;

    while (del_iter->next != NULL)
    {
        prev = del_iter;
        del_iter = del_iter->next;
    }
    prev->next = NULL;
    free(del_iter);
    lst->size--;
}


int main() {
	struct List *lst = malloc(sizeof(struct List));
	initList(lst);

	printf("------------testing addFront()------------\n");

	addFront(lst, 2);
	printForward(lst);
	printBackward(lst);
	addFront(lst, 8);
	printForward(lst);
	printBackward(lst);

	printf("------------testing addBack()------------\n");

	addBack(lst, 1);
	printForward(lst);
	printBackward(lst);
	addBack(lst, 7);
	printForward(lst);
	printBackward(lst);

	printf("------------testing removeFront()------------\n");

	removeFront(lst);
	printForward(lst);
	printBackward(lst);

    printf("------------testing removeBack()------------\n");

	removeBack(lst);
	printForward(lst);
	printBackward(lst);

	return 0;
}
