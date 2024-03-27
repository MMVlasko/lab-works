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
        element->prev = NULL;
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

int insert_after(ListNode *node, int value, List* list) {
    if (node->next == NULL) {
        append(value, list);
        return 1;
    }
    ListNode *element = (ListNode*)malloc(sizeof(ListNode));
    element->value = value;
    if (node == NULL) {
        element->next = list->head;
        list->head->prev = element;
        list->head = element;
        return 1;
    }
    node->next->prev = element;

    element->prev = node;
    element->next = node->next;

    node->next = element;
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

//int delete(int target, List *list) {
//    if (!list->size)
//        return 0;
//    Iterator *iter = (Iterator*)malloc(sizeof(Iterator));
//    iter->node = list->head;
//    while (iter->node->value != target) {
//        if (iter->node->next == NULL)
//            return 0;
//        next(iter);
//    }
//    if (iter->node->next != NULL && iter->node->prev != NULL) {
//        iter->node->prev->next = iter->node->next;
//        iter->node->next->prev = iter->node->prev;
//    } else if (iter->node->next == NULL)
//        iter->node->prev->next = NULL;
//    else {
//        iter->node->next->prev = NULL;
//        list->head = iter->node->next;
//    }
//    free(iter->node);
//    free(iter);
//    list->size--;
//    return 1;
//}

int delete(ListNode *node, List *list) {
    if (node->next != NULL && node->prev != NULL) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    } else if (node->next == NULL)
        node->prev->next = NULL;
    else {
        node->next->prev = NULL;
        list->head = node->next;
    }
    free(node);
    return 1;
}

void sort(List *list, ListNode *base, ListNode* end, int size) {
//    printf("%d %d %d\n", base->value, size, end == NULL);
    if (size < 2)
        return;
    Iterator *iter = (Iterator*)malloc(sizeof(Iterator));
    iter->node = base;

    int k = 0;
    while (k <= size / 2 - 1) {
        next(iter);
        k++;
    }
    ListNode *this = iter->node;
//    printf("%d\n\n", this->value);
    iter->node = base;
    int m = size / 2 - 1, n = size / 2;
//    printf("fghj");
    while (iter->node != this) {
//        print_list(list);
        if (iter->node->value >= this->value) {
            int temp = iter->node->value;
            ListNode *temp_node = iter->node->next;
            delete(iter->node, list);
            iter->node = temp_node;
            insert_after(this, temp, list);
            m--;
            n++;
        } else
            next(iter);
    }
    while (iter->node != end) {
//        print_list(list);
        if (iter->node->value < this->value) {
            int temp = iter->node->value;
            ListNode *temp_node = iter->node->next;
            delete(iter->node, list);
            iter->node = temp_node;
            insert_after(this->prev, temp, list);
            m++;
            n--;
        } else
            next(iter);
    }
    sort(list, list->head, this, m);
    sort(list, this->next, NULL, n);
}














