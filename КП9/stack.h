#ifndef STACK_H
#define STACK_H

#define STACK_INIT_SIZE 100

typedef struct Stack
{
    size_t size;
    size_t limit;
    int *data;
} Stack;

Stack *createStack();
void freeStack(Stack **s);
void push(Stack *s, int item);
int pop(Stack *s);

#endif