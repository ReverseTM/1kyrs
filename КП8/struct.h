#ifndef STRUCT_H
#define STRUCT_H

#include <inttypes.h>

typedef uint8_t elem_type;
typedef struct _list_node list_node;

typedef struct _list_node
{
    elem_type *data;
    list_node *next;
} list_node;

typedef struct
{
    list_node *head;
} list;

int comparison_data(elem_type *data1, elem_type *data2);
int equality_data(elem_type *data1, elem_type *data2);
list *listCreate();
void listPrint(list *lst);
void listInsert(list *lst, elem_type *data);
void listRemove(list *lst, elem_type *data);
int listLen(list *lst);
int execute(list *lst, int size);

#endif
