#include "deque.h"
#include <stdlib.h>

void deque_create(Deque deque){ // создание дека
    deque -> elements = malloc(sizeof(int));
    deque -> size = 1;
    deque -> number_of_elements = 0;
}
void deque_destroy(Deque deque){ // удаление дека
    if (deque -> elements)
        free(deque -> elements);
}

int deque_size(Deque deque) { // вместимость
    return deque -> size;
}
bool deque_is_empty(Deque deque){ // проверка на заполненность дека (на пустоту)
    return (deque -> number_of_elements == 0) ? true : false;
}
void resize(Deque deque){ // увеличивает размер на один
    deque -> size++;
    deque -> elements = realloc(deque -> elements, deque -> size * sizeof(int));
}
void push_front(Deque deque, el_type data){ // вставка элемента в начало
    if (deque -> number_of_elements == deque ->size){
        resize(deque);
    }
    int tmp_1, tmp_2;
    tmp_1 = data;
    for (int i = 0; i < deque->number_of_elements + 1; i++){
        tmp_2 = deque->elements[i];
        deque->elements[i] = tmp_1;
        tmp_1 = tmp_2;
    }
    deque->number_of_elements++;
}
void push_last(Deque deque, el_type data){ // вставка элемента в конец
    if (deque -> number_of_elements == deque_size(deque)){
        resize(deque);
    }
    deque -> elements[deque -> number_of_elements] = data;
    deque -> number_of_elements++;
}
void deque_print(Deque deque) { // печать дека
    if (deque -> number_of_elements == 0){
        printf("Deque is empty!\n");
        return;
    }
    for (int i = 0; i < deque -> number_of_elements; i++){
        if (i != deque -> number_of_elements - 1){
            printf("[%d] -> ", deque -> elements[i]);
        } else {
            printf("[%d]\n",deque -> elements[i]);
        }
    }
}

el_type pop_last(Deque deque){ // взятие и как бы удаление с конца
    if (deque -> number_of_elements > 0){
        int val = deque -> elements[deque -> number_of_elements-1];
        deque -> elements[deque -> number_of_elements] = 0;
        deque -> number_of_elements--;
        printf("%d\n", val);
    } else {
        printf("Error deque is already empty!\n");
    }
}
el_type pop_front(Deque deque){ // взятие и как бы удаление с начала
    if (deque -> number_of_elements > 0){
        int val = deque -> elements[0];
        for (int i = 0; i < deque -> number_of_elements - 1; i++){
            deque -> elements[i] = deque -> elements[i + 1];
        }
        deque -> elements[deque -> number_of_elements - 1]= 0;
        deque -> number_of_elements--;
        printf("%d\n", val);
    } else {
        printf("Error deque is already empty!\n");
    }
}

void sort(Deque deque) {
    el_type minPosition, tmp;

    for (int i = 0; i < deque->number_of_elements; i++) {
        minPosition = i;

        for (int j = i + 1; j < deque->number_of_elements; j++) {
            if (deque->elements[minPosition] > deque->elements[j]) {
                minPosition = j;
            }
        }
        tmp = deque->elements[minPosition];
        deque->elements[minPosition] = deque->elements[i];
        deque->elements[i] = tmp;
    }
}

void head(Deque deque) {
    printf("Head element: %d\n", deque -> elements[0]);
}

void tail(Deque deque) {
    printf("Tail element: %d\n", deque -> elements[deque -> number_of_elements-1]);
}

void size_deque(Deque deque) {
    printf("Size: %d\n",deque -> number_of_elements);
}

void run(Deque deque, int size) {
    el_type minPosition, tmp;

    el_type mass[size];

    for (int i = 0; i < deque -> number_of_elements; i++) {
        mass[i] = deque -> elements[i];
    }
    for (int i = 0; i < sizeof(mass) / sizeof(mass[0]); i++) {
        minPosition = i;

        for (int j = i + 1; j < sizeof(mass) / sizeof(mass[0]); j++) {
            if (mass[minPosition] > mass[j]) {
                minPosition = j;
            }
        }
        tmp = mass[minPosition];
        mass[minPosition] = mass[i];
        mass[i] = tmp;
    }

    if (sizeof(mass) / sizeof(mass[0]) > 0){
        int maxElement = 0, maxIndex = 0;
        for (int i = 0; i < deque -> number_of_elements; i++) {

            if (deque -> elements[i] > maxElement) {
                maxElement = deque -> elements[i];
                maxIndex = i;
            }
        }

        for (int i = maxIndex; i < deque -> number_of_elements -1; i++) {
            deque -> elements[i] = deque -> elements[i + 1];
        }
        
        deque -> elements[deque -> number_of_elements -1] = 0;
        deque -> number_of_elements--;
        int val = mass[sizeof(mass) / sizeof(mass[0]) - 1];
        printf("Max element: %d\n", val);
    } else printf("Error deque is empty!\n");
}
