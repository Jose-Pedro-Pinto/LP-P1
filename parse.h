#include "config.h"
#include "instr.h"

//casts an instruction with a single nom empty element
Instr* castInstr(char* nome,char* pattern,Instr* (*cast)(char* str));
//casts the if instruction
Instr* castIf(char* nome);
//casts the expression instruction
Instr* castExpr(char* variable,char* attr);
//casts the attribution expression
Instr* castAttr(char* nome);
//parses a line of input into its components
Instr* parseToStruct(char* nome);
//turns an aritmetic opperator(char) into a constant
int pickOp(char* op);