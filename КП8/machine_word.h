#ifndef _WORD_H_
#define _WORD_H_

#include <inttypes.h>
#include <stdlib.h>

#define SIZE_STR 64
#define SIZE_BYTE 8

void scan_str(char *str);
uint64_t conversion(char *str);
uint8_t *get_word(char *str, uint64_t digit);
void print_word(uint8_t *word);

#endif //_WORD_H_
