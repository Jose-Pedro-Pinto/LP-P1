#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Global variables
//number of buckets in the hashtable
#define HASH_SIZE 10
//the multiplier when calculating the hash
#define MULTIPLIER 31
//the maximum size of an instruction
#define MAXINSTR 100
//the maximum size of a variable
#define MAXNOME 30
//the value of error for ints
#define NOTFOUND -404