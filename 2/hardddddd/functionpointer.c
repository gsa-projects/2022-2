#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define easy

#ifdef easy
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }
int div(int x, int y) { return x / y; }

int main() {
    int (*pf[4])(int, int) = { add, sub, mul, div };
    

    return 0;
}
#endif