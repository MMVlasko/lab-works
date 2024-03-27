#include <stdio.h>
#include "tools.h"

int main() {
    List *list = new_list();
    append(0, list);
    append(-11, list);
    for (int i = 30; i > 0; i--) {
        append(i, list);
    }
    append(-1, list);
    print_list(list);
    sort(list, list->head, NULL, list->size);
    print_list(list);
    return 0;
}