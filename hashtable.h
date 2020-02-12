#include "config.h"

//hash tables
typedef struct hashlist {
	char *key; //necessariamente string
	int value;
	struct hashlist *next;
} hashList;

hashList *table[HASH_SIZE];

//print the hashtable
void printtable();
//look for a key in the hashtable, if it exists returns the corresponding value, otherwise returns -404
int lookup(char *key);
//inserts a value and its key in the hashtable
void insert(char *key, int value);
//gets a string and returns an integer, a hash of that string
unsigned int hash(char *str);

