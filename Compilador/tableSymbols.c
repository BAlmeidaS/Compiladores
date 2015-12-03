#include "tableSymbols.h"
#include <string.h>


int searchTable(char * data, char * table[]) {
	int i;
	for(i = 0; i < lenght(table); i++)
		if(strcmp(table[i], data) == 0) return i;
	return INDEX_NOT_FOUND;
}

		///////////
		//Publico//
		///////////

char * reservedWords[LEN_OF_RESERVED_TABLE] = { "program", "int", "char", "boolean", "if", "else", "while", "input", "print", "void"};
char * specialCharacters[LEN_OF_SPECIAL_CHAR_TABLE] = { "{", "}", "=", ">", "<", "==", "[", "]", "\"", "(", ")", ";", ",", ".", "+", "-", "*", "/"};
List * identifiers_table = NULL;
List * constants_table = NULL;

int SearchReserverdWords(char * data) {
	int i;
	for(i = 0; i < lenght(reservedWords); i++)
		if(strcmp(reservedWords[i], data) == 0) return i;
	return INDEX_NOT_FOUND;
}


int SearchIdentifier(char * data) {
	if (identifiers_table == NULL) identifiers_table =  empty_list();
	return search_list(data, identifiers_table);
}

int AddIdentifier(char * data) {
	if (identifiers_table == NULL) identifiers_table =  empty_list();
	return add_list(data, identifiers_table);
}

int CheckIdentifier(char * data) {
	int index = SearchIdentifier(data);
	//caso nao exista o identificador, cria um novo
	if(index == INDEX_NOT_FOUND) index = AddIdentifier(data);
	return index;
}

int SearchSpecialCharacters(char * data) {
	int i;
	for(i = 0; i < lenght(specialCharacters); i++)
		if(strcmp(specialCharacters[i], data) == 0) return i;
	return INDEX_NOT_FOUND;
}









