#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash.h"

/*
	assertTrue: testing function
	param1: predicate - result of the test function
	param2: message - the output message
	pre: none
	post: none
 */
void assertTrue(int predicate, char *message) {
	printf("%s: ", message);
	if (predicate)
		printf("Pass \n");
	else
		printf("Fail \n");
}

/*
	getWord: function takes a FILE pointer and returns a string which is the next word in the file
	words are defined to be characters, apostrophes or numbers separated by periods, spaces or newlines
	param1: file - the file to parse
	pre: none
	post: no changes to the file
	return: current word of file is returned. NULL is returned at the end of the file
 */
char* getWord(FILE *file) {
	int length = 0;
	int maxLength = 16;
	char character;

	char *word = malloc(sizeof (char) *maxLength);
	assert(word != NULL);

	while((character = fgetc(file)) != EOF) {
		if((length+1) > maxLength) {
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || character == 39) {
			word[length] = character;
			length++;
		} else if(length > 0) {
			break;
		}
	}

	if(length == 0)	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}


int main () {
#include <stdio.h>
#include <stdlib.h>
#include "hash.h" // Ensure this matches your header file name

	int main(int argc, const char * argv[]) {
		/* 1. Command Line Argument Validation */
		if(argc < 2) {
			printf("Usage: %s <filename>\n", argv[0]);
			return 1;
		}

		const char* fn = argv[1]; /* Get filename from command line arg */
		struct hashTable *hash1;
		FILE *filePtr;

		printf("Opening file: %s \n", fn);
		filePtr = fopen(fn, "r");

		/* Check for file open error */
		if (filePtr == NULL) {
			printf("Error: Could not open file %s\n", fn);
			return 1;
		}

		/* Create the map */
		hash1 = createMap(40, 1); // createMap calls _initMap

		char *word;

		/* 2. Read File and Build Concordance */
		while((word = getWord(filePtr))) {
			// Skip empty strings if getWord returns them
			if(*word == '\0') {
				free(word); // Don't leak memory for empty words
				continue;
			}

			// *** USE CONCORDANCE HERE, NOT insertMap ***
			// This ensures frequencies are counted (1, 2, 3...)
			// instead of resetting to 1 every time.
			concordance(hash1, word);

			// Free the word returned by getWord because concordance/insertMap
			// made its own copy (Deep Copy)
			free(word);
		}

		fclose(filePtr);

		/* 3. Print Results (Doubly Nested Loop Requirement) */
		printf("\n--- Word Frequencies ---\n");

		// Outer Loop: Iterate through the array (buckets)
		for (int i = 0; i < hash1->tableSize; i++) {
			struct hashLink *curr = hash1->table[i];

			// Inner Loop: Iterate through the linked list in this bucket
			while (curr != NULL) {
				printf("%s: %d\n", curr->key, curr->value);
				curr = curr->next;
			}
		}

		/* 4. Cleanup */
		_freeMap(hash1);
		free(hash1);

		return 0;
	}

    printf("--------------- Testing hashFunction1 --------------- \n");

    assertTrue((hashFunction1("abc") == 294), "Hash 'abc' == 294");

    printf("--------------- Testing contains --------------- \n");

    assertTrue(containsKey(hash1, "it") == 1, "Search for 'it'");
    assertTrue(containsKey(hash1, "comparison") == 1, "Search for 'comparison'");
    assertTrue(containsKey(hash1, "period") == 1, "Search for 'period'");
    assertTrue(containsKey(hash1, "despair") == 1, "Search for 'despair'");
    assertTrue(containsKey(hash1, "deriop") == 0, "Search for 'deriop'");
    assertTrue(containsKey(hash1, "yuck") == 0, "Search for 'yuck'");

    printf("\n--------------- Testing table stats --------------- \n");

    assertTrue(hash1->tableSize == 40, "Test table size (40)");
    assertTrue(getFullBuckets(hash1) == 30, "Test full buckets (30)");
    assertTrue(getEmptyBuckets(hash1) == 10, "Test empty buckets (10)");
    assertTrue(getLinkCount(hash1) == 59, "Test link count (59)");

    printf("--------------- Testing remove --------------- \n");

    assertTrue(containsKey(hash1, "despair") == 1, "Search for 'despair'");
    removeKey(hash1, "despair");
    assertTrue(containsKey(hash1, "despair") == 0, "Search for 'despair' after remove");
    assertTrue(containsKey(hash1, "yuck") == 0, "Search for 'yuck'");
    removeKey(hash1, "yuck"); /* Should print some type of 'not found' message */

    printf("--------------- Printing hash table --------------- \n");
	printMap(hash1);

    printf("Delete Hash Table 1\n");
    deleteMap(hash1);

    printf("Closing file\n");
    fclose(filePtr);

    printf("--------------- Testing Round 2 - Same text file - new hash --------------- \n");

    fn = "text1.txt";
	printf("Opening file: %s \n", fn);
	filePtr = fopen(fn, "r");
	hash2 = createMap(40, 2);

    while((word = getWord(filePtr))) {
        if(*word == '\0') {
            break;
        }
        insertMap(hash2, word, 1);
    }

    printf("--------------- Testing table stats 2 --------------- \n");

    assertTrue(hash2->tableSize == 80, "Test table size (80)");
    assertTrue(getFullBuckets(hash2) == 38, "Test full buckets (38)");
    assertTrue(getEmptyBuckets(hash2) == 42, "Test empty buckets (42)");
    assertTrue(getLinkCount(hash2) == 59, "Test link count (59)");


    printf("--------------- Testing remove --------------- \n");

    assertTrue(containsKey(hash2, "yuck") == 0, "Search for 'yuck'");
    removeKey(hash2, "yuck");
    assertTrue(containsKey(hash2, "despair") == 1, "Search for 'despair'");
    removeKey(hash2, "despair");
    assertTrue(containsKey(hash2, "despair") == 0, "Search for 'despair' after remove");
    assertTrue(containsKey(hash2, "belief") == 1, "Search for 'belief'");
    removeKey(hash2, "belief");
    assertTrue(containsKey(hash2, "belief") == 0, "Search for 'belief' after remove");
    assertTrue(containsKey(hash2, "degree") == 1, "Search for 'degree'");
    removeKey(hash2, "degree");
    assertTrue(containsKey(hash2, "degree") == 0, "Search for 'degree' after remove");

    printf("Delete Hash Table 2\n");
    deleteMap(hash2);

    printf("Closing file\n");
    fclose(filePtr);

    /*UNCOMMENT AFTER YOU GET THE MAP WORKING*/


    printf("--------------- Testing table stats 2 --------------- \n");

	struct hashTable *concord;

    fn = "text2.txt";
	printf("Opening file: %s \n", fn);
	filePtr = fopen(fn, "r");
	concord = createMap(10, 2);


	//instead of calling insert, we call concordance
    while((word = getWord(filePtr)) != '\0') {
        concordance(concord, word);
    }

    printf("--------------- Concordance table stats --------------- \n");

    printf("table size: %d \n", concord->tableSize);
    printf("full buckets: %d \n", getFullBuckets(concord));
    printf("empty buckets: %d \n", getEmptyBuckets(concord));
    printf("link count: %d \n", getLinkCount(concord));





	return 0;
}
