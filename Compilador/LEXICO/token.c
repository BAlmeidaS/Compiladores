#include "token.h"

Token *token;

void createToken() {
	token = (Token *) malloc(sizeof(Token));
}

void freeToken() {
	free(token);
}

void printToken() {
	char *tipo;
	switch (token->type) {
		case T_RESERV_IDENTIF:
			tipo = "T_RESERV_IDENTIF";
			break;
		case T_RESERVED_WORD:
			tipo = "T_RESERVED_WORD";
			break;
		case T_IDENTIF:
			tipo = "T_IDENTIF";
			break;
		case T_NUM:
			tipo = "T_NUM";
			break;
		case T_COMMENT:
			tipo = "T_COMMENT";
			break;
		case T_SPECIAL_CHARACTER:
			tipo = "T_SPECIAL_CHARACTER";
			break;
		case T_INVALID:
			tipo = "T_INVALID";
			break;
		case T_END_OF_FILE:
			tipo = "T_END_OF_FILE";
			break;
		case T_STRING:
			tipo = "T_STRING";		
			break;
		default:
			tipo = "Null";
	}

	printf("Token: %s, %s (%d) \n", token->lexeme, tipo, token->value);
} 
