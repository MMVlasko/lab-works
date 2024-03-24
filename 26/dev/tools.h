#ifndef LAB_WORKS_TOOLS_H
#define LAB_WORKS_TOOLS_H

typedef struct list_node {
    int value;
    struct list_node *prev;
    struct list_node *next;
} ListNode;

typedef struct {
    ListNode *head;
    int size;
} List;

typedef struct {
    ListNode *node;
} Iterator;

List *new_list(void);

void next(Iterator*);

void append(int, List*);

int insert_after(int, int, List*);

void print_list(List*);

#endif
