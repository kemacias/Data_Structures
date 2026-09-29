#ifndef __DEQUE_H
#define __DEQUE_H

# ifndef TYPE
# define TYPE double
# define TYPE_SIZE sizeof(double)
# endif

/*links with forward pointers*/
struct Link {
    TYPE value;
    struct Link *next;
};

/*deque - doubly linked list contains head and tail pointers along with size*/
struct Deque {
    struct Link *head;
    struct Link *tail;
    int size;
};


void initList(struct Deque *d);
void addFront(struct Deque *d, TYPE val);
void addBack(struct Deque *d, TYPE val);
void print(struct Deque *d);
void printReverse(struct Link *curr);
TYPE getFront(struct Deque *d);
TYPE getBack(struct Deque *d);
void removeFront(struct Deque *d);
void removeBack(struct Deque *d);
void freeDeque(struct Deque *d);

#endif
