#include <stdio.h>
#include "tools.h"

int main() {
    List *list = new_list();
    append(2, list);
    for (int i = 0; i < 10; ++i) {
        append(1, list);
    }
    print_list(list);
    delete(2, list);
    print_list(list);
//    print_list(list);
//    delete(2, list);
//    print_list(list);
//    delete(2, list);
//    print_list(list);
    return 0;
}