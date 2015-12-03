
#ifndef FILES_H_
#define FILES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

typedef struct  out {
	char * filepath;
	FILE * code;
    FILE * data;
} out;

FILE *file;

out *outFile;

void createFile(char *path);
void createOutFile(char *path);

void closeFile();


#endif 