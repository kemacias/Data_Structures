#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*Kate Bohning
 *Data Structures
 *Heap Implimentation - Week 8 */


#define TYPE float

struct DynArr {
	TYPE *data;	/* pointer to the data array */
	int size; /* Number of elements in the array */
	int capacity; /* capacity of the array */
};

struct Heap {
    struct DynArr *d;
};

void _percolateUp(struct Heap *h);
float _percolateDown(struct Heap* h);


/*
	initDynArr: Initialize (including allocation of data array) dynamic array.
	param1: d - pointer to the dynamic array
	param2 : capacity - capacity of the dynamic array
	pre: d is not null
	pre: capacity > 0
	post: memory is allocated for data array that can hold cap elements of type TYPE
	post: size is 0
	post: capacity is set
*/
void initDynArr(struct DynArr *d, int capacity) {
	assert(capacity > 0);
	assert(d != NULL);

	d->data = malloc(sizeof(TYPE) * capacity);
	assert(d->data != NULL);
	d->size = 0;
	d->capacity = capacity;
}

/*
	createDynArr: Allocate and initialize dynamic array.
	param: cap desired capacity for the dynamic array
	pre: cap > 0
	post: memory is allocated for a a dynamic array
	ret: a pointer to an empty dynArr of cap capacity
*/
struct DynArr *createDynArr(int cap) {
	assert(cap > 0);

	struct DynArr *dyn;
	dyn = malloc(sizeof(struct DynArr));
	if(!dyn) {
		printf("Failed to allocate memory \n");
	}
	initDynArr(dyn,cap);
	return dyn;
}

/*
	addDynArr: Adds an element to the end of the dynamic array
	param: d pointer to the dynamic array
	param: val the value to add to the end of the dynamic array
	pre: the dynArry is not null
	post: size increases by 1
	post: if reached capacity, capacity is doubled
	post: val is in the last utilized position in the array
*/
void addDynArr(struct DynArr *d, TYPE val) {
	assert(d != NULL);

	/* If full, then re-size */
	if(d->size >= d->capacity) {
		d->capacity *= 2;
		d->data = realloc(d->data, d->capacity);
	}
	d->data[d->size] = val;
	d->size++;
}


/*
	putDynArr: Put an item into the dynamic array at the specified location, overwriting the element that was there
	param1: d - pointer to the dynamic array
	param2: pos - the index to put the value into
	param3: val	- the value to insert
	pre: d is not null
	pre: pos >= 0 and pos
	pre: pos < capacity
	post: index (pos) contains new value (val)
*/
void putDynArr(struct DynArr *d, int pos, TYPE val) {
	assert(d != NULL);
    assert(pos >= 0);
	assert(pos < d->capacity);

	d->data[pos] = val;
}


/*
	swapDynArr: Swap two specified elements in the dynamic array
	param1: d - pointer to the dynamic array
	param2: i - one of the elements to be swapped
	param3: j - one of the elements to be swapped
	pre: d is not null
	pre: d is not empty
	pre: i >= to 0
	pre: j >= to 0
	pre: i < size of the dynamic array
	pre: j < size of the dynamic array
	post: index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(struct DynArr *d, int i, int  j) {
	TYPE  temp;
	assert(d != NULL);
	assert(i < d->size);
	assert(j < d->size);
	assert(i >= 0);
	assert(j >= 0);

	temp = d->data[i];
	d->data[i] = d->data[j];
	d->data[j] = temp;
}


/*
	getValDynArr: Return the value from the specified index position from a dynamic array
	param1: d - pointer to the dynamic array
	param2: pos - location of element to remove
	return: value at the specified index position
	pre: d is not null
	pre: d is not empty
    pre: pos >= 0
	pre: pos < size
	post: no changes to the dynamic array
*/
TYPE getValDynArr(struct DynArr *d, int pos) {
	assert(d != NULL);
	assert(pos < d->size);
	assert(pos >= 0);

    return d->data[pos];
}


/*
	removeAtDynArr: Remove the element at the specified location from the array, shifts other elements back one to fill the gap
	param1: d - pointer to the dynamic array
	param2: pos - location of element to remove
	pre: d is not null
	pre: d is not empty
    pre: pos >= 0
	pre: pos < size
	post: the element at pos is removed
	post: the elements past pos are shifted back one
*/
void removeAtDynArr(struct DynArr *d, int pos) {
	assert(d != NULL);
	assert(pos < d->size);
	assert(pos >= 0);

   /* Shift all elements*/
   int i;
   for(i = pos; i < d->size-1; i++){
      d->data[i] = d->data[i+1];
   }
   d->size--;
}


/*
	printDynArr: Print the contents of the dynamic array
	param: heap - the dynamic array
	pre: d is not NULL
	post: the values are printed from the first to last positions in the array
	post: no changes to the dynamic array
*/
void printDynArr(struct DynArr *d) {
    assert(d != NULL);

    int i = 0;
    while(i < d->size) {
        printf("%.1f ", d->data[i]);
        i++;
    }
    printf("\n");
}

/*
	----------------------------------- Heap-based priority queue implementation -----------------------------------
*/

/*
    initHeap: initialize max-heap
	param1: h - pointer to the max-heap
	param2: cap - the capacity of the underlying dynamic array
	pre: h is not null
	pre: cap > 0
	post: memory is allocated to the dynamic array - use createDynArr()
*/
void initHeap(struct Heap *h, int cap) {
    assert(h != 0);
    assert(cap > 0);
    h->d = createDynArr(cap);
}


/*
    pushHeap: add a value to the max-heap
	param1: h - pointer to the max-heap
	param2: val - value to be added to the max-heap
	pre: heap is not null
	post: node is added to the heap
	post: underlying array has added an item to the correct position
	post: heap properties are maintained
	HINT: call _percolateUp
*/
void pushHeap(struct Heap *h, TYPE val) {
	printf("adding %.1f\n", val);
	/* FIXME */
	assert(h != NULL);

	addDynArr(h->d, val);
	_percolateUp(h);


}


/*
    _percolateUp: swap a value up into place in a max-heap
	param1: h - pointer to the max-heap
	pre: none
	post: heap properties are maintained
	called by pushHeap
*/
void _percolateUp(struct Heap *h) {
	/* FIXME */
	int pos = h->d->size-1;
	int parent = (pos-1)/2;

	while (parent >= 0)
	{
		if (h->d->data[pos] > h->d->data[parent])
		{
			swapDynArr(h->d, parent, pos);
			pos = parent;
			parent = (pos-1)/2;
		}
		else
		{
			return;
		}
	}

}


/*
    popHeap: remove the root of the max-heap
	param1: h - pointer to the max-heap
	pre: heap is not null
	pre: heap is not empty
	post: node is removed from the heap
	post: heap properties are maintained
	HINT: call _percolateDown
*/
void popHeap(struct Heap *h) {
	printf("popping %.1f\n", getValDynArr(h->d, 0));
	/* FIXME */
    assert(h != NULL);
	assert(h->d->size > 0);

	swapDynArr(h->d, 0, h->d->size-1);
	removeAtDynArr(h->d, h->d->size-1);


}


/*
   	_percolateDown: swap the root down into place in a max-heap
	param1: h - pointer to the max-heap
	post: heap properties are maintained
	called by popHeap
*/
float _percolateDown(struct Heap* h)
{
	/* FIXME */
	int parent = 0;
	int lChild = parent*2+1;
	int rChild = parent*2+2;
	int greater = 0;

	while (lChild <= h->d->size-1)
	{
		if (lChild == h->d->size-1)
		{
			greater = lChild;
		}
		else if (h->d->data[lChild] > h->d->data[rChild])
		{
			greater = lChild;
		}
		else
		{
			greater = rChild;
		}
		if (h->d->data[greater] > h->d->data[parent])
		{
			swapDynArr(h->d, greater, parent);
			parent = greater;
			lChild = parent*2+1;
			rChild = parent*2+2;
		}
		else
		{
			return;
		}
	}
}



/*
	getHeapMax: Get the value from first node in the max-heap
	param: h - pointer to the heap
	pre: heap is not null
	pre: heap is not empty
    return: value of first node's value
	pre: heap is not empty
*/
TYPE getHeapMax(struct Heap *h) {
	/* FIXME */
	assert(h != NULL);
	assert(h->d->size > 0);

	return h->d->data[0];
}


/*
	freeHeap: Free the memory for the heap and the underlying dynArr
	param: h - pointer to the heap
	pre: h is not NULL
    return: none
	post: memory has been freed for the array in DynArr
	post: memory has been freed for DynArr
	post: memory has been freed for heap
*/
void freeHeap(struct Heap *h) {
    assert(h != NULL);
	
    free(h->d->data);
    h->d->data = 0;

    free(h->d);
    h->d = 0;

    free(h);
    h = 0;
}



int main() {
	struct Heap *heap = malloc(sizeof(struct Heap));

	initHeap(heap, 16);

	printf("-------------TESTING PUSH-------------\n");
	pushHeap(heap, 7);
	pushHeap(heap, 12);
	pushHeap(heap, 3);
	pushHeap(heap, 5);
	pushHeap(heap, 4);
	pushHeap(heap, 11);
	pushHeap(heap, 6);
	printf("Should print: 12.0 7.0 11.0 5.0 4.0 3.0 6.0\n");
	printDynArr(heap->d);

	printf("-------------TESTING POP-------------\n");

	popHeap(heap);
	printf("Should print: 11.0 7.0 6.0 5.0 4.0 3.0 \n");
	printDynArr(heap->d);

	popHeap(heap);
    printf("Should print: 7.0 5.0 6.0 3.0 4.0 \n");
	printDynArr(heap->d);

    freeHeap(heap);
	heap = 0;


	return 0;
}
