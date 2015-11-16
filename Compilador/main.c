/* 			
/		2056 - Compiladores
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



int main(int argc, char **argv) {

	char *filename = "codigo.txt";
	createFile(filename);

	createToken();
	createTransitionTable();

	nextToken();

	while (token->type != T_END_OF_FILE) {
		//if (token->type != TTYPE_COMMENT && token->type != TTYPE_STRING)
		//	if (!spa_step()) { /* sintatic analyser */
		//		fprintf(stderr, "source code could not be correctly parsed");
		//		break;
		//	}
		printToken();
		nextToken(); /* lexical analyser */

	}

	closeFile();

	//close_file_writer();
	//merge_code_data();

	return 0;
}

