#include <stdio.h>
#include <stdlib.h>
#include "table.h"

void menu()
{
    printf("Меню:\n");
    printf("1) Вывести таблицу\n");
    printf("2) Найти элемент в таблице по ключу\n");
    printf("3) Отсортировать таблицу\n");
    printf("4) Перемешать данные в таблице\n");
    printf("5) Перевернуть данные в таблице\n");
    printf("6) Меню\n");
    printf("7) Выход\n");
}

int main(void)
{
    const int N = 50;
    int i, size, rule;
    int key_index;
    char ch;
    row arr[N];
    FILE *keys = fopen("keys.txt", "r");
    FILE *text = fopen("stih.txt", "r");
    if (keys == NULL || text == NULL)
    {
        printf("Файл не существует\n");
        return 0;
    }
    i = 0;
    while (i < N && fscanf(keys, "%d", &arr[i].key) == 1)
    {
        getRow(text, arr[i].stroke, sizeof(arr[i].stroke));
        i++;
    }
    fclose(keys);
    fclose(text);
    size = i;
    menu();
    while (1)
    {
        scanf("%d", &rule);
        switch (rule)
        {
        case 1:
            printTable(arr, size);
            break;
        case 2:
            if (!isSorted(arr, size))
            {
                printf("Таблица неотсортирована\n");
            }
            else
            {
                printf("Введите ключ\n");
                scanf("%d", &key_index);
                i = binSearch(arr, size, key_index);
                if (i > -1)
                {
                    printf("По ключу %d найден элемент \"%s\"\n", key_index, arr[i].stroke);
                }
                else
                    printf("Элемент с данным ключом не найден\n");
            }
            break;
        case 3:
            qiuck_sort(arr, size);
            printf("Таблица отсортирована\n");
            break;
        case 4:
            printf("Таблица перемешана\n");
            shuffle(arr, size);
            break;
        case 5:
            printf("Таблица перевёрнута\n");
            reverse(arr, size);
            break;
        case 6:
            menu();
            break;
        case 7:
            return 0;
            break;
        default:
            printf("Выберите корректную команду из меню\n");
            break;
        }
    }
    return 0;
}
