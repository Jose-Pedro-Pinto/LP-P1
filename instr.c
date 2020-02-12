#include "instr.h"

//creates an instruction with all elems empty
Instr* emptyfunc() {
	Instr *instr = (Instr *)malloc(sizeof(Instr));
	instr->op = -1;
	instr->first.kind = EMPTY;
	instr->second.kind = EMPTY;
	instr->third.kind = EMPTY;
	return instr;
}

//creates an instruction with the first elem a string and the others empty
Instr* singleStrfunc(char* string){
	Instr *instr = emptyfunc();
	instr->first.kind = STRING;
	instr->first.contents.name = strdup(string);
	return instr;
}

//creates a "ler" instruction
Instr* lerfunc(char* string) {
	Instr *instr = singleStrfunc(string);
	instr->op = READ;
	return instr;
}

//creates an "escrever" instruction
Instr* escfunc(char* string) {
	Instr *instr = emptyfunc();
	instr->op = PRINT;
	instr->first.kind = STRING;
	instr->first.contents.name = strdup(string);
	return instr;
}

//creates an "atribution" instruction (ex: a = 13;)
Instr* atribfunc(char* string, char* n) {
	Instr *instr = singleStrfunc(string);
	instr->op = ATRIB;
	if (!isInt(n)){
		instr->second.kind = STRING;
		instr->second.contents.name = strdup(n);
	}		
	else{
		int val = atoi(n);
		instr->second.kind = INT_CONST;
		instr->second.contents.val = val;
	}
	return instr;
}

//creates an "expression" instruction (ex: a = 13 * p;)
Instr* expfunc(int op, char* var, char* v1, char* v2) {
	Instr *instr = singleStrfunc(var);
	instr->op = op;
	if (isInt(v1)){
		instr->second.kind = INT_CONST;
		instr->second.contents.val = atoi(v1);
	}
	else{
		instr->second.kind = STRING;
		instr->second.contents.name = strdup(v1);
	}
	if (isInt(v2)){
		instr->third.kind = INT_CONST;
		instr->third.contents.val = atoi(v2);
	}
	else{
		instr->third.kind = STRING;
		instr->third.contents.name = strdup(v2);
	}
	return instr;
}

//creates an "label" instruction
Instr* labelfunc(char* label) {
	Instr *instr = singleStrfunc(label);
	instr->op = LABEL;
	return instr;
}

//creates an "goto" instruction
Instr* goTofunc(char* label) {
	Instr *instr = singleStrfunc(label);
	instr->op = GOTO_I;
	return instr;
}

//creates an "if" instruction (ex: if a goto c)
Instr* iffunc(char* var, char* label) {
	Instr *instr = singleStrfunc(var);
	instr->op = IF_I;
	instr->second.kind = STRING;
	instr->second.contents.name = strdup(label);
	return instr;
}

//prints an instruction
void printInstr(Instr* instr){
    printOp(instr->op);
    printf("first:\n");
    printElem(instr->first);
    printf("second:\n");
    printElem(instr->second);
    printf("third:\n");
    printElem(instr->third);
}

//prints the type of instruction
void printOp(int op){
    switch (op)
    {
        case ATRIB:
            printf("op: atrib\n");
            break;
        case ADD:
            printf("op: add\n");
            break;
        case SUB:
            printf("op: sub\n");
            break;
        case MUL:
            printf("op: mul\n");
            break;
        case DIV:
            printf("op: div\n");
            break;
        case IF_I:
            printf("op: if\n");
            break;
        case PRINT:
            printf("op: print\n");
            break;
        case READ:
            printf("op: read\n");
            break;
        case GOTO_I:
            printf("op: goto\n");
            break;
        case LABEL:
            printf("op: label\n");
            break;
        default:
            printf("op: invalid\n");
            break;
    }
}

//prints a single element of an instruction
void printElem(Elem elem){
    if (elem.kind == EMPTY){
        printf(" empty\n");
    }
    if (elem.kind == STRING){
        printf(" string:");
        printf(" %s\n",elem.contents.name);
    }
    if (elem.kind == INT_CONST){
        printf(" integer:");
        printf(" %d\n",elem.contents.val);
    }
}