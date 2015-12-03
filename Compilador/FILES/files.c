#include "files.h"


void createCode() {
	printf("teste \n");
	FILE * enviroment = fopen("enviroment.asm", "r"); //PRECISA CRIAR UM ARQUIVO DE ENVIROMENT COM O ASSEMBLY DA MVN
	char buffer[512];

	if (enviroment != NULL)
		while (!feof(enviroment)) {
			fgets(buffer, sizeof(buffer), enviroment);
			if(buffer == NULL) break;
			else {
				printf("%s\n", buffer);
				fputs(buffer, outFile->code);
			}
		}
	fclose(enviroment);
}

void createData() {
	fprintf(outFile->data, "\t\t @ /0A00\n");
}



/////////////
// Public  //
/////////////
void createFile(char *path){
	file = fopen(path, "r");
	if (file == NULL) 
		printf("Nao foi possivel abrir o arquivo %s", path);
}

void closeFile(){
	fclose(file);
}

void createOutFile(char *path){

	outFile = (out *)malloc(sizeof(out));
	outFile->filepath = path;
	char *filepath;

	filepath = "code.asm";
	outFile->code = fopen(filepath, "w+");
	if(outFile->code == NULL)
		fprintf(stderr,"Não conseguiu criar o arquivo code.asm.\n");
	else 
		createCode();

	filepath = "data.asm";
	outFile->data = fopen(filepath, "w+");
	if (outFile->data == NULL) 
		fprintf(stderr,"Não conseguiu criar o arquivo data.asm.\n");
	else 
		createData();
}



 