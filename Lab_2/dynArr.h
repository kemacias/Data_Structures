/*dynArr.h : Dynamic Array implementation*/

#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED 1


typedef struct DynArr DynArr;

/*Dynamic Array Functions*/
void initDynArr(DynArr *d, int cap);
DynArr *createDynArr(int cap);
void deleteDynArr(DynArr *d);
int sizeDynArr(DynArr *d);
void addDynArr(DynArr *d, int val);
int getDynArr(DynArr *d, int pos);
void putDynArr(DynArr *d, int pos, int val);
void removeAtDynArr(DynArr *d, int pos);
void dispArr(DynArr *d);

/*Stack Interface*/
void push(DynArr *d, int val);
void pop(DynArr *d);
int peek(DynArr *d);

#endif

