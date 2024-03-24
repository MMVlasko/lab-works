#include <stdio.h>
#include "tools.h"

int main() {
    List *list = new_list();
    for (int i = 0; i < 10000; ++i) {
        append(i, list);
        insert_after(i, 1, list);
    }
    print_list(list);
    return 0;
}