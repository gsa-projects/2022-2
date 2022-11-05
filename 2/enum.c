#include <stdio.h>

enum days { SUN, MON, TUE, WED, THU, FRI, SAT };

int main() {
    int a = (1, 2) * (3, 5, 7);
    printf("%d", a);

    return 0;
}