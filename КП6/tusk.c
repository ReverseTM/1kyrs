#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "base.h"

int main(int argc, char *argv[])
{
    FILE *in;
    int f = 0, p = 0;
    int passing_score = 0;
    if (argc != 3)
    {
        printf("Usage: program [-key] filename\nKeys: -f xor -p\n");
        return 1;
    }
    if (strcmp(argv[1], "-f") == 0)
    {
        f = 1;
        in = fopen(argv[2], "r");
    }
    else if (strcmp(argv[1], "-p") == 0)
    {
        printf("Enter passing score:\n");
        scanf("%d", &passing_score);
        p = 1;
        in = fopen(argv[2], "r");
    }
    else
    {
        printf("Usage: program [-key] filename\nKeys: -f xor -p\n");
        return 2;
    }
    applicants stud;
    if (f)
    {
        printf("___________________________________________________________________________________\n");
        printf("|        ФАМИЛИЯ         | ИО | ПОЛ | ШКОЛА | МЕДАЛЬ | МАТ | ИКТ | РУС | СОЧ |\n");
        printf("___________________________________________________________________________________\n");
    }
    while (fread(&stud, sizeof(stud), 1, in) == 1)
    {
        if (f)
        {
            printf("|%-25s|%-3s|%-3s|%-6d|%-7s|%-6d|%-5d|%-5d|%-7s|\n", stud.surname, stud.initials, stud.gender, stud.num,
                   stud.medal, stud.math, stud.ict, stud.rus, stud.writting);
            printf("___________________________________________________________________________________\n");
        }
    }
    if (f)
    {
        return 0;
    }
    fseek(in, 0, SEEK_SET);
    fseek(in, 0, SEEK_SET);
    printf("\t\t\t\t\tANSWER\n");
    printf("_________________________________________________________________________________\n");
    printf("|        ФАМИЛИЯ         | ИО | ПОЛ | ШКОЛА | МЕДАЛЬ | МАТ | ИКТ | РУС | СОЧ |\n");
    printf("_________________________________________________________________________________\n");
    while (fread(&stud, sizeof(stud), 1, in) == 1)
    {
        if (stud.medal && stud.ict + stud.math + stud.rus < passing_score)
        {
            printf("|%-25s|%-3s|%-3s|%-6d|%-7s|%-6d|%-5d|%-5d|%-7s|\n", stud.surname, stud.initials, stud.gender, stud.num,
                   stud.medal, stud.math, stud.ict, stud.rus, stud.writting);
            printf("___________________________________________________________________________________\n");
        }
    }
    fclose(in);
    return 0;
}
