#include "list.h"

//creates a new list
List newList(void* n, List l1) {
	List l = malloc(sizeof(struct list));
	l->head = n;
	l->tail = l1;
	return l;
}

//clones a list
List copyList(List l){
    if (l == NULL)
        return NULL;
    List l1 = newList(head(l),copyList(tail(l)));
    return l1;
}

//prints a list of any type of element
void generalPrint(List l,void (*print)(void* element)){
	if (l == NULL)
        return;
    generalPrint(tail(l),print);
    printf("%d :--------------:\n",length(l));
    print(head(l));
}

//returns the first element of the list
void* head(List l) {
	if (l == NULL) {
		return NULL;
	}
	return (l->head);
}

//returns the list without its first element
List tail(List l) {
	return (l->tail);
}

///length of the list
int length (List l) {
	if (l == NULL)
        return 0;
    return length(tail(l))+1;
}

//last element of the list
List lastElement(List l){
    if (tail(l)!=NULL){
        return lastElement(tail(l));
    }
    return l;
}

//nth element of the list
void* nthElement(List l,int n){
    if (l==NULL){
        return 0;
    }
    if (n==1){
        return head(l);
    }
    return nthElement(tail(l),n-1);
}

//appends two lists
List append(List l1, List l2) {
	List copy2 = copyList(l2);
    List temp = lastElement(copy2);
    List copy = copyList(l1);
    temp->tail = copy;
    return copy2;
}

//reverse of a list
List reverse(List l){
    if (tail(l) == NULL)
        return l;
    List l1 = append(newList(head(l),NULL),reverse(tail(l)));
    return l1;
}

//aux function to map
List mapAux(void* (*f)(void*),List l){
    if (l==NULL){
        return NULL;
    }
    l->head = f(head(l));
    mapAux(f, tail(l));
    return l;
}

//applies a function to all elements of the list
List map(void* (*f)(void*),List l){
    List copy = copyList(l);
    return mapAux(f, copy);
}

//aux function to filter
List filterListAux(void* (*f)(void*),List l){
    if (l == NULL){
        return l;
    }
    if (f(head(l))==0){
        return filterListAux(f, tail(l));
    }
    l->tail = filterListAux(f, tail(l));
    return l;
}

//returns a list of elements that pass a test 
List filterList(void* (*f)(void*),List l){
    List copy = copyList(l);
    return filterListAux(f, copy);
}

//checks if an element is in a list
int member(void* (*equals)(void*),List l,void* element){
    if (l == NULL)
        return 0;
    else if (equals(head(l),element))
        return 1;
    else if(member(equals,tail(l),element))
        return 1;
    else return 0;
}

/*int isPair(int number);

filterlist(isPair,list);*/