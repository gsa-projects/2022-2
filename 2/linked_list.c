#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define hwiju

#ifdef recursive
typedef struct _node {
    char name[10];
    int age;
    int height;
    struct _node* next;
} node;

void insert_last(node** head, node data) {
    if ((*head) != NULL)
        return insert_last(&((*head)->next), data);
    else {
        (*head) = (node*)malloc(sizeof(node));

        *head = &data;
        (*head)->next = NULL;
    }
}

void print_list(node* head) {
    if (head != NULL) {
        printf("%s, %d, %d\n", head->name, head->age, head->height);
        return print_list(head->next);
    }
}

int main() {
    node* head = NULL;
    node data;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", data.name, &(data.age), &(data.height));
        insert_last(&head, data);
    }
    print_list(head);

    return 0;
}
#endif

#ifdef junsun
typedef struct ListNode {
    char name[10];
    int age;
    int height;
    struct ListNode* next;
} ListNode;

void print_list(ListNode* node) {
    ListNode* tmp = node;
    while (tmp != NULL) {
        printf("%s: %d years old, %d cm tall\n", tmp->name, tmp->age, tmp->height);
        tmp = tmp->next;
    }
}

void insert_last(ListNode** node, ListNode data) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    if (p == NULL) return;

    *p = data;
    p->next = NULL;

    if (*node == NULL) {
        *node = p;
    }
    else {
        ListNode* tmp = *node;
        while (tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = p;
    }
}

int main() {
    ListNode* head = NULL;

    ListNode data;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", data.name, &(data.age), &(data.height));
        insert_last(&head, data);
    }
    print_list(head);

    return 0;
}
#endif

#ifdef hwiju
typedef struct node {
    char name[10];
    int age;
    int height;
    struct node* p_next;
}ListNode;

void insert_last(ListNode** pp_head, ListNode value);
void print_list(ListNode* p_head);

int main()
{
    ListNode* head = NULL;
    ListNode data;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", data.name, &(data.age), &(data.height));
        insert_last(&head, data);
    }
    print_list(head);
}

void print_list(ListNode* p_head)
{
    ListNode* p;
    p = p_head;
    while (p != NULL)
    {
        printf("이름 : %s, 나이 :%d, 키 : %d\n", p->name, p->age, p->height);
        p = p->p_next;
    }
}


void insert_last(ListNode** pp_head, ListNode value)
{
    ListNode* p = NULL;

    if (*pp_head == NULL)
    {
        *pp_head = (ListNode*)malloc(sizeof(ListNode));
        p = *pp_head;
    }
    else {
        p->p_next = (ListNode*)malloc(sizeof(ListNode));
        p = p->p_next;
    }
    strcpy(p->name, value.name);
    p->age = value.age;
    p->height = value.height;
    p->p_next = NULL;
}
#endif

#ifdef caninsert
typedef struct _node {
    int data;
    struct _node* next;
} node;

void print(node* head) {
    node* tmp = head;
    while (tmp != NULL) {
        printf("->%d", tmp->data);
        tmp = tmp->next;
    }
}

void insert(node** head, node data) {
    node* p = (node*)malloc(sizeof(node));
    if (p == NULL) return;

    *p = data;
    p->next = NULL;

    if (*head == NULL) {
        *head = p;
    }
    else {
        node* tmp = *head;

        while (tmp->next != NULL && tmp->next->data < p->data) {
            tmp = tmp->next;
        }

        if (p->data < (*head)->data) {
            p->next = *head;
            *head = p;
        }
        else if (tmp->next != NULL) {
            p->next = tmp->next;
            tmp->next = p;
        }
        else {
            tmp->next = p;
        }
    }
}

int main() {
    node* head = NULL;
    int arr[] = { 10, 14, 7, 9, 3, 0, 11, 2, 6, 8, 13, 12, 1, 4, 5 };

    for (int i = 0; i < 15; ++i) {
        node data = { arr[i] };
        insert(&head, data);
    }
    print(head);

    return 0;
}
#endif