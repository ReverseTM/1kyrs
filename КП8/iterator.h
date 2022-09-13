#ifndef ITERATOR_H
#define ITERATOR_H

#include "struct.h"

typedef struct _listIterator
{
    list_node *node;
} listIterator;

listIterator *iteratorCreate(list *lst);
void iteratorNext(listIterator *it);
list_node *iteratorGet(listIterator *it);
void iteratorSet(list_node *l, listIterator *it);

#endif
