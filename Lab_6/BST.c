#include "BST.h"

/*
Kate Bohning
Data Structures
Binary Search Tree implementation - Week 6
*/

/*
	initBST: initialize BST members
	param1: tree
	pre: tree is not null
	post: nodeCount is 0
	post: root is null
 */
void initBST(struct BST *tree) {
    assert(tree != NULL);
    tree->root = NULL;
	tree->nodeCount  = 0;
}



/*
	getLeftMostValue: iterative helper function to find the left most child of a node
	param: curr the current node
	pre: curr is not null
	post: return the value of the left most child of curr
*/
TYPE getLeftMostValue(struct Node *curr) {
	/*FIX ME*/
	assert(curr != NULL);
	while (curr->left != NULL)
	{
		curr = curr->left;
	}

    return curr->val;
}


/*
	addBST: iterative function to add a value to a binary search tree
	param1: tree - the binary search tree
	param2: val	- the value to be added to the tree
	pre: tree is not null
	post: nodeCount is incremented
	post: memory is dynamically allocated to a  new node
	post: new node has value specified by parameter
	post: left and right pointers of new node are NULL
	post: prev pointer points to new node
	post: tree contains one new node - pointers have been updated
	HINT: prev has three cases: left, right or root
 */
void addBST(struct BST *tree, TYPE val) {
    printf("Adding %d \n", val);
    /* FIX ME */
	assert(tree != NULL);
	struct Node *temp = malloc(sizeof(struct Node));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;

	struct Node *curr = tree->root;
	struct Node *prev = curr;

	while (curr != NULL)
	{
		prev = curr;
		if (val < curr->val)
		{
			curr = curr->left;
		}
		else
		{
			curr = curr->right;
		}
	}
	if (curr == tree->root)
	{
		tree->root = temp;
	}
	else if (val > prev->val)
	{
		prev->right = temp;
	}
	else
	{
		prev->left = temp;
	}
	tree->nodeCount++;
}


/*
	containsBST: iterative function to determine if the binary search tree contains an element
	param1: tree the BST
	param2: val	- the value to search for in the tree
	pre: tree is not null
	return : return 1 if the tree contains the value, otherwise return 0
	post: no changes to the BST
 */
int containsBST(struct BST *tree, TYPE val) {
	/* FIX ME */
	assert(tree != NULL);
	struct Node *curr = tree->root;
	while (curr != NULL)
	{
		if (val == curr->val)
		{
			return 1;
		}
		else if (val > curr->val)
		{
			curr = curr->right;
		}
		else if (val < curr->val)
		{
			curr = curr->left;
		}
	}

    return 0;
}



/*
	removeBST: iterative function to remove a value from the BST
	param1: tree - the BST
	param2: val	- the value to be removed from the tree
	pre: tree is not null
	pre: val is in the tree
	post: nodeCount is decremented
	post: node has been freed
	post: link is removed from the BST - pointers updated
	HINT: There are four different delete cases - leaf, one subtree (L or R) and two subtrees
	HINT: Call getLeftMostValue to find the inorder successor when needed
	HINT: Step 1 - find the node and the prev
	HINT: Step 2 - update pointers - updating pointers is pretty painful
	HINT: This is the most complicated function
*/
void removeBST(struct BST *tree, TYPE val) {
	printf("Remove %d \n", val);
	assert(tree != NULL);
	assert(containsBST(tree, val));
	/*FIX ME*/
	struct Node *curr = tree->root;
	struct Node *prev = NULL;

	while (curr->val != val)
	{
		prev = curr;
		if (val > curr->val)
		{
			curr = curr->right;
		}
		else
		{
			curr = curr->left;
		}
	}
	if (curr->left == NULL && curr->right == NULL)
	{
		printf("leaf\n");
		if (prev->right == curr)
		{
			prev->right = NULL;
		}
		else
		{
			prev->left = NULL;
		}
	}
	else if (curr->left == NULL)
	{
		printf("right subtree\n");
		if (prev->right == curr)
		{
			prev->right = curr->right;
		}
		else
		{
			prev->left = curr->right;
		}
	}
	else if (curr->right == NULL)
	{
		printf("left subtree\n");
		if (prev->right == curr)
		{
			prev->right = curr->left;
		}
		else
		{
			prev->left = curr->left;
		}
	}
	else
	{
		printf("two subtrees\n");
		curr->val = getLeftMostValue(curr->right);
		prev = curr;
		curr = curr->right;
		while (curr->left != NULL)
		{
			prev = curr;
			curr = curr->left;
		}
		if (prev->right == curr)
		{
			prev->right = curr->right;
		}
		else
		{
			prev->left = curr->right;
		}
	}
	free(curr);
	curr = 0;
	tree->nodeCount--;

}

/*
	freeBST: function to delete a BST
	param: tree a binary search tree
	pre: tree not null
	post: tree is freed
	post: all memory for the BST and nodes is freed
	function calls _freeNodes
 */
void freeBST(struct BST *tree) {
    assert(tree != NULL);

	_freeNodes(tree->root);
	free(tree);
	tree = 0;
}

/*
	_freeNodes: recursive function to free the nodes of a BST
	param: curr - the root node of the tree to be freed
	pre: none
	post: node and all descendants are deallocated
	HINT: free the nodes using a post-order traversal
*/
void _freeNodes(struct Node *curr) {
	if(curr == NULL) {
        return;
	}
    _freeNodes(curr->left);
    _freeNodes(curr->right);
    free(curr);
    curr = 0;
}


/*
    inorderTraversal: recursive function prints the inorder traversal of BST
    param: curr - the current node
    pre: none
    post: in-order traversal is printed
    post: no changes to the BST
    hint: inorder = left-node-right
*/
void inorderTraversal(struct Node *curr) {
    /* FIX ME */
	if (curr == NULL)
	{
		printf("Empty Tree\n");
		return;
	}
	inorderTraversal(curr->left);
	printf("%d ", curr->val);
	inorderTraversal(curr->right);
	printf("%d ", curr->val);
}


Write a function which will insert a value into a min-heap