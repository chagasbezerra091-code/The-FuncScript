// stdbool.c - // stdbool.c - Compatível com C
#include <stdio.h>
#include "stdbool.h"

int main() {
    bool flag = true;
    if (flag) {
        printf("Flag é true!\n");
    } else {
        printf("Flag é false!\n");
    }
    return 0;
}
