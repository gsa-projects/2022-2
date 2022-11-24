#include <stdio.h>

int main() {
    char *data1[3] = { "hello", "world", "coding" };
    // 각 원소가 각 원소를 가리키는 포인터들을 가지는 배열
    // data1: [&x1,     &x2,     &x3]
    //        -> hello -> world -> coding

    for (int i = 0; i < 3; i++)
    {
        printf("%d : %s: %p\n", i, data1[i], &data1[i]);
    }
    
    char (*data2)[3] = { "hello", "world", "coding" };
    // 배열(의 첫 인덱스)을 주소로 가지는 포인터
    // data2 -> [hello, world, coding]

    for (int i = 0; i < 3; i++)
    {
        printf("%d : %s: %p\n", i, data2[i], &data2[i]);
    }

    return 0;
}