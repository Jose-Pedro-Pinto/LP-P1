#include "config.h"
#include "parse.h"
#include "list.h"
#include "hashtable.h"

//read the value and inserts a value and its key in the hashtable
void read__func(Instr* l);
//look for a key in the hashtable and if exists prints otherwise prints the instruction in the list
void print__func(Instr* l);
//assigns and inserts a value and its key in the hashtable
int varValue(Elem element);
//if the value of the variable is an integer it returns the element content
//if the value of the variable is an string search in the hashtable for the key of the variable 
void atrib__func(Instr* l);
//does the operations with each variable
void exp__func(Instr* l);
//looks for a label in the list if it is not null otherwise returns -1
int findLabel(char* label, List list);
//goes to a label in the list and if doesn't exists return NULL
List goToLabel(char* label, List resetlist);
//goes to a label in the list
List goto__func(Instr* l, List resetlist);
//if the value of the variable is != 0 goes to the label, otherwise returns null
List if_goto__func(Instr* l, List resetlist);