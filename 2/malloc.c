#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void example_malloc() {
    char *s1 = "Hello";
    char* s2;
    s2 = (char*)malloc((strlen(s1) + 1) * sizeof(char));

    strcpy(s2, s1);
    printf("%s\n%s\n", s1, s2);

    free(s2);
}

int main() {
    

	return 0;
}