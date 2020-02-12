#include "parse.h"

//casts an instruction with a single nom empty element
Instr* castInstr(char* nome,char* pattern,Instr* (*cast)(char* str)){
	char string[MAXNOME];
	if(sscanf(nome,pattern,string)!=1)
		return NULL;
	return cast(string);
}

//casts the if instruction
Instr* castIf(char* nome){
		char variable[MAXNOME];
		char string[MAXNOME];
		if(sscanf(nome,"if %s goto %[^;];",variable,string)!=2)
			return NULL;
		return iffunc(variable,string);
}

//there are 2 castExpr, if the program does not work, try to swap them
/*
Instr* castExpr(char* variable,char* attr){
		char op[1];
		char v1[MAXNOME];
		char v2[MAXNOME];
		if (sscanf(attr,"%[^ ] %[^ ] %s",v1,op,v2)!=3){
			return atribfunc(variable,attr);
		}
		int operator = pickOp(op);
		if (operator!=-1)
			return expfunc(operator,variable,v1,v2);
		return NULL;
}*/

//casts the expression instruction
Instr* castExpr(char* variable,char* attr){
		char op[1];
		char  *v1;
		char v2[MAXNOME];
		if (sscanf(attr,"%[^ ] %[^ ] %s",v1,op,v2)!=3){
			return atribfunc(variable,attr);
		}
		v1 = strtok(attr, " ");
		printf("%s\n%s\n%s\n", v1,v2,op);
		int operator = pickOp(op);
		if (operator!=-1)
			return expfunc(operator,variable,v1,v2);
		return NULL;
}

//turns an aritmetic opperator(char) into the corresponding constant
int pickOp(char* op){
		int operator;
		switch (*op)
		{
			case '+':
				operator=ADD;
				break;
			case '-':
				operator=SUB;
				break;
			case '*':
				operator=MUL;
				break;
			case '/':
				operator=DIV;
				break;
			default:
				operator =-1;
		}
	return operator;
}

//casts the attribution expression
Instr* castAttr(char* nome){
	char variable[MAXNOME];
	char attr[MAXINSTR];
	if (sscanf(nome,"%s = %[^;];",variable,attr)!=2)
		return NULL;
	return castExpr(variable,attr);
}

//parses a line of input into its components
Instr* parseToStruct(char* nome) {

	if (strStartsWith(nome, "ler")) {
		return castInstr(nome,"ler(%[^)]);",lerfunc);
	}
	
	if (strStartsWith(nome, "escrever")) {
		return castInstr(nome,"escrever(%[^)]);",escfunc);
	}
	
	if (strStartsWith(nome, "label")) {
		return castInstr(nome,"label %[^;];",labelfunc);
	}

	if (strStartsWith(nome, "goto")) {
		return castInstr(nome,"goto %[^;];",goTofunc);
	}

	if (strStartsWith(nome, "if")) {
		return castIf(nome);
	}
	
	else {
		return castAttr(nome);
	}
}