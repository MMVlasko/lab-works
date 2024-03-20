//#include <string.h>
//#include <stdio.h>
//#include "lib.h"
//
//int main(void) {
//    char chr[15];
//    BNode *node = NULL;
//    printf("Type 'help' to take info\n\n ");
//    while (1) {
//        printf("tree> ");
//        scanf("%s", chr);
//        if (!strcmp(chr, "check")) {
//            if (node == NULL || !is_btree(node))
//                printf(" NO\n\n");
//            else
//                printf(" YES\n\n");
//            printf(" ");
//        }
//        if (!strcmp(chr, "ins")) {
//            float data;
//            scanf("%f", &data);
//            if (node == NULL) {
//                node = new_node(data);
//            } else {
//                insert(node, data);
//            }
//            printf(" OK\n\n ");
//        }
//        if (!strcmp(chr, "del")) {
//            float data;
//            scanf("%f", &data);
//            if (node == NULL) {
//                printf(" ELEMENT NOT EXIST\n\n ");
//            } else {
//                int state = delete(node, data);
//                if (!state) node = NULL;
//                if (state == -1) printf(" ELEMENT NOT EXIST\n\n ");
//                else printf(" OK\n\n ");
//            }
//        }
//        if (!strcmp(chr, "show")) {
//            if (node != NULL) {
//                show(node, 0, 1, "fr");
//                printf("\n ");
//            } else printf(" EMPTY\n\n ");
//
//        }
//        if (!strcmp(chr, "exit")) return 0;
//        if (!strcmp(chr, "help")) {
//            printf(" ins <number> : insert element to tree\n");
//            printf(" show : show tree in console\n");
//            printf(" del <number> : delete element from tree\n");
//            printf(" clear : destroy tree\n");
//            printf(" check : check tree for 'B-tree' condition\n");
//            printf(" exit : complete the work\n\n ");
//        }
//        if (!strcmp(chr, "clear")) {
//            if (node != NULL) {
//                while (!(node->right == NULL && node->left == NULL))
//                    delete(node, node->value);
//                node = NULL;
//                printf(" OK\n\n ");
//            } else printf(" ALREADY CLEARED\n\n ");
//        }
//    }
//}
