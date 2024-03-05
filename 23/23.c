#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int visited;
    float value;
    struct node *left;
    struct node *right;
    struct node *parent;
} BNode;

BNode *new_node(float data) {
    BNode *node = (BNode*)malloc(sizeof(BNode));
    node->value = data;
    node->left = NULL;
    node->right = NULL;
    node->visited = 0;
    node->parent = NULL;
    return node;
}

void insert(BNode *tree, float data) {
    if (tree->left == NULL && data <= tree->value) {
        tree->left = new_node(data);
        tree->left->parent = tree;
    } else if (tree->right == NULL && data >= tree->value) {
        tree->right = new_node(data);
        tree->right->parent = tree;
    } else if (data <= tree->value) {
        insert(tree->left, data);
    } else {
        insert(tree->right, data);
    }
}

void visual(BNode *tree, int level, int jump) {
    if (!(tree->visited)) {
        char tab[level * 16];
        if (jump) {
            for (int i = 0; i < level * 16; i++) {
                tab[i] = ' ';
            }
            tab[level * 16 + 6] = 'c';
            tab[level * 16 + 5] = '%';
            tab[level * 16 + 4] = 'f';
            tab[level * 16 + 3] = '4';
            tab[level * 16 + 2] = '.';
            tab[level * 16 + 1] = '%';
        }

        if (tree->left == NULL && tree->right == NULL) {
            if (jump) {
                printf(tab, tree->value, '\n');
            } else {
                printf("        %.4f\n", tree->value);
                jump = 1;
            }
            tree->visited = 1;
        } else {
            if (jump) {
                printf(tab, tree->value, ' ');
                jump = 0;
            } else {
                printf("        %.4f", tree->value);
            }
            tree->visited = 1;

        }
    }
    if (tree->left == NULL && tree->right == NULL) {
        visual(tree->parent, level - 1, jump);
    } else if (tree->right == NULL) {
        if (!tree->left->visited) {
            visual(tree->left, level + 1, jump);
        }
    } else if (tree->left == NULL) {
        if (!tree->right->visited) {
            visual(tree->right, level + 1, jump);
        }
    } else if (tree->left->visited && tree->right->visited && tree->parent != NULL) {
        visual(tree->parent, level - 1, jump);
    } else if (!(tree->right->visited)) {
        visual(tree->right, level + 1, jump);
    } else if (!(tree->left->visited)) {
        visual(tree->left, level + 1, jump);
    }
}

int main() {
    BNode *i = new_node(37);
    insert(i, 3);
    insert(i, 56);
    insert(i, 23);
    insert(i, 1);
//    printf("%f", i->right->parent->value);
    visual(i, 0, 1);
    free(i);
}