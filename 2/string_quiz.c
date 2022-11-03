#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

#define p3

#if defined(p1)
#define SIZE 100
void shift_str(char *s, int len)
{
    char temp = *s;
    for (int i = 0; i < len; i++)
    {
        *(s + i) = *(s + i + 1);
    }
    s[len - 1] = temp;
}
int main()
{
    char text[SIZE];
    scanf("%s", text);
    int shift;
    scanf("%d", &shift);

    while (shift--)
    {
        shift_str(text, strlen(text));
    }

    printf("%s", text);
}
#endif

#if defined(p1_js)
void shift_str(char *s, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        char temp = *s;
        *s = *(s + 1);
        *(s + 1) = temp;
        s++;
    }
}

int main()
{
    char str[100] = "";
    int x;

    scanf("%s", str);
    scanf("%d", &x);

    for (int i = 0; i < x; i++)
    {
        shift_str(str, strlen(str));
    }
    printf("%s\n", str);
}
#endif

#if defined(p2)
#define SIZE 22
int main() {
    char text[SIZE] = "GwangjuScienceAcademy";

    for (int i = 0; i < 100; i++) {
        system("cls");
        for (int j = 0; j < SIZE; j++)
            printf("%c", text[(i + j) % SIZE]);
        Sleep(50);
    }

    return 0;
}
#endif

#if defined(p3)
int main()
{
    char text[100];
    printf("enter string: ");
    scanf("%s", text);

    for (int i = 0; i < 100; i++) {
        system("cls");
        for (int j = 0; j < strlen(text); j++)
            printf("%c", text[(i + j) % strlen(text)]);
        Sleep(50);
    }

    return 0;
}
#endif

#if defined(p3_js)
#define WIDTH 30
int main()
{
    char str[4] = "abcde";
    // char str[WIDTH + 1] = "";
    // int len;
    // printf("회전할 문자열 입력: ");
    // gets_s(str, WIDTH);
    // len = strlen(str);
    // for (int i = len; i < WIDTH; i++)
    //     str[i] = ' ';
    // for (int i = 0; i < 200; i++)
    // {
    //     system("cls");
    //     for (int j = 0; j < WIDTH; j++)
    //         printf("%c", str[(j + i) % WIDTH]);
    //     Sleep(100);
    // }
    return 0;
}
#endif

#if defined(p4)
#define WIDTH 40
#define HEIGHT 10
int main()
{
    char text[100];
    printf("enter string: ");
    scanf("%s", text);

    for (int i = strlen(text); i < WIDTH; i++)
        text[i] = ' ';

    for (int i = 0; i < 100; i++)
    {
        system("cls");
        for (int j = 0; j < 2 * HEIGHT; j += 2)
        {
            for (int k = 0; k < WIDTH; k++)
            {
                printf("%c", text[(i + j + k) % WIDTH]);
            }
            printf("\n");
        }
        Sleep(10);
    }

    return 0;
}
#endif

#if defined(p4_js)
#endif

#if defined(p5)
int main()
{
    int t;
    scanf("%d", &t);

    int acc = 0;
    while (t--)
    {
        char text[100];
        scanf("%s", text);

        for (int i = 0; i < strlen(text) - 1; i++)
        {
            if (text[i] == text[i + 1])
            {
                acc++;
                break;
            }
        }
    }

    printf("%d\n", acc);
}
#endif