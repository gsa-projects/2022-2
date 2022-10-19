#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

#define pop_quiz

#if defined(strcat_and_strcpy)
int main() {
    char a[100] = "Hello";
    char b[100] = "World";

    strcpy(a + strlen(a), b); // strcat(a, b)와 완전 동일
    printf("%s", a);
}
#endif

#if defined(remove_space)
void removeDuplicateSpace(char* str) {
    char temp[100] = "";
    int temp_idx = 0;
    int waiting = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i]) != 0) { // 알파벳이면
            temp[temp_idx++] = str[i]; // temp에 알파벳 넣고
        }
        else { // 알파벳 아니면
            if (str[i] == ' ') { // 알파벳 아닌 것들 중 공백이면
                if (waiting == 0) temp[temp_idx++] = str[i];    // 연속된 공백이 아니면 temp에 공백 넣음

                if (str[i + 1] == ' ') waiting = 1; // 다음 문자도 공백이면 연속된 공백이니까 waiting = 1
                else waiting = 0;
            }
        }
    }

    strcpy(str, temp);
}

int main() {
    char str[] = "Hello  World   Example String       Variable";
    removeDuplicateSpace(str);

    printf("%s", str);
    return 0;
}
#endif

#if defined(pop_quiz)
void swap(int* x, int* y);

int main(void)

{
    int a = 100, b = 200;
    //printf("%d %d\n", &a, &b);

    //swap(&a, &b);

    printf("a=%d b=%16d\n", a, b); 

    //printf("a = %d b = % d\n", &a, &b);

    return 0;

}



void swap(int* x, int* y)

{

    int tmp;

    tmp = *x;

    *x = *y;

    *y = tmp;

    *x = *x + 1;

    *y = *y + 2;

    printf("x = %d y = %d\n", *x, *y);

}
#endif

// int main() {
//     //difference_of_pointerstring_arraystring();
//     //init_string();
//     //loop_string_with_variable();
//     //loop_string_with_pointer();
//     //string_copy_without();
//     //string_copy_with();
//     //string_length_without();
//     //string_length_with();
//     //pointerandarray();
//     //neonboard1();
//     str_p1();

//     return 0;
// }

void difference_of_pointerstring_arraystring() {
    char school[] = "Gwangju Science Academy for the gifted";
    /*1000 G
    1001 w
    1002 a
    ...*/

    char* school2 = "Gwangju Science Academy for the gifted";
    /*1000 213890

    213890 G
    213891 w
    213892 a
    213893 n
    ...*/

    school[0] = 'K';

    printf("%s\n", school);
}

void init_string() {
    char str1[4] = { 'a','b','c','\0' };
    char str2[4] = "abc";
    //char str[4] = "abcdef"; << 오류남
    char str3[6] = "ab"; // << [a][b][\0][\0][\0][\0]
    char str4[4] = ""; // << [\0][\0][\0][\0]
    char str5[5]; // << [?][?][?][?]

    for (int i = 0; i < 6; i++)
        printf("[%c]", str3[i]);
}

void loop_string_with_variable() {
    char str[] = "this is example string";

    int i = 0;
    while (str[i] != '\0') {
        printf("[%c]", str[i]);
        i++;
    }
}

void loop_string_with_pointer() {
    char str[] = "this is example string";

    char* p;
    p = str;

    while (*p != '\0') {
        printf("[%c]", *p);
        p++;
    }
}

void string_copy_without() {
    char str[] = "hello world";
    char dst[100];
    int i;

    printf("original: %s\n", str);

    for (i = 0; str[i] != '\0'; i++)
        dst[i] = str[i];
    dst[i] = '\0';

    printf("copied:   %s\n", dst);
}

void string_copy_with() {
    char str[] = "hello world";
    char dst[100];

    printf("original: %s\n", str);

    strcpy(dst, str);

    printf("copied:   %s\n", dst);
}

void string_length_without() {
    char str[] = "hello world frineds";
    int i = 0;

    //while ()
}

void string_length_with() {
    //strlen(string) 쓰세요~
}

int pointerandarray() {
    /*char s1[6] = "Hello";
    char* s = "World";
    char* s2 = (char*)malloc(sizeof(char) * 10);
    char s3[10];
    char* s4 = " ";
    strcat(s2, s);

    printf("%s", s1);*/

    char* s1 = "Science";
    char* s2 = (char*)malloc(sizeof(char) * 20);
    strcpy(s2, "Gwangju");
    strcat(s2, s1);
    printf("%s", s2);
    free(s2);

    // strcpy, strcat으로도 값 변경은 char[]만 됨, char*는 읽기만 됨

    return 0;
}

#define SIZE 22

int neonboard1() {
    char text[SIZE] = "GwangjuScienceAcademy";

    for (int i = 0; i < 100; ++i) {
        system("cls");
        for (int j = 0; j < SIZE; ++j) {
            printf("%c", text[(i + j) % SIZE]);
        }
        Sleep(50);
    }
}