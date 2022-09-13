#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "struct.h"
#include "iterator.h"
#include "machine_word.h"
// printf("%ld\n", 1234 >> (0 * 8) & 255); // 0 for 1 byte 1 for 2 byte etc
//обработать ввод без ведущих нулей перевести в 10 систему и брать байт
void menu()
{
    printf("Menu:\n");
    printf("1) Add an item to the end of the list\n");
    printf("2) Remove an item from the list\n");
    printf("3) Output a list\n");
    printf("4) Print the length of the list\n");
    printf("5) Completing a variant task\n");
    printf("6) Menu\n");
    printf("7) Delete the list and terminate the program\n");
}

int main(void)
{
    list *lst = listCreate();
    listIterator *it = iteratorCreate(lst);
    char *str = (char *)malloc(SIZE_STR * sizeof(char));

    char state, space = ' ';
    int index;
    menu();
    while (1)
    {
        scanf("%c%c", &state, &space);
        iteratorSet(lst->head, it);
        if (state == '\n' || state == ' ')
            continue;
        switch (state)
        {
        case '1':
            printf("Please enter a machine word :\n");
            str = (char *)realloc(str, SIZE_STR * sizeof(char));
            scan_str(str);
            listInsert(lst, get_word(str, conversion(str)));
            printf("Machine word added\n");
            break;
        case '2':
            printf("Please enter the index of the element you want to delete :\n");
            str = (char *)realloc(str, SIZE_STR * sizeof(char));
            scan_str(str);
            listRemove(lst, get_word(str, conversion(str)));
            break;
        case '3':
            for (int i = 0; i < listLen(lst); i++)
            {
                printf("-----------------------");
            }
            printf("\n");
            for (int i = 0; i < listLen(lst); i++)
            {
                printf("          ");
            }
            printf("LIST");
            for (int i = 0; i < listLen(lst); i++)
            {
                printf("          ");
            }
            printf("\n");
            for (int i = 0; i < listLen(lst); i++)
            {
                printf("-----------------------"); // 22
            }
            printf("\n");
            listPrint(lst);
            break;
        case '4':
            printf("Length of the list: %d\n", listLen(lst));
            break;
        case '5':
            if (!execute(lst, listLen(lst)))
            {
                printf("List is not sorted!\n");
            }
            else
                printf("List is sorted!\n");
            break;
        case '6':
            menu();
            break;
        case '7':
            free(it);
            free(lst);
            return 0;

        default:
            printf("There is no action with this number, select a command from the menu\n");
            break;
        }
    }
}
