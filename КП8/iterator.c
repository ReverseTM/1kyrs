#include <stdlib.h>
#include <stdio.h>
#include "iterator.h"

listIterator *iteratorCreate(list *lst)
{
    if (lst != NULL)
    {
        listIterator *it = (listIterator *)malloc(sizeof(listIterator));
        it->node = lst->head;
        return it;
    }
    else
        return NULL;
}

void iteratorNext(listIterator *it)
{
    if (it->node == NULL)
    {
        printf("End of the list\n");
    }
    else
    {
        it->node = it->node->next;
    }
}

list_node *iteratorGet(listIterator *it)
{
    return it->node;
}

void iteratorSet(list_node *lst, listIterator *it)
{
    it->node = lst;
}
