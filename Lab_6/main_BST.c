#include "BST.h"
#include <stdlib.h>
#include <stdio.h>
/*#include <malloc.h>*/

/*
	printTestResult: function to print the result of a test function
	param1: predicate - the result of the test
	param2: nameTestFunction - name of the function being tested
	param3: message - message passed to the test function
	post: result is printed to standard output
*/
void printTestResult(int predicate, char *message) {
	if (predicate) {
	   printf("%s: PASS\n", message);
    } else {
	   printf("%s: FAIL\n", message);
	}
}


/* Main function for testing different functions of the assignment */
int main() {
    struct BST *tree = malloc(sizeof(struct BST));
    initBST(tree);

    printf("------------------Testing addBST------------------\n");

    addBST(tree, 55);
    printTestResult((tree->root->val == 55), "addBST(55)");

    addBST(tree, 36);
    printTestResult((tree->root->left->val == 36), "addBST(36)");

    addBST(tree, 78);
    printTestResult((tree->root->right->val == 78), "addBST(78)");

	addBST(tree, 20);
	printTestResult((tree->root->left->left->val == 20), "addBST(20)");

	addBST(tree, 85);
	printTestResult((tree->root->right->right->val == 85), "addBST(85)");

	addBST(tree, 67);
    printTestResult((tree->root->right->left->val == 67), "addBST(67)");

    printTestResult((tree->nodeCount == 6), "size == 6");

    printf("------------------testing containsBST-------------------\n");

    printTestResult(containsBST(tree, 55), "containsBST(55)");
    printTestResult(containsBST(tree, 36), "containsBST(36)");
    printTestResult(containsBST(tree, 20), "containsBST(20)");
    printTestResult(containsBST(tree, 85), "containsBST(85)");
    printTestResult(!containsBST(tree, 88), "containsBST(88)");
    printTestResult(!containsBST(tree, 1), "containsBST(1)");

    printf("\n------------printing in-order traversal------------ \n");
    inorderTraversal(tree->root);
    printf("\n");

    printf("------------------testing removeNode-------------------\n");

    removeBST(tree, 20);
    printTestResult((tree->root->val == 55) && (!containsBST(tree, 20)), "removeBST(20)");

    printf("\n------------printing in-order traversal------------ \n");
    inorderTraversal(tree->root);
    printf("\n");

    removeBST(tree, 67);
    printTestResult((tree->root->val == 55)  && (!containsBST(tree, 67)), "removeBST(67)");

    printf("\n------------printing in-order traversal------------ \n");
    inorderTraversal(tree->root);
    printf("\n");

    removeBST(tree, 55);
    printTestResult((tree->root->val == 78) && (!containsBST(tree, 55)), "removeBST(55)");

    printf("\n------------printing in-order traversal------------ \n");
    inorderTraversal(tree->root);
    printf("\n");

    freeBST(tree);
    tree = 0;

	return 0;
}



