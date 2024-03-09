#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
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
    node->parent = NULL;
    return node;
}

float min(float a, float b) {
    if (a < b)
        return a;
    else
        return b;
}

void insert(BNode *tree, float data) {
    if (tree->left == NULL && data <= tree->value) {
        tree->left = new_node(data);
        tree->left->parent = tree;
    } else if (tree->right == NULL && data >= tree->value) {
        tree->right = new_node(data);
        tree->right->parent = tree;
    } else if (data <= tree->value)
        insert(tree->left, data);
    else
        insert(tree->right, data);
}

void visual(BNode *tree, int level, int jump, const char mode[2]) {
    if (mode[0] == 'f') {
        if (jump) {
            for (int i = 0; i < level * 16; i++)
                printf(" ");
            printf(".\n");
            for (int i = 0; i < level * 16; i++)
                printf(" ");
            jump = 0;
        }

        if (tree->right == NULL) {
            printf(" . . . .%08.4f\n", tree->value);
            jump = 1;
        } else
            printf(" . . . .%08.4f", tree->value);
    }
    if (mode[0] == 'f') {
        if (tree->right == NULL && tree->left == NULL && tree->parent != NULL) {
            if (mode[1] == 'r')
                visual(tree->parent, level - 1, jump, "br");
            else
                visual(tree->parent, level - 1, jump, "bl");
        } else if (tree->right != NULL)
            visual(tree->right, level + 1, jump, "fr");
        else if (tree->left != NULL)
            visual(tree->left, level + 1, jump, "fl");

    }  else if (mode[0] == 'b') {
        if (mode[1] == 'r' && tree->left != NULL)
            visual(tree->left, level + 1, jump, "fl");
        else if (tree->parent != NULL) {
            if (tree->parent->right == tree)
                visual(tree->parent, level - 1, jump, "br");
            else if (tree->parent->left == tree)
                visual(tree->parent, level - 1, jump, "bl");
        }
    }
}

float minimum(BNode *tree) {
    if (tree->right == NULL && tree->left == NULL)
        return tree->value;
    else if (tree->right == NULL)
        return min(tree->value, minimum(tree->left));
    else if (tree->left == NULL)
        return min(tree->value, minimum(tree->right));
    else
        return min(tree->value, min(minimum(tree->right), minimum(tree->left)));
}

int delete(BNode *tree, float target) {
    if (target != tree->value) {
        if (tree->left == NULL && tree->right == NULL)
            return -1;
        else if (target < tree->value)
            delete(tree->left, target);
        else if (target > tree->value)
            delete(tree->right, target);
    }
    else if (tree->left != NULL && tree->right != NULL) {
        float num = minimum(tree->right);
        delete(tree, num);
        tree->value = num;
    } else if (tree->parent != NULL) {
        if (tree->right == NULL && tree->left == NULL) {
            if (tree->parent->right == tree)
                tree->parent->right = NULL;
            else
                tree->parent->left = NULL;
            free(tree);
        } else if (tree->right == NULL) {
            tree->left->parent = tree->parent;
            if (tree->parent->right == tree)
                tree->parent->right = tree->left;
            else
                tree->parent->left = tree->left;
        } else if (tree->left == NULL) {
            tree->right->parent = tree->parent;
            if (tree->parent->right == tree)
                tree->parent->right = tree->right;
            else
                tree->parent->left = tree->right;
        }
    } else {
        if (tree->right == NULL && tree->left == NULL)
            return 0;
        else if (tree->right == NULL) {
            tree->value = tree->left->value;
            tree->right = tree->left->right;
            tree->left = tree->left->left;
        } else {
            tree->value = tree->right->value;
            tree->left = tree->right->left;
            tree->right = tree->right->right;
        }
    }
    return 1;
}

int is_btree(BNode *tree) {
    if ((tree->left != NULL && tree->right == NULL) || (tree->left == NULL && tree->right != NULL))
        return 0;
    else if (tree->left == NULL && tree->right == NULL)
        return 1;
    else
        return is_btree(tree->left) && is_btree(tree->right);
}

int main() {
    char chr[15];
    BNode *node = NULL;
    printf(" ");
    while (1) {
        printf("tree> ");
        scanf("%s", chr);
        if (!strcmp(chr, "check")) {
            if (node == NULL || !is_btree(node))
                printf("NO\n\n ");
            else
                printf("YES\n\n ");
            printf(" ");
        }
        if (!strcmp(chr, "ins")) {
            float data;
            scanf("%f", &data);
            if (node == NULL) {
                node = new_node(data);
            } else {
                insert(node, data);
            }
            printf("OK\n\n ");
        }
        if (!strcmp(chr, "del")) {
            float data;
            scanf("%f", &data);
            if (node == NULL) {
                printf("ELEMENT NOT EXIST\n\n ");
            } else {
                int state = delete(node, data);
                if (!state) node = NULL;
                if (state == -1) printf("ELEMENT NOT EXIST\n\n ");
                else printf("OK\n\n ");
            }
        }
        if (!strcmp(chr, "show")) {
            if (node != NULL) {
                visual(node, 0, 1, "fr");
                printf("\n ");
            } else printf("NULL\n\n ");

        }
        if (!strcmp(chr, "exit")) return 0;
        if (!strcmp(chr, "help")) {
            printf("ins <number> : insert element to tree\n");
            printf(" show : show tree in console\n");
            printf(" del <number> : delete element from tree\n");
            printf(" clear : destroy tree\n");
            printf(" check : check tree for 'B-tree' condition\n");
            printf("exit : complete the work\n\n ");
        }
        if (!strcmp(chr, "clear")) {
            while (!(node->right == NULL && node->left == NULL))
                delete(node, node->value);
            node = NULL;
            printf("OK\n\n ");
        }
    }
}
