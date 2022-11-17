#include <stdio.h>

void pprint(char* x) {
    printf("%c | %p\n", *x, x);
}

void address() {
    int arr[2][2] = { 1, 2, 3, 4 };

    printf("arr       : %p\n", arr);
    printf("&arr      : %p\n", &arr);
    printf("&arr[0]   : %p\n", &arr[0]);
    printf("&arr[0][0]: %p\n", &arr[0][0]);
    printf("&arr[0][1]: %p\n", &arr[0][1]);
    printf("&arr[1][0]: %p\n", &arr[1][0]);
    printf("&arr[0][2]: %p\n", &arr[0][2]);
    printf("&arr[1][1]: %p\n", &arr[1][1]);
    printf("&arr[0][3]: %p\n", &arr[0][3]);
}

void pointer_practice1() {
    int a = 3;
    int* pa;
    pa = &a;

    *pa = 4;

    pprint(&a);
    pprint(pa);
}

void pointer_practice2() {
    int arr[4] = { 1, 2, 3, 4 };
    int* parr;
    parr = arr;

    pprint(arr);
    pprint(parr);
}

void get_sum() {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* parr;
    parr = &arr[0];

    int sum = 0;
    while (parr - &arr[0] < 4) {
        sum += (*parr);
        parr++;
    }

    printf("%d\n", sum);
}

void pointer_add() {
    /*
    * 주솟값은 16진수, 16진수 저장에는 4비트가 필요하고 컴퓨터가 64비트(=8바이트)이므로 16자리의 주솟값이 나옴
    * 아무튼 모든 타입의 포인터 변수는 주솟값을 저장하므로 8바이트 공간을 가짐
    */
    char* pc;
    int* pi;
    double* pd;

    pc = 10000;
    pi = 10000;
    pd = 10000;

    printf("%d, %d, %d, %d\n", sizeof(int), sizeof(char*), sizeof(int*), sizeof(double*));
    printf("%p\n", pc);
    printf("%d %d %d %d\n", pc, pc + 1, pc + 2, pc - 1);
    printf("%d %d %d %d\n", pi, pi + 1, pi + 2, pi - 1);
    printf("%d %d %d\n", pd, pd + 1, pd + 2);
}

void pointer_constant() {
    int a, b, c;

    //  (const int*) -> 값(포인터 역참조, *) 변경 금지
    const int* pa = &a;
    //  *pa = 3;
    pa = &b;

    //  (const ptr) -> 주소(포인터 변수 값, &) 변경 금지
    int* const pb = &b;
    *pb = 3;
    //  pb = &a;

    //  (const int* const ptr) -> 값과 주소(*, &) 변경 금지
    const int* const pc = &c;
    //  *pc = 3;
    //  pc = &c;
}

void sub(int* b, int n) {
    b[0] = 4;
    b[1] = 5;
    b[2] = 6;
}

//void sub(int b[], int n) {
//    b[0] = 4;
//    b[1] = 5;
//    b[2] = 6;
//}

void pointer_and_array() {
    int a[3] = { 1, 2, 3 };

    printf("%d %d %d\n", a[0], a[1], a[2]);
    sub(a, 3);
    printf("%d %d %d\n", a[0], a[1], a[2]);
}

#define double_pointer
#if defined(double_pointer)
void dp(char **p) {
    *p = "hello";
}

int main() {
    char *q;
    dp(&q);

    printf("%s\n", *q);

    return 0;
}
#endif