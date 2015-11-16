#ifndef LEXICO_H_
#define LEXICO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "token.h"
#include "../ADT/linked_list.h"


#define NUM_STATES 100
#define NUM_ENUM 90

typedef enum {
	letter,
	digit,
	space,
	special,
	equal,
	linebreak,
	sharp,
	eof,
	invalid,
	aspas
} character;

int transition_table[NUM_STATES][NUM_ENUM];

FILE *file;

void createTransitionTable();
void nextToken();

void createFile(char *path);
void closeFile();

#endif