#include "token.h"
#include "stdlib.h" 
#include "stdio.h" 

Token *token;

void createToken() {
	token = (Token *) malloc(sizeof(Token));
}

void freeToken() {
	free(token);
}
