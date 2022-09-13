#include "machine_word.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void scan_str(char *str)
{
    char symb = ' ';
    uint8_t count_str = 0;
    bool end_str = true, flag = false;

    while (symb != '\n' && count_str < 255)
    {
        scanf("%c", &symb);

        if (symb == '\n' || symb == ' ')
        {
            end_str = false;
        }

        if (symb == '1')
            flag = true;

        if (end_str && flag)
        {
            str[count_str] = symb;
            count_str++;
        }
    }
}

uint64_t conversion(char *str)
{
    uint64_t digit = 0;

    for (int i = strlen(str) - 1; i > -1; i--)
    {
        if (str[i] == '1')
            digit += pow(2, strlen(str) - i - 1);
    }

    return digit;
}

uint8_t *get_word(char *str, uint64_t digit)
{
    uint8_t *word = (uint8_t *)malloc(SIZE_BYTE * sizeof(uint8_t));
    for (int i = SIZE_BYTE - 1; i >= 0; i--)
    {
        word[i] = digit >> ((8 - i - 1) * 8) & 255;
    }

    return word;
}

void print_word(uint8_t *word)
{
    printf("[ ");
    for (int i = 0; i < SIZE_BYTE; i++)
    {
        printf("%d ", word[i]);
    }

    printf("] -> ");
}
