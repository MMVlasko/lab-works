#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

List *new_list(void) {
    List *list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

void next(Iterator *item) {
    item->node = item->node->next;
}

void append(int value, List *list) {
    ListNode *element = (ListNode*)malloc(sizeof(ListNode));
    element->next = NULL;
    element->value = value;

    if (list->head == NULL) {
        list->head = element;
        list->size = 1;
        return;
    }

    Iterator *iter = (Iterator*)malloc(sizeof(Iterator));

    element->next = NULL;
    element->value = value;
    iter->node = list->head;
    while (iter->node->next != NULL) {
        next(iter);
    }
    iter->node->next = element;
    element->prev = iter->node;
    list->size++;
}

int insert_after(int target, int value, List* list) {
    if (!list->size)
        return 0;
    Iterator *iter = (Iterator*)malloc(sizeof(Iterator));
    iter->node = list->head;
    while (iter->node->value != target) {
        if (iter->node->next == NULL) return 0;
        next(iter);
    }
    if (iter->node->next == NULL) {
        append(value, list);
        return 1;
    }
    ListNode *element = (ListNode*)malloc(sizeof(ListNode));
    element->value = value;
    iter->node->next->prev = element;

    element->prev = iter->node;
    element->next = iter->node->next;

    iter->node->next = element;
    list->size++;
    return 1;
}

void print_list(List* list) {
    printf("[");
    if (!list->size) {
        printf("]\n");
        return;
    }
    Iterator *iter = (Iterator*)malloc(sizeof(Iterator));
    iter->node = list->head;
    while (iter->node->next != NULL) {
        printf("%d, ", iter->node->value);
        next(iter);
    }
    printf("%d]\n", iter->node->value);
    free(iter);
}
