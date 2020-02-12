#include "execinstr.h"

//read the value and inserts a value and its key in the hashtable
void read__func(Instr* l) {
	int n;
	scanf("%d", &n);
	insert(l->first.contents.name, n);
}

//look for a key in the hashtable and if exists prints otherwise prints the instruction in the list
void print__func(Instr* l) {
	int n;
	n = lookup(l->first.contents.name);
	if (n != NOTFOUND){
		printf("%d\n", n);
	}
	else{
		printf("%s\n", l->first.contents.name);
	}
}

//assigns and inserts a value and its key in the hashtable
void atrib__func(Instr* l) {
    int var = varValue(l->second);
	insert(l->first.contents.name, var);
}

//if the value of the variable is an integer it returns the element content
//if the value of the variable is an string search in the hashtable for the key of the variable 
int varValue(Elem element){
	if (element.kind == INT_CONST){
		return element.contents.val;
	}
	else if(element.kind == STRING){
		int val = lookup(element.contents.name);
		if (val != NOTFOUND){
			return val;
		}
	}
	return 0;
}

//does the operations with each variable
void exp__func(Instr* l) {
	int var1 = varValue(l->second);
	int var2 = varValue(l->third);
	int val;
	switch (l->op)
	{
		case ADD:
			val = var1+var2;
			break;
		case SUB:
			val = var1-var2;
			break;
		case MUL:
			val = var1*var2;
			break;
		case DIV:
			val = var1/var2;
			break;
		default:
			break;
	}
	insert(l->first.contents.name, val);	
}

//looks for a label in the list if it is not null otherwise returns -1
int findLabel(char* label, List list){
	int i=0;
	Instr* l;
	while (list != NULL) {
		l = list->head;
		if (l->op == LABEL) {
			if (strcmp(l->first.contents.name, label) == 0) {
				return i;
			}
		}
		list = list->tail;
		i++;
	}
	return -1;
}

//goes to a label in the list and if it doesn't exist returns NULL
List goToLabel(char* label, List resetlist){
	int n = findLabel(label, resetlist);
	if (n == -1) {
		return NULL;
	}
	else{
		List list = resetlist;
		while (n > 0) {
			list = list->tail;
			n--;
		}
		return list;
	}
}

//goes to a label in the list
List goto__func(Instr* l, List resetlist) {
	return goToLabel(l->first.contents.name, resetlist);
}

//if the value of the variable is != 0 goes to the label, otherwise returns null
List if_goto__func(Instr* l, List resetlist) {
	int x = lookup(l->first.contents.name);
	if (x != 0) {
		return goToLabel(l->second.contents.name, resetlist);
	}
	else{
		return NULL;
	}
}
