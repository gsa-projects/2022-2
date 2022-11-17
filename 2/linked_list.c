#include <stdio.h>
#include <stdlib.h>
#define make_node() (node*)malloc(sizeof(node))

typedef struct _node {
    int data;
    struct _node *next;
} node;

void append(node** head, int d) {
    // 맨 마지막 node로 간 뒤
    // node.data = d;

    node* tmp = (*head)->next;

    while (tmp != NULL)
        tmp = tmp->next;
    
    tmp->data = d;
}

void print(node** head) {

}

int main() {
    node* head = make_node();

    int input;
    while (1) {
        scanf("%d", &input);

        switch (input) {
            case 1:
                int d;
                scanf("%d", &d);
                append(&head, d);
            case 2:
                print(&head);
            case 3:
                return 0;
        }
    }

    return 0;
}