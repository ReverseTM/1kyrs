#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>

typedef int el_type;

typedef struct deque{
    el_type *elements; // элементы
    el_type size; // вместимость
    int number_of_elements; // размер
}deque;

typedef struct deque *Deque;

void deque_create(Deque deque);
void deque_destroy(Deque deque);
int deque_size(Deque deque);
bool deque_is_empty(Deque deque);
void resize(Deque deque);
void push_front(Deque deque, int data);
void push_last(Deque deque, int data);
void deque_print(Deque deque);
void run(Deque deque, int size);
el_type pop_last(Deque deque);
el_type pop_front(Deque deque);
void sort(Deque deque);
void head(Deque deque);
void tail(Deque deque);
void size_deque(Deque deque);

#endif // DEQUE_H_INCLUDED