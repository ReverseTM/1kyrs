#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "iterator.h"
#include "machine_word.h"

uint8_t *barrier;

int comparison_data(elem_type *data1, elem_type *data2)
{
    for (int i = 0; i < 8; i++)
    {
        if (data1[i] > data2[i])
        {
            printf("%d %d\n", data1[i], data2[i]);
            return 0;
        }
    }
    return 1;
}

int equality_data(elem_type *data1, elem_type *data2)
{
    for (int i = 0; i < 8; i++)
    {
        if (data1[i] != data2[i])
            return 0;
    }
    return 1;
}

list *listCreate()
{
    printf("Set up a barrier: \n");
    char *str = (char *)malloc(SIZE_STR * sizeof(char));
    list *lst = (list *)malloc(sizeof(list));
    lst->head = (list_node *)malloc(sizeof(list_node));
    lst->head->next = NULL;
    scan_str(str);
    lst->head->data = get_word(str, conversion(str));
    barrier = get_word(str, conversion(str));
    return lst;
}

void listPrint(list *lst)
{
    listIterator *it = iteratorCreate(lst);
    if (it->node)
    {
        while (it->node != NULL)
        {
            if (!(equality_data(it->node->data, barrier)))
                print_word(it->node->data);
            it->node = it->node->next;
        }
        printf("BARRIER");
        printf("\n");
    }
}

void listInsert(list *lst, elem_type *data)
{
    listIterator *it = iteratorCreate(lst);
    if (it->node)
    {
        while (it->node->next)
        {
            iteratorNext(it);
        }
        list_node *tail = (list_node *)malloc(sizeof(list_node));
        tail->next = NULL;
        tail->data = barrier;
        it->node->data = data;
        it->node->next = tail;
    }
    else
        printf("The list does not exist!\n");
    free(it);
}

void listRemove(list *lst, elem_type *data)
{
    int flag = 0;
    listIterator *it = iteratorCreate(lst);
    list_node *prew;
    if (it->node)
    {
        if (equality_data(it->node->data, data))
        {
            flag = 1;
            lst->head = it->node->next;
            free(it->node);
            it->node = NULL;
        }
        else
        {
            while (it->node->next)
            {
                if (equality_data(it->node->next->data, data))
                {
                    prew = it->node;
                    iteratorNext(it);
                    flag = 1;
                    if (it->node->next != NULL)
                    {
                        prew->next = it->node->next;
                    }
                    free(it->node);
                    it->node = NULL;
                    break;
                }
                iteratorNext(it);
            }
        }
        if (flag)
            printf("Item removed\n");
        else
            printf("The item is not in the list\n");
    }
    else
        printf("The list does not exist!\n");
    free(it);
}

int listLen(list *lst)
{
    int count = 0;
    listIterator *it = iteratorCreate(lst);
    iteratorSet(lst->head, it);
    if (it->node)
    {
        while (it->node->next && !(equality_data(it->node->next->data, barrier)))
        {
            count++;
            iteratorNext(it);
        }
    }
    else
        printf("The list does not exist!\n");
    free(it);
    count++;
    return count;
}

int execute(list *lst, int size)
{
    listIterator *it = iteratorCreate(lst);

    while (it->node->next && !(equality_data(it->node->next->data, barrier)))
    {
        if (!(comparison_data(it->node->data, it->node->next->data)))
            return 0;
        iteratorNext(it);
    }
    return 1;
}
