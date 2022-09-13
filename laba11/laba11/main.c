#include <stdio.h>

typedef enum {
    input, cipher, space, end_stroke, putcher, tab
} State;

State state = input;

int letter_number(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int main(void)
{
    char symbol = ' ';
    int counter_number = 0;

    while (symbol != EOF) {
        switch (state) {
            case input:
                symbol = getchar();

                if (letter_number(symbol)) {
                    state = cipher;
                }

                if (symbol == ' ') {
                    state = space;
                }

                if (symbol == '\t') {
                    state = tab;
                }

                if (!letter_number(symbol) && symbol != ' ' && symbol != '\n' && symbol != '\t') {
                    state = putcher;
                }

                if (symbol == '\n') {
                    state = end_stroke;
                }

                break;

            case cipher:
                if (symbol >= 'A' && symbol <= 'Z') {
                    counter_number %= 26;
                    symbol = symbol + counter_number + 3;

                    if (symbol > 'Z') {
                        while (symbol > 'Z') {
                            symbol = 'A' + (symbol - 'Z' - 1);
                        }

                        printf("%c", symbol);
                    } else {
                        printf("%c", symbol);
                    }
                }

                if (symbol >= 'a' && symbol <= 'z') {
                    counter_number %= 26;
                    if (symbol + counter_number + 3 > 'z') {
                        symbol = 'a' + (symbol + counter_number + 3) % 122 - 1;

                        if (symbol > 'z') {
                            while (symbol > 'z') {
                                symbol = 'a' + (symbol - 'z' - 1);
                            }

                            printf("%c", symbol);
                        } else {
                            printf("%c", symbol);
                        }
                    } else {
                        symbol = symbol + counter_number + 3;

                        if (symbol > 'z') {
                            while (symbol > 'z') {
                                symbol = 'a' + (symbol - 'z' - 1);
                            }

                            printf("%c", symbol);
                        } else {
                            printf("%c", symbol);
                        }
                    }
                }

                if (symbol >= '0' && symbol <= '9') {
                    counter_number %= 10;
                    symbol = symbol + counter_number + 3;

                    if (symbol > '9') {
                        while (symbol > '9') {
                            symbol = '0' + (symbol - '9' - 1);
                        }

                        printf("%c", symbol);
                    } else {
                        printf("%c", symbol);
                    }
                }

                counter_number++;
                state = input;

                break;

            case putcher:
                counter_number++;

                printf("%c", symbol);

                state = input;

                break;

            case space:
                counter_number = 0;

                printf("%c", symbol);

                state = input;

                break;

            case tab:
                counter_number = 0;

                printf("%c", symbol);

                state = input;

                break;

            case end_stroke:
                counter_number = 0;

                printf("\n");

                state = input;

                break;
        }
    }
    return 0;
}