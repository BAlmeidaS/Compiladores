#include "lexico.h"

off_t fsize(char *filename) {
    struct stat st; 

    if (stat(filename, &st) == 0)
        return st.st_size;

    return -1; 
}

char *substring(char *from, size_t begin, size_t len) {
	char *substring;
	if(from == 0 || strlen(from) == 0 || strlen(from) < begin || strlen(from) < (begin+len)) return 0;

	substring = (char *)malloc(len);
	strncpy(substring, from+begin, len);
	substring[len+1] = '\0';
	return substring;
}

void endToken() {
	switch(token->type) {
		case T_RESERV_IDENTIF:
			//entende Se é uma palavra reservada ou se é um identificador
			if (token->type == T_RESERV_IDENTIF){
				int index_of_reserved = search_reserved_words_table(token->lexeme);

				if (index_of_reserved != INDEX_NOT_FOUND) {
					token->type = T_RESERVED_WORD;
					token->value = index_of_reserved;
				} else {
					token->type = T_IDENTIF;
					token->value = add_if_new_identifiers_table(token->lexeme);
				}			
			}
			break;
			
		case T_NUM:
			token->value = atoi(token->lexeme);
			break;

		case T_SPECIAL_CHARACTER:
			token->value = search_special_characters_table(token->lexeme);
			break;

		case T_STRING:
			token->lexeme = substring(token->lexeme, 1, strlen(token->lexeme)-2);
			break;

		default:
			/* Other types do not have token->value */
			break;
		}
}

int typeState(int state) {
	switch (state) {
		case 2:
			return T_RESERV_IDENTIF;
		case 3:
			return T_NUM;
		case 4:
			return T_COMMENT;
		case 5:
			return T_SPECIAL_CHARACTER;
		case 6:
			return T_SPECIAL_CHARACTER;
		case 7:
			return T_INVALID;
		case 8:
			return T_END_OF_FILE;
		case 9:
			return T_STRING;

		default:
			return -1;
	}
}

character get_type_char(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return letter;
	else if (c >= '0' && c <= '9')
		return digit;
	else if (c == ' ') // talvez incluir "|| c == '\t'""
		return space;
	else if (c == '=')
		return equal;
	else if (c == ';')
		return linebreak;
	else if (	c == '>' || c == '<' || c == '!' || 
				c == '+' || c == '-' || c == '*' || c == '/' || 
			 	c == '{' || c == '}' || c == '[' || c == ']' || 
			 	c == '(' || c == ')' || c == ',' )
		return special;
	else if (c == '#')
		return sharp;
	else if (c == EOF) 
		return eof;
	else
		return invalid;
}


char get_lookahead() {
	int c = fgetc(file);
	ungetc(c, file);
	return (char)c;
}


// SPECIAL CHARACTERS: >, <, ! (different), +, -, /, *, {, }, [, ], ','
void getToken() {
	char current = (char)fgetc(file);
	int character = get_type_char(current);
	int nextstate = transition_table[1][character];

	char lookahead; 
	int type_lookahead;

	int tokenType;
	
	//Cria a lista que será o lexema do token
	List * lexeme;
	lexeme = empty_list();


	//PRIMEIRO - verificar se é o EOF
	if (nextstate == 9) { 
		tokenType = T_END_OF_FILE;
	}

	//Ignorar espacos
	while(nextstate == 1) { 
		current = (char)fgetc(file);
		character = get_type_char(current);
		nextstate = transition_table[nextstate][character];
	}
	alloc_add_list(current, lexeme);

	lookahead = get_lookahead(file);
	type_lookahead = get_type_char(lookahead);

	
	//O token eh completado utilizando a informacao de lookahead
	while(transition_table[nextstate][type_lookahead] != 0) { 
		current = (char)fgetc(file);
		character = get_type_char(current);
		alloc_add_list(current, lexeme);
		lookahead = get_lookahead(file);
		type_lookahead = get_type_char(lookahead);
		
		if(transition_table[nextstate][character] == 1) 
			break;

		nextstate = transition_table[nextstate][character];
	}


	tokenType = typeState(nextstate);
	token->type = tokenType;

	alloc_add_list('\0', lexeme);
	token->lexeme = get_string_array(lexeme);
	
}



		///////////
		//Publico//
		///////////

void createTransitionTable() {
	int i, j;
	for (i = 0; i < NUM_STATES; i++)
		for (j = 0; j < NUM_ENUM; j++)
			transition_table[i][j] = 0;

	// IDENTIFICADOR_ou_PALAVRA RESERVADA 
	transition_table[1][letter] = 2;
	transition_table[2][letter] = 2;
	transition_table[2][digit] = 2;

	// NUM
	transition_table[1][digit] = 3;
	transition_table[3][digit] = 3;

	// SPACE ou LINEBREAK (;)
	transition_table[1][space] = 1;
	transition_table[1][linebreak] = 1;

	// COMMENT 
	transition_table[1][sharp] = 4;
	transition_table[4][letter] = 4;
	transition_table[4][digit] = 4;
	transition_table[4][space] = 4;
	transition_table[4][sharp] = 4;
	transition_table[4][equal] = 4;
	transition_table[4][special] = 4;
	transition_table[4][invalid] = 4;
	transition_table[4][aspas] = 4;
	transition_table[4][linebreak] = 1;

	// SPECIAL CHARACTERS: >, <, ! (different), +, -, /, *, {, }, [, ], ',', " " "
	transition_table[1][special] = 5;

	// COMPARASION (==)
	transition_table[1][equal] = 6;
	transition_table[6][equal] = 1;

	// STRING
	transition_table[1][aspas] = 9;
    transition_table[9][letter] = 9;
    transition_table[9][digit] = 9;
    transition_table[9][space] = 9;
    transition_table[9][sharp] = 9;
    transition_table[9][equal] = 9;
    transition_table[9][special] = 9;
    transition_table[9][linebreak] = 9;
	transition_table[9][invalid] = 9;
    transition_table[9][aspas] = 1;

	// iNVALID 
	transition_table[1][invalid] = 7;

	// END OF FILE
	transition_table[1][eof] = 8;
}


void nextToken() {
	getToken();
	endToken();
}

void createFile(char *path){
	file = fopen(path, "r");
	if (file == NULL) {
		printf("Nao foi possivel abrir o arquivo %s", path);
	}
}

void closeFile(){
	fclose(file);
}





