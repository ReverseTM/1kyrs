#include <time.h>
#include <stdlib.h>
#include "table.h"
#include "stack.h"

void printTable(row *arr, const int size)
{
    printf("╔═════════╦══════════════════════════════════════════════════╗\n");
    printf("║   Ключ  ║                    Значение                      ║\n");
    printf("╠═════════╬══════════════════════════════════════════════════╣\n");
    for (int i = 0; i < size; i++)
        printf("║%9d║%50s║\n", arr[i].key, arr[i].stroke);
    printf("╚═════════╩══════════════════════════════════════════════════╝\n");
}

void getRow(FILE *stream, char *str, const int size)
{
    int cnt = 0;
    char ch;
    while ((ch = getc(stream)) != '\n' && cnt < size - 1)
        str[cnt++] = ch;
    str[cnt] = '\0';
}

void swapRows(row *r1, row *r2)
{
    row tmp;
    tmp = *r1;
    *r1 = *r2;
    *r2 = tmp;
}

int binSearch(const row *arr, const int size, const long int key_index)
{
    int start = 0, end = size - 1, mid;
    if (size <= 0)
        return -1;
    while (start < end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid].key == key_index)
            return mid;
        else if (arr[mid].key < key_index)
            start = mid + 1;
        else
            end = mid;
    }
    if (arr[end].key == key_index)
        return end;
    return -1;
}

void quick_sort(row *a, size_t size)
{
    size_t i, j;
    int tmp, pivot;
    Stack *lows = createStack();
    Stack *highs = createStack();
    size_t low, high;

    push(lows, 0);
    push(highs, size - 1);

    while (lows->size > 0)
    {
        low = pop(lows);
        high = pop(highs);
        i = low;
        j = high;
        pivot = a[(low + (high - low) / 2)].key;

        do
        {
            while (a[i].key < pivot)
                i++;
            while (a[j].key > pivot)
                j--;

            if (i <= j)
            {
                if (a[i].key > a[j].key)
                {
                    swapRows(&a[i], &a[j]);
                }
                i++;
                if (j > 0)
                {
                    j--;
                }
            }
        } while (i <= j);

        if (i < high)
        {
            push(lows, i);
            push(highs, high);
        }
        if (j > low)
        {
            push(lows, low);
            push(highs, j);
        }
    }
    freeStack(&lows);
    freeStack(&highs);
}

int random_(const int a, const int b)
{
    return a + rand() % (b - a + 1);
}

void shuffle(row *arr, const int size)
{
    int i, j, k;
    srand((unsigned int)time(0));
    for (k = 0; k < size; k++)
    {
        i = randomtwo(0, size - 1);
        j = randomtwo(0, size - 1);
        swapRows(&arr[i], &arr[j]);
    }
}

void reverse(row *arr, const int size)
{
    int i, j;
    for (i = 0, j = size - 1; i < j; i++, j--)
        swapRows(&arr[i], &arr[j]);
}

int isSorted(const row *arr, const int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i].key > arr[i + 1].key)
            return 0;
    return 1;
}
