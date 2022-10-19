#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

int main() {
    int a[3] = { 1, 2, 3 };
    int *p = a + 1;
    int *q = a + 2;
    
    int *temp = p;
    p = q;
    q = temp;

    printf("%d %d\n", *p, *q);
}