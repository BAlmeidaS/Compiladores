#ifndef token_h_
#define token_h_

#include <stdlib.h>
#include <stdio.h>

#define T_RESERVED_WORD 1
#define T_IDENTIF 2
#define T_NUM 4
#define T_COMMENT 5
#define T_SPECIAL_CHARACTER 6
#define T_INVALID 7
#define T_END_OF_FILE 8
#define T_STRING 9

#define T_RESERV_IDENTIF (T_RESERVED_WORD | T_IDENTIF)

typedef struct {
	int type; 
	char *lexeme;
	int value; //Indice na tabela de simbolos
} Token;

extern Token *token; /* Variavel Global de qual token está sendo lido - Buffer de tamanho 1 com os tokens lidos*/

void createToken();
void freeToken();


#endif
