#include "config.h"
#include "utils.h"

typedef enum {ATRIB, ADD, SUB, MUL, DIV, IF_I, PRINT,
READ, GOTO_I, LABEL} OpKind;

typedef enum {EMPTY, INT_CONST, STRING} ElemKind;

//Um elemento da instrução
typedef struct {
	ElemKind kind;
	union 
		{
			int val;
			char *name;
		} contents;
} Elem;

//Instrução
typedef struct {
	OpKind op;
	Elem first, second, third;
} Instr;

//creates an instruction with all elems empty
Instr* emptyfunc();
//creates an instruction with the first elem a string and the others empty
Instr* singleStrfunc(char* string);
//creates a "ler" instruction
Instr* lerfunc(char* string);
//creates an "escrever" instruction
Instr* escfunc(char* string);
//creates an "atribution" instruction (ex: a = 13;)
Instr* atribfunc(char* string, char* n);
//creates an "expression" instruction (ex: a = 13 * p;)
Instr* expfunc(int op, char* var, char* v1, char* v2);
//creates an "label" instruction
Instr* labelfunc(char* label);
//creates an "goto" instruction
Instr* goTofunc(char* label);
//creates an "if" instruction (ex: if a goto c)
Instr* iffunc(char* var, char* label);
//prints an instruction
void printInstr(Instr* instr);
//prints the type of instruction
void printOp(int op);
//prints a single element of an instruction
void printElem(Elem elem);