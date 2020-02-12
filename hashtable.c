#include "hashtable.h"

//print the hashtable
void printtable() {
	int i;
	for (i=0 ; i<HASH_SIZE ; i++) {
		printf("index: %d\n", i);
		hashList* l = table[i];
		while (l != NULL) {
			printf(" Key: %s Value: %d\n",l->key, l->value);
			l = l->next;
		}
	}
}

//look for a key in the hashtable, if it exists returns the corresponding value, otherwise returns -404
int lookup(char *key) {

	int index;
	index = hash(key);
	hashList* l = table[index];

	while (l != NULL) {

		if (strcmp(l->key, key) == 0)
			return l->value;
		l = l->next;
	}	

	return NOTFOUND;

}

//inserts a value and its key in the hashtable
void insert(char *k, int v) {
	int index;
	hashList* new;
	index = hash(k);
	new = (hashList*)malloc(sizeof(hashList));
	new->key = k;
	new->value = v;
	new->next = table[index];
	table[index] = new;
}

//gets a string and returns an integer, a hash of that string
unsigned int hash(char* str) {
	unsigned int h;
	unsigned char *p;
	h = 0;
	for (p = (unsigned char* )str; *p!= '\0' ; p++)
		h = MULTIPLIER*h + *p;
	return h % HASH_SIZE;
}