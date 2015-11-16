
#include <stdlib.h>
#include <stdio.h>


#include "LEXICO/token.h"

char funcao2(FILE *file){
	char ret;
	ret = (char)fgetc(file);
	return ret;
}

char funcao(FILE *file){
	char ret;
	ret = funcao2(file);
	return ret;
}




int main() {

	char * filename = "codigo.txt";

	FILE *file;

	file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error: could not open file %s", filename);
	}

	char a;  
	int x;

	while (x<100){
		a = funcao(file);
		printf("%c \n", a);
		x++;
	}
	
	return 0;
}


