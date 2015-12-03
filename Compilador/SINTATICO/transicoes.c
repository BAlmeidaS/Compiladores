#include "machines.h"

void erasingTransitionTable() {
	int i, j, k;
	for(i=0; i < EXPRESSION_TYPES; i++)
		for(j=0; j < TOKEN_TYPES; j++)
			for(k=0; j < MAX_LENGTH; j++)
				machine->transition_table[i][j][k] = MACHINE_INVALID_STATE;
}


/////////////
// Public  //
/////////////

void init_machines() {
	Machine program, command, expression;

	/* Machine Program: MTYPE_PROGRAM */
	erasingTransitionTable();
//	tabela [maquina de estado] [entrada] [current state] = next state
// Maquina de Estatos 1
transitionTable[1][WORD_PROGRAM][0] = 1
transitionTable[1][WORD_ABRE_CHAVES][1] = 2
transitionTable[1][WORD_FECHA_CHAVES][2] = 3
transitionTable[1][WORD_PONTO_VIRGULA][3] = 4

// Maquina de Estatos 3
transitionTable[3][WORD_INT][0] = 1 
transitionTable[3][WORD_CHAR][0] = 1
transitionTable[3][WORD_BOOLEAN][0] = 1 

// Maquina de Estatos 4
transitionTable[4][WORD_ABRE_COLCHETES][1] = 2
transitionTable[4][WORD_FECHA_COLCHETES][3] = 4 

// Maquina de Estatos 5
transitionTable[5][WORD_VIRGULA][1] = 0 

// Maquina de Estatos 6
transitionTable[6][WORD_IDENTIFICADOR][0] = 1





// Maquina de Estatos 10
transitionTable[10][WORD_EQUAL][1] = 2
transitionTable[10][WORD_PONTO_VIRGULA][3] = 4

// Maquina de Estatos 11
transitionTable[11][WORD_IF][0] = 1 
transitionTable[11][WORD_ELSE][7] = 8 
transitionTable[11][WORD_ABRE_PARANTESES][1] = 2
transitionTable[11][WORD_FECHA_PARENTESES][3] = 4 
transitionTable[11][WORD_ABRE_CHAVES][4] = 5 
transitionTable[11][WORD_FECHA_CHAVES][6] = 7
transitionTable[11][WORD_ABRE_CHAVES][8] = 9 
transitionTable[11][WORD_FECHA_CHAVES][10] = 11 

// Maquina de Estatos 12
transitionTable[12][WORD_ABRE_PARANTESES][1] = 2 
transitionTable[12][WORD_FECHA_PARENTESES][3] = 4
transitionTable[12][WORD_ABRE_CHAVES][4] = 5
transitionTable[12][WORD_FECHA_CHAVES][5] = 6
transitionTable[12][WORD_WHILE][0] = 1 

// Maquina de Estatos 13
transitionTable[13][WORD_INPUT][0] = 1
transitionTable[13][WORD_PONTO_VIRGULA][2] = 3 

// Maquina de Estatos 14
transitionTable[14][WORD_PRINT][0] = 1 
transitionTable[14][WORD_PONTO_VIRGULA][2] = 3 

// Maquina de Estatos 15
transitionTable[15][WORD_SOMA][1] = 0 
transitionTable[15][WORD_MENOS][1] = 0

// Maquina de Estatos 16
transitionTable[16][WORD_VEZES][1] = 0 
transitionTable[16][WORD_DIVISAO][1] = 0 

// Maquina de Estatos 17
transitionTable[17][WORD_ABRE_PARANTESES][0] = 2 
transitionTable[17][WORD_FECHA_PARENTESES][3] = 1 


// Maquina de Estatos 20
transitionTable[20][WORD_EQUAL][0] = 1 
transitionTable[20][WORD_EQUAL][1] = 2 
transitionTable[20][WORD_MENOR_QUE][0] = 1 
transitionTable[20][WORD_MAIOR_QUE][0] = 1 
transitionTable[20][WORD_NOT][0] = 1

// Maquina de Estatos 21
transitionTable[21][WORD_ABRE_PARANTESES][1] = 2 
transitionTable[21][WORD_FECHA_PARENTESES][2] = 3
transitionTable[21][WORD_FECHA_PARENTESES][3] = 4 




//FALTA AS TRANSICOES QUE CHAMAM MAQUINAS, AS CHAMADAS DE FUNCAO



}
