#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "deque.h"

int main(int argc,char **argv) {
    deque deque;
    deque_create(&deque);
    char str[20];
    el_type n1;

    printf(
            "\n\tCommands:\n"
            "---------------------------------------------\n"
            "push_front 'n' - add 'n' to the head\n"
            "push_last 'n' - add 'n' to the tail\n"
            "pop_front - pull an element from the head\n"
            "pop_last - pull an element from the tail\n"
            "run - performs a task\n"
            "head - element from the head\n"
            "tail - element from the lt\n"
            "sort - sort deque\n"
            "size - print size deque\n"
            "empty - check the dek for emptiness\n"
            "print - print deque\n"
            "quit - exit\n"
            "---------------------------------------------\n"
    );

    while(true)
    {
        scanf("%s",str);
        if(!strcmp(str,"push_front"))
        {
            scanf("%d\n",&n1);
            push_front(&deque,n1);
        }
        else if(!strcmp(str,"push_last"))
        {
            scanf("%d\n",&n1);
            push_last(&deque,n1);
        }
        else if(!strcmp(str,"pop_front"))
            pop_front(&deque);
        else if(!strcmp(str,"pop_last"))
            pop_last(&deque);
        else if(!strcmp(str,"size"))
            size_deque(&deque);
        else if(!strcmp(str,"empty"))
            printf(deque_is_empty(&deque) ? "Deque is empty\n":"Deque in not empty\n");
        else if (!strcmp(str,"head"))
            head(&deque);
        else if (!strcmp(str, "tail"))
            tail(&deque);
        else if (!strcmp(str, "sort"))
            sort(&deque);
        else if (!strcmp(str, "run"))
            run(&deque, deque.number_of_elements);
        else if(!strcmp(str,"print"))
            deque_print(&deque);
        else if(!strcmp(str,"quit"))
            break;
    }
    deque_destroy(&deque);
    return 0;
}

