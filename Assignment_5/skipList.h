#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

#define TYPE int

/*
sLink is a skip link struct
value is the value stored in the skip link
level is the level of the skip link
next is a pointer to an array of pointers
*/
struct sLink {
    TYPE value;
    int level;
    struct sLink **next;
};

/*
skipLisst skip list struct
maxlevel determines the size of the sentinel array of pointers
currMax is the highest level of a node in the skiplist at a given time
size is the number of skiplinks in the list
sentinel contains pointers to every potential level of the skiplist
*/
struct skipList {
    int maxLevel;
    int currMax;
    int size;
    struct sLink *sentinel;
};

void initSkipList(struct skipList *lst, int maxLvl);
int levelGen(struct skipList *lst);
void addValTest(struct skipList *lst, TYPE val, int lvl);
void addVal(struct skipList *lst, TYPE val);
int searchVal(struct skipList *lst, TYPE val);
void printLv(struct skipList *lst, int lv);
int getSize(struct skipList *lst);
void removeLink(struct skipList *lst, TYPE val);
void deleteList(struct skipList *lst);
void staticTest(struct skipList *lst);
void test(struct skipList *lst);
