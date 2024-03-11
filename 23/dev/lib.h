#ifndef LAB_WORKS_LIB_H
#define LAB_WORKS_LIB_H

typedef struct node {
    float value;
    struct node *left;
    struct node *right;
    struct node *parent;
} BNode;

BNode *new_node(float);

void insert(BNode*, float);

void show(BNode*, int, int, const char[2]);

int delete(BNode*, float);

int is_btree(BNode*);

#endif