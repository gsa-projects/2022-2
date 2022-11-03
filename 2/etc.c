#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>

#define ex

#if defined(ex)
int main() {
    char str[] = "helloworld";

    printf("%d\n", strlen(str));

    return 0;
}
#endif

#if defined(binary_search)
#define SIZE 10
int search(int arr[], int size, int key);

int main()
{
    char str[] = "hello world";
    printf(str);

    return 0;
}

int search(int arr[], int size, int key)
{
    int start = 0, end = size - 1;
    int middle;

    while (start <= end)
    {
        middle = (start + end) / 2;

        printf("[%d %d]\n", start, end);

        if (arr[middle] < key)
        {
            start = middle + 1;
        }
        else if (arr[middle] > key)
        {
            end = middle - 1;
        }
        else
        {
            return arr[middle];
        }
    }

    return -1;
}
#endif

#if defined(shift)
void shift_str(char *p, int len);
int main()
{
    char str[30] = "";
    int input;
    int len;
    scanf("%s", str);
    scanf("%d", &input);
    for (int i = 0; i < input; i++)
    {
        shift_str(str, strlen(str));
    }
    printf("%s", str);
    return 0;
}

void shift_str(char p[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        char temp = *p;
        *p = *(p + 1);
        *(p + 1) = temp;
        p++;
    }
}
#endif