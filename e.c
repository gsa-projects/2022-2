#include <stdio.h>
#include <string.h>
#define SIZE 3 // 회사 개수

int main() {
    int num[SIZE] = { 40000, 30000, 70000 }; // 각 회사 금액
    char str[SIZE][100] = { "coin1", "coin2", "coin3" }; // 각 회사 이릅

    char input[100]; // 100 = 회사명 최대 길이
    scanf("%s", input);
    
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(input, str[i]) == 0) {
            int price;
            scanf("%d", &price); // 금액 입력

            num[i] = price;
        }
    }
    
    for (int i = 0; i < SIZE; i++) {
        printf("%s: %d\n", str[i], num[i]);
    }

    return 0;
}