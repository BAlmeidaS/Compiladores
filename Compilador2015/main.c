/* 			
/	2056 - Compiladores
/
/	Andre Amorim Pereira - 7209843
/	Bruno Almeida Silveira - 6852401
/
/	16/11/15
*/

#include <stdlib.h>
#include <stdio.h>
#include "LEXICO/token.h"
#include "LEXICO/lexico.h"
#include "tableSymbols.h"


int main(int argc, char **argv) {

	char *filename = "codigo.txt";
	createFile(filename);
	createOutFile(filename);

	createToken();
	createTransitionTable();

	nextToken();
	while (token->type != T_END_OF_FILE) {
		printToken();
		nextToken(); /* lexical analyser */

	}
	printToken();

	closeFile();

	return 0;
}

