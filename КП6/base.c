#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "base.h"

int read_applicants(FILE *in, applicants *s)
{
    return fscanf(in, "%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\t%s\t\n", s->surname, s->initials, s->gender, &s->num, s->medal, &s->math, &s->ict, &s->rus, s->writting) == 9;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: program input_filename output_filename\n");
        return 1;
    }
    applicants s;
    FILE *out = fopen(argv[2], "w");
    FILE *in = fopen(argv[1], "r");
    if (!(out && in))
    {
        perror("Can't open file");
        return 2;
    }
    while (read_applicants(in, &s))
    {
        fwrite(&s, sizeof(s), 1, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}
