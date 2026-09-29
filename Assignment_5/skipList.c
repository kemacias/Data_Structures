#include "skipList.h"
/*#include <malloc.h>*/
#include <stdio.h>
#include <time.h>
#include <assert.h>

/*
	skip list implementation

	Uncomment #include <malloc.h for windows . I also added <stdio.h> instead for mac.
	it may need to be commented out for windows.

Kate Bohning
Data Structures - week 5
Implementation of skipped lists
*/


/*
	initSkipList: Skiplist is initialized - memory is allocated for the sentinel
	param1: lst - the list
	param2: maxLvl - maximum depth of the list
	pre: lst is not null
    pre: maxLvl is greater than 0
    post: rand() has been seeded
	post: memory is allocated to sentinel
	post: sentinel points to NULL at every level
	post: maxLevel is set to maxLvl - should be log n(size of list)
	post: currMax is set to 0
	post: size is set to 0
*/
void initSkipList(struct skipList *lst, int maxLvl) {
    assert(lst != NULL);
    assert(maxLvl > 0);
	printf("Initializing...\n");
	assert(lst != NULL);
	assert(maxLvl > 0);
    srand(time(NULL));

	lst->sentinel = malloc(sizeof(struct sLink));/* sentinel->next is the sentinel*/
	lst->sentinel->next = malloc(sizeof(struct sLink*)*(maxLvl));/* sentinel->next is an array with a pointer to every level */

    int i;
	for(i = 0; i < maxLvl; i++) {
		lst->sentinel->next[i] = lst->sentinel;/* sentinel points to the sentinel at every level */
	}/*for*/

	lst->maxLevel = maxLvl;/* max allowable levels */
	lst->currMax = 0;/* level of highest node currently */
	lst->size = 0;/* number of level 1 links */
}/*function*/


/*
	levelGen: Generate a random level for new links - probabilistically determined
	param1: lst - the list
	return: random level from 0 to lst->maxLevel - 1
	pre: lst is not null
	HINT: random levels are determined by a "series of coin flips"
	HINT: Each level is 50% less common than the last
	HINT: Approximately 50% are level 2, 25% are level 3, 12.5% are level 4, etc
	HINT: Each consecutive "heads" adds one to the level, at the first "tails" we have reached our level
	HINT: start at level 0 and add 1 for each heads
	HINT: random levels are capped at maximum level - 1
	HINT: random level can only exceed currMax by 1

	Ex: HHT = level 2, T = 0, THH = 0, HHHT = 3
*/
int levelGen(struct skipList *lst)
{
	/* FIX ME */
	assert (lst != NULL);
	int level = 0;
	while (rand() % 2 == 0 && level < lst->maxLevel)
	{
		level++;
		/*printf("levelGen: level = %d\n", level); */
	}
	return level;

}
/*
	addValTest: Adds a value to the skipList at a specified level - for testing purposes
	param1: lst - the list
	param2: val - the value to add
	param3: lvl - the level of the link
	pre: lst is not null
	pre: lvl >= 0
	pre: lvl < maxLevel
	post: memory has been allocated to the new skip link
	post: value has been set for the new skip link at each necessary level
	post: pointers have been adjusted at each necessary level
	HINT: currMax needs to get set in this function. Normally it happens in levelGen but we are not using it.
*/
void addValTest(struct skipList *lst, TYPE val, int lvl) {
	printf("inserting %d as a lvl %d node\n", val, lvl);
	assert(lst != NULL);
	assert(lvl < lst->maxLevel);
	assert(lvl >= 0);

	/* allocate memory for link to insert - extra space is allocated for the "height" of the link +1 (in case it is zero)*/
	struct sLink *insert = malloc(sizeof(struct sLink));
	insert->next = malloc(sizeof(struct sLink*)*(lvl+1));
	insert->value = val;
	insert->level = lvl;

    if(lvl > lst->currMax) {
        lst->currMax = lvl;
	}

	/*pointer for iterator node. Points to sentinel*/
	struct sLink *curr = lst->sentinel;

	/* FIX ME */
	/* add to the correct position for each level of the skip list less or equal to the link's level */
    /* HINT: Start at the top and work down */
	/* HINT: this is simply a test function - don't hesitate to put debugging statements in to help navigate */




}

/*
	addVal: Adds a new sLink to the skipList at a random level and maintains the skip list
	param1: lst - the list
	param2: val - the value to add
	pre: lst is not null
	post: a new sLink is added to the skip list at each necessary level with the specified value - level is generated randomly
	HINT - this is the same process as addValTest with one exception - you need to generate a level using LevelGen()
*/
void addVal(struct skipList *lst, TYPE val) {
	/* FIX ME */
	/* allocate memory for link to insert - extra space is allocated for the "height" of the link +1 (in case it is zero)*/


}

/*
	searchVal: Searches the skipList for a value
	param1: lst - the list
	param2: val - the search value
    pre: lst is not null
	post: return an integer greater than 0 if found - If not found, return 0
	Returns the number of comparisons  needed to find the value if found (will work as boolean return)
*/
int searchVal(struct skipList *lst, TYPE val) {
	printf("Searching for: %d\n", val);
	/* FIX ME */
	/* HINT - traversing the list is similar to the an insert */


	return 0;
}

/*
	printLv: Print the specified level of the list
	param1: lst - the list
	param2: lv - level of the list to print
	pre: lst is not null
	pre: lv is greater than or equal to 0 and not greater than list->maxLevel
	post: prints all of the values at a specified level
*/
void printLv(struct skipList *lst, int lv) {
	printf("Level %d: ", lv);
	/* FIX ME */

}


/*
	removeLink: Remove the first instance of the link containing the value from the list and maintains the skip list
	pre: lst is not null
    pre: val is in the list
	param1: lst - the list
	param2: val - value to remove
	post: pointers are adjusted at each relevant level
    post: sLink is freed
	post: sLink->next is freed
	HINT: start at the top or bottom and search for the value on that level
	HINT: each level of pointers needs to be adjusted as applicable
	HINT: ONLY FREE the node at the bottom level
	HINT: print statements displaying slides and dropping down a level might help to see what is happening
*/
void removeLink(struct skipList *lst, TYPE val) {
	/* FIX ME */


}


/*
	getSize: return the number of level 1 links in the skip list
	param1: lst - the list
	pre: lst is not null
	post: return the number of level 0 links in the list
	HINT: count the number of links at level 0
*/
int getSize(struct skipList *lst) {
	/* FIX ME */

	return 0;
}


/*
	deleteList: memory is freed for the skip list
    param1: lst - the list
	pre: lst is not null
	post: sLinks are freed
	post: sLinks->next are freed
	post: lst is freed
	HINT: free at level 0 of the list - no need to adjust other pointers
	HINT: Two malloc means two free for each node
*/
void deleteList(struct skipList *lst) {
	struct sLink *curr = lst->sentinel->next[0];
	struct sLink *prev = curr;

	while(curr != lst->sentinel) {
        prev = curr;
        curr = curr->next[0];
        free(prev->next);
        free(prev);
	}
	free(lst->sentinel->next);
	free(lst->sentinel);
	free(lst);
}
