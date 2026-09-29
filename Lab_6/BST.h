#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
/*#include <malloc.h>*/

/* Defines the type to be stored in the data structure */
# define TYPE int

struct Node {
	TYPE val;
	struct Node *left;
	struct Node *right;
};

/* BST definition */
struct BST {
	struct Node *root;
	int nodeCount;
};


void initBST(struct BST *tree);
TYPE getLeftMostValue(struct Node *curr);
void addBST(struct BST *tree, TYPE val);
int containsBST(struct BST *tree, TYPE val);
void freeBST(struct BST *tree);
void _freeNodes(struct Node *curr);
void removeBST(struct BST *tree, TYPE val);

void inorderTraversal(struct Node *curr);
