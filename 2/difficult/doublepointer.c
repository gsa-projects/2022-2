#include <stdio.h>
#include <stdlib.h>
#define size

#ifdef dpointer
int main() {
    int i = 80;
    int *p = &i;
    int **dp = &p;
    
    **dp = 90;
    // *p = 100;
    printf("%d %d %d", i, *p, **dp); // 90 90 90
}
#endif 

#ifdef darraypointer
int main() {
    // m 주소 1000
    int m[2][3] = { {1, 2, 3}, {4, 5, 6} };

    printf("%u\n", m);  // 1000
    printf("%u %u\n", **m, *m); // 1, 1000
    printf("%u %u\n", *m[0], *m[1]);    // 1, 4
}
#endif

#ifdef dstringpointer
int main() {
    char *a[] = { "abc", "def", "ghi", "jkl", "mno" };
    char **pa;
    pa = a;

    printf("%c %c %c\n", **pa, **pa + 1, **pa + 2);    // a b c, 아스키로 더한거
    printf("%c %c %c\n", **pa, *(*pa + 1), *(*pa + 2));    // a b c, "abc"의 인덱스로 한거
    printf("%s %s %s\n", *pa, *pa + 1, *pa + 2);    // abc bc c
    printf("%s %s %s\n", *pa, *(pa + 1), *(pa + 2));    // abc def ghi
    printf("%s %s %s\n", a[0], a[1], a[2]); // abc def ghi
    printf("%s %s %s\n", a[0] + 1, a[1] + 1, a[2] + 1); // bc ef hi
}
#endif

#ifdef ap
int main() {
    // 배열포인터
    char (*data2)[3] = { "hello", "world", "coding" };
    // 배열(의 첫 인덱스)을 주소로 가지는 포인터
    // data2 -> [hello, world, coding]

    for (int i = 0; i < 3; i++)
        printf("%d : %s: %p\n", i, data2[i], &data2[i]);

    return 0;
}
#endif

#ifdef pa
int main() {
    // 포인터배열
    char *data1[3] = { "hello", "world", "coding" };
    // 각 원소가 각 원소를 가리키는 포인터들을 가지는 배열
    // data1: [&x1,     &x2,     &x3]
    //        -> hello -> world -> coding

    for (int i = 0; i < 3; i++)
        printf("%d : %s: %p\n", i, data1[i], &data1[i]);

    return 0;
}
#endif

#ifdef dap
int main() {
    int x[2][2] = { {1, 2}, {3, 4} }; // 100 104 108 112
    int *px[2]; // 1000 1008
    int **ppx; // 10000

    px[0] = x[0];
    px[1] = x[1];
    ppx = &px;

    // px->1000 : { ->100, ->108 }
    // ppx->10000 : 1000

    printf("%u %u %u\n", x, px, ppx);

    printf("%u %u %u\n", px[0], px[1], ppx);    // 100 108 1000
    printf("%u %u %u\n", px[0]+1, px[1]+1, ppx+1);  // 104 112 1008
    printf("%u %u\n", *(++px[0]), *(++ppx));    // *(104) = 2, *(1008) = 108

    return 0;
}
#endif

#ifdef ex
typedef struct node {
	int data;
    struct node* next;
} node;

void insert(node** head, node to_add)
{
	node* p = (node*)malloc(sizeof(node));
    if (p == NULL) return;
    *p = to_add;
    p->next = NULL;
    
    if (*head == NULL) 	// head에 노드가 없는 경우
    {	
    	*head = p;
    }
    else				// head에 노드가 1개 이상 있는 경우
    {	
    	node* tmp = *head;
	    while (tmp->next != NULL)
    		tmp = tmp->next;
    
    	tmp->next = p;
    }
}

void print(node* head)
{
	for (node* tmp = head; tmp != NULL; tmp = tmp->next)
    	printf("%d\n", tmp->data);
}

int main()
{
	node* head = NULL;
    node to_add;
    
    to_add.data = 3;
    insert(&head, to_add);
    
    to_add.data = 4;
    insert(&head, to_add);
    
    to_add.data = 5;
    insert(&head, to_add);
    
    print(head);
}
#endif

#ifdef size
int main() {
    char* strs[4] = {
        'newjeans',
        3,
        "itzy",
        [4,5,6]
    };

    printf("%d %d\n", sizeof(strs), sizeof(strs[0]));

    return 0;
}
#endif