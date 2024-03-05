#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        if (jump) {
            for (int i = 0; i < level * 16; i++) {
                printf(" ");
            }
            printf(".\n");
            for (int i = 0; i < level * 16; i++) {
                printf(" ");
            }
            jump = 0;
        }

        if (tree->right == NULL) {
            printf(" . . . .%08.4f\n", tree->value);
            jump = 1;
        } else {
            printf(" . . . .%08.4f", tree->value);
        }
        tree->visited = 1;
    }

    if (tree->left == NULL && tree->right == NULL && tree->parent == NULL){
        tree->visited = 0;
        return;
    }

    if (tree->left == NULL && tree->right == NULL && tree->parent != NULL) {
        visual(tree->parent, level - 1, jump);
    } else if (tree->right == NULL) {
        if (!tree->left->visited) {
            visual(tree->left, level + 1, jump);
        } else {
            tree->left->visited = 0;
            if (tree->parent != NULL) visual(tree->parent, level - 1, jump); else tree->visited = 0;
        }
    } else if (tree->left == NULL) {
        if (!tree->right->visited) {
            visual(tree->right, level + 1, jump);
        } else {
            tree->right->visited = 0;
            if (tree->parent != NULL) visual(tree->parent, level - 1, jump); else tree->visited = 0;
        }
    } else if (tree->left->visited && tree->right->visited && tree->parent != NULL) {
        tree->left->visited = 0;
        tree->right->visited = 0;
        visual(tree->parent, level - 1, jump);
    } else if (!(tree->right->visited)) {
        visual(tree->right, level + 1, jump);
    } else if (!(tree->left->visited)) {
        visual(tree->left, level + 1, jump);
    } else {
        tree->visited = 0;
        if (tree->left != NULL) tree->left->visited = 0;
        if (tree->right != NULL) tree->right->visited = 0;
    }
}

int main() {
    char chr[15];
    BNode *node = NULL;
    printf(" ");
    while (1) {
        printf("tree> ");
        scanf("%s", chr);
        if (!strcmp(chr, "insert")) {
            float data;
            scanf("%f", &data);
            if (node == NULL) {
                node = new_node(data);
            } else {
                insert(node, data);
            }
        }
        if (!strcmp(chr, "show")) {
            if (node != NULL) {
                visual(node, 0, 1);
                printf(" ");
            } else printf("null\n ");

        }
        if (!strcmp(chr, "exit")) return 0;
        if (!strcmp(chr, "clear")) node = NULL;
    }
}