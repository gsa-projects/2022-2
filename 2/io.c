#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void io() {
    int ch;

    while (1) {
        ch = getchar();
        if (ch == 'q') break;
        putchar(ch);
    }
}

void io_dis() {
    int ch;

    while (1) {
        ch = _getch();
        if (ch == 'q') break;
        _putch(ch);
    }
}

void sing() {
    char title[100];
    char lyric[100];

    printf("enter title: ");
    gets_s(title, 100);
    printf("enter lyric: ");
    gets_s(lyric, 100);

    puts(title);
    puts(lyric);
}

int OX()
{
    int count;
    scanf("%d", &count);

    while (count--)
    {
        int sum = 0, acc = 1;
        char mark[30];
        scanf("%s", mark);

        for (int i = 0; i < strlen(mark); ++i)
        {
            if (mark[i] == 'O') sum += acc++;
            else if (mark[i] == 'X') acc = 1;
        }

        printf("%d\n", sum);
    }

    return 0;
}

int dict() {
    char s1[100], s2[100];

    printf("첫번째 단어를 입력하세요: ");
    scanf("%s", s1);
    printf("두번째 단어를 입력하세요: ");
    scanf("%s", s2);

    int cmp = strcmp(s1, s2);
    printf("%s가 %s%s", s1, s2, cmp == 0 ? "와 같습니다." : cmp == 1 ? "보다 뒤에 있습니다." : "보다 앞에 있습니다.");

    return 0;
}

int count() {
    char str[] = "gsa! gsa..gsa";

    int wc = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if ((i == 0 || !isalpha(str[i - 1])) && isalpha(str[i])) wc++;
    }

    printf("%d\n", wc);

    return 0;
}

int buffer() {
    char a[100];
    scanf("%s", a);
    printf("\n%s\n", a);
    scanf("%s", a);
    printf("\n%s\n", a);

    return 0;
}

int main() {

}