#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define VOWELS (1u<<('a' - 'a') | 1u<<('b' - 'a') | 1u<<('e' - 'a') | 1u<<('k' - 'a') | 1u<<('m' - 'a') | 1u<<('h' - 'a') | 1u<<('o' - 'a') | 1u<<('p' - 'a') | 1u<<('c' - 'a') | 1u<<('t' - 'a') | 1u<<('y' - 'a') | 1u<<('x' - 'a'))

unsigned int intersected_set(unsigned int set_1, unsigned int set_2)
{
    return set_1 & set_2;
}

unsigned int set_union(unsigned int set_1, unsigned int set_2)
{
    return set_1 | set_2;
}

unsigned int complement(unsigned int set_1)
{
    return ~set_1;
}

unsigned int difference(unsigned int set_1, unsigned int set_2)
{
    return ~(set_1 & set_2);
}

int char_to_set(char c)
{
    if (c >= 'a' || c <= 'z') {
        return (1u << (c - 'a'));
    } else {
        return 0;
    }
}

int main(void)
{
    char symbol;
    int letter = 0;
    int flag = 0;
    int res = 0;

    while ((symbol = getchar()) != EOF) {
        if (!(symbol == ' ' || symbol == ',' || symbol == '\t' || symbol == '\n' || symbol == EOF)) {
            symbol = tolower(symbol);
            letter = set_union(letter,char_to_set(symbol));
            flag = 1;
        } else {
            if (intersected_set(letter, complement(VOWELS)) == 0 && flag == 1) {
                res = 1;
            }

            letter = 0;
            flag = 0;
        }
    }
    if (res == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}