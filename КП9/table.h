#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include "table.h"

typedef struct row
{
    int key;
    char stroke[150];
} row;

void printTable(row *arr, const int size);
void getRow(FILE *stream, char *str, const int size);
void swapRows(row *r1, row *r2);
int binSearch(const row *arr, const int size, const long int key);
void quick_sort(row *a, size_t size);
void shuffle(row *arr, const int size);
void reverse(row *arr, const int size);
int random_(const int a, const int b);
int isSorted(const row *arr, const int size);

#endif
