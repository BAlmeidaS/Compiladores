
#ifndef TABLE_OF_SYMBOLS_H_
#define TABLE_OF_SYMBOLS_H_

#include "ADT/linked_list.h"

#define LEN_OF_RESERVED_TABLE 10
#define LEN_OF_SPECIAL_CHAR_TABLE 18

#define lenght(array) (sizeof(array)/sizeof(*array))

extern char * reserved_words_table[];
extern char * special_characters_table[];
extern List * identifiers_table;
extern List * constants_table;

int SearchReserverdWords(char * data);
int SearchIdentifier(char * data);
int AddIdentifier(char * data);
int CheckIdentifier(char * data);
int SearchSpecialCharacters(char * data);


#endif /* TABLE_OF_SYMBOLS_H_ */


