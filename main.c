#include "config.h"
#include "execinstr.h"
#include <stdio.h>


//reads from stdin character by character returns a string
char *ler_nome() { 

	int i=0;
	char aux[MAXNOME], c, *nome; 
	do c = getchar(); while (!isalpha(c));
	do {
		aux[i++] = c;
		c = getchar();
	} while (c != '\n');
	aux[i] = '\0';
	nome  = malloc(i+1);
	strcpy(nome,aux);
	return nome;

}

//read line by line from the file and converts to a list
List readCode(FILE *file){

	int i=0;
	List list = NULL;

	char linha[MAXNOME];
	char *l;

	printf("A ler o ficheiro.\n");
	printf("\n");

	while(!feof(file)) {
		fgets(linha, sizeof(linha), file);
		if(!strStartsWith(linha, "quit;")) {
			printf("%s",linha);
			Instr* line = parseToStruct(linha);
			if (line == NULL){ 
				printf("invalid instruction\n");
				return NULL;
			}
			list = newList(line,list);
		}
		else{
			break;
		}	    
	}
	fclose(file);
	generalPrint(list, printInstr);
	return reverse(list);
}	

//receives the list with the statement and associates each statement
void runCode(List instrList){
	List resetlist = instrList;
	List copyList = instrList;
	//scroll instruction list
	Instr* l;
	while (instrList != NULL) {
		l = instrList->head;
		switch (l->op)
		{
			case READ:
				read__func(l);
				break;
			case PRINT:
				print__func(l);
				break;
			case ATRIB:
				atrib__func(l);
				break;
			case GOTO_I:
				instrList = goto__func(l,resetlist);
				break;
			case IF_I:
				instrList = if_goto__func(l,resetlist);
				break;
			default:
				exp__func(l);
			break;
		}
		if (instrList != NULL) {
			instrList = instrList->tail;
		}
		else{
			instrList = copyList->tail;
		}
		copyList = instrList;
	}
}

//prompts the user to enter the file name in read form ler(nome_ficheiro)
//if the file exists call the functions readCode(file) and runCode(list)
int main() {

	FILE *file; 
	char* instr;
	char nome_fich[MAXNOME];
	List list;

	printf("Por favor introduza o nome dos ficheiros que pretende ler na forma de ler(nome_ficheiro.txt)\n");
	printf("Quando terminar introduza 'quit;' para finalizar a leitura.\n");
	instr = ler_nome();

	while (strcmp(instr, "quit;") != 0) {

		if(strStartsWith(instr, "ler")) {
			sscanf(instr,"ler(%[^)])", nome_fich);
			file = fopen(nome_fich, "r");
			if(file == NULL) {
				printf("Erro, nao foi possivel abrir o ficheiro.\n");
				//fclose(file);
			}

			else {
				list=readCode(file);
			  	runCode(list);
			}	
		}

		else {
			printf("Instrução inválida. Por favor introduza uma instrução na forma ler(nome_fich).\n");
		}
		printf("Introduza o nome de outro ficheiro ou quit; para terminar.\n");
		instr = ler_nome();	
	}

	return 0;
}
