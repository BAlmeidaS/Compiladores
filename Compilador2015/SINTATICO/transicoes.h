#ifndef TRANSICOES_H_
#define TRANSICOES_H_

#include <stdlib.h>

//////////// MAQUINAS DE ESTADO ////////////

#define INVALID_STATE 				-1

#define SUB_INVALID					-1

#define SUB_PROGRAM					1
#define SUB_DECLARA_IDENTIFICADOR	2
#define SUB_TIPO					3
#define SUB_AGREGADO_HOMOGENEO		4
#define SUB_LISTA_DE_EXPRESSOES		5
#define SUB_IDENTIFICADOR			6
#define SUB_COMANDO					9
#define SUB_COMANDO_ATRIBUICAO		10
#define SUB_COMANDO_IF				11
#define SUB_COMANDO_WHILE			12
#define SUB_COMANDO_INPUT			13
#define SUB_COMANDO_OUTPUT			14
#define SUB_EXPRESSAO				15
#define SUB_TERMO					16
#define SUB_FATOR					17
#define SUB_NUMERO					18
#define SUB_CONDICAO				19
#define SUB_OPERADOR_CONDICIONAL	20
#define SUB_CHAMADA_FUNCAO			21




//////////// TOKENS ////////////

#define WORD_INVALID				-1

#define WORD_PROGRAM				0		/**/
#define WORD_RETURN					1		/**/
#define WORD_INT					2		/**/
#define WORD_CHAR					3		/**/
#define WORD_BOOLEAN				4		/**/
#define WORD_ABRE_COLCHETES			5		/**/
#define WORD_FECHA_COLCHETES		6		/**/
#define WORD_VIRGULA				7		/**/
#define WORD_EQUAL					8		/**/
#define WORD_IF						9		/**/
#define WORD_ELSE					10		/**/
#define WORD_ABRE_PARANTESES		11		/**/
#define WORD_FECHA_PARENTESES		12		/**/
#define WORD_ABRE_CHAVES			13		/**/
#define WORD_FECHA_CHAVES			14		/**/
#define WORD_WHILE					15		/**/
#define WORD_INPUT					16		/**/
#define WORD_PRINT					17		/**/
#define WORD_SOMA					18		/**/
#define WORD_MENOS					19		/**/
#define WORD_PONTO_VIRGULA			20		/**/
#define WORD_VEZES					21		/**/
#define WORD_DIVISAO				22		/**/
#define WORD_MENOR_QUE				23		/**/
#define WORD_MAIOR_QUE				24		/**/
#define WORD_VOID					25		/**/
#define WORD_IDENTIFICADOR			27		/**/
#define WORD_NUMERO					26		/**/
#define WORD_NOT					27		/**/


/************************************************************/
/*						MACHINE								*/
/************************************************************/

#define MAX_LENGTH 12
#define STATES 98
#define TOKEN_TYPES 27
#define EXPRESSION_TYPES 21


typedef struct stateMachine {
	int machine_id;
	int current_state;
	int final_state[MAX_LENGTH];
	int machine_calls[STATES][EXPRESSION_TYPES];
} stateMachine;


int transitionTable[EXPRESSION_TYPES][TOKEN_TYPES][MAX_LENGTH];

stateMachine machines_array[EXPRESSION_TYPES];

void createExpressions();
void is_machine_in_final_state(int machineId);

#endif /* TRANSICOES_H_ */
