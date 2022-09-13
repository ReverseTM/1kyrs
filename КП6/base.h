#ifndef LAABS_applicants_H
#define LAABS_applicants_H

typedef struct
{
    char surname[25];
    char initials[10];
    char gender[5];
    int num;
    char medal[3];
    int math;
    int ict;
    int rus;
    char writting[10];
} applicants;

#endif
