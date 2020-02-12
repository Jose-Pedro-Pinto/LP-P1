#include "config.h"

//struct for the list
typedef struct list {
	void* head;
	struct list *tail;
} *List;

//reverse of a list
List reverse(List l);
//creates a new list
List newList(void* n, List l1);
//turns an array into a list
List listFromArray(void* array[],List l1);
//clones a list
List copyList(List l);
//returns the first element of the list
void* head(List l);
//returns the list without its first element
List tail(List l);
//length of the list
int length (List l);
//last element of the list
List lastElement(List l);
//nth element of the list
void* nthElement(List l,int n);
//appends two lists
List append(List l1, List l2);
//applies a function to all elements of the list
List map(void* (*f)(void*),List l);
//aux function to map
List mapAux(void* (*f)(void*),List l);
//returns a list of elements that pass a test
List filterList(void* (*f)(void*),List l);
//aux function to filter
List filterListAux(void* (*f)(void*),List l);
//prints a list of any type of element
void generalPrint(List l,void (*print)(void* element));
//checks if an element is in a list
int member(void* (*equals)(void*),List l,void * element);