#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int id;
    char name[10];
    float score;
    struct student* next;
} STUDENT;

void insert_list(STUDENT** head, STUDENT data) {
    STUDENT* p = (STUDENT*)malloc(sizeof(STUDENT));
    
    if (p == NULL) return;
    *p = data;
    p->next = NULL;

    if (*head == NULL) {
        *head = p;
    }
    else {
        STUDENT* tmp = *head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        
        tmp->next = p;
    }
}

int main() {
    printf("** 학점 입력 프로그램 **\n");
    printf("학생 수를 입력하세요 : ");
    
    int n;
    scanf("%d", &n);

    printf("1. 학번 2. 이름 3. 학점 순으로 입력\n");

    STUDENT data;
    STUDENT *head = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d %s %f", &(data.id), data.name, &(data.score));
        insert_list(&head, data);
    }

    STUDENT *max = head;
    for (STUDENT *tmp = head; tmp != NULL; tmp = tmp->next) {
        if (max->score < tmp->score) max = tmp;
    }

    printf("학점이 가장 높은 학생은 %s입니다.", max->name);

    return 0;
}