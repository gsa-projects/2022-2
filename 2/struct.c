#include <stdio.h>
#include <string.h>
#include <math.h>

#if defined(struct)
struct point {
	int x;
	int y;
};

int main() {
	struct point p1, p2;
	
	printf("왼쪽 상단의 좌표를 입력하시오: ");
	scanf("%d %d", &p1.x, &p1.y);

	printf("오른쪽 하단의 좌표를 입력하시오: ");
	scanf("%d %d", &p2.x, &p2.y);

	printf("면적은 %d이고 둘레는 %d입니다.\n", abs(p1.x - p2.x) * abs(p1.y - p2.y), 2 * (abs(p1.x - p2.x) + abs(p1.y - p2.y)));

	return 0;
}
#endif

#if defined(structlist)
#define SIZE 3

struct student {
    int number;
    char name[20];
    double grade;
};

int main() {
    struct student list[SIZE];

    for (int i = 0; i < SIZE; i++) {
        printf("학번을 입력하세요: ");
        scanf("%d", &list[i].number);

        printf("이름을 입력하세요: ");
        scanf("%s", &list[i].name);

        printf("학점을 입력하세요: ");
        scanf("%lf", &list[i].grade);
    }
    
    for (int i = 0; i < SIZE; i++) {
        printf("학번: %d, 이름: %s, 학점: %lf\n", list[i].number, list[i].name, list[i].grade);
    }
}
#endif

#if defined(structpointer)
struct student {
    int number;
    char name[20];
    double grade;
};

int main() {
    struct student s = {20070001, "hgd", 4.3};
    struct student *p;
    p = &s;

    printf("%d, %s, %lf", p->number, p->name, p->grade);
}
#endif

#if defined(vectorp)
struct vector2d {
    double i;
    double j;
};

struct vector2d add(struct vector2d v1, struct vector2d v2) {
    struct vector2d vr = { v1.i + v2.i, v1.j + v2.j };
    return vr;
}

double dot(struct vector2d v1, struct vector2d v2) {
    return v1.i * v2.i + v1.j * v2.j;
}

int main() {
    struct vector2d v1, v2;
    
    printf("v1: ");
    scanf("%lf %lf", &v1.i, &v1.j);

    printf("v2: ");
    scanf("%lf %lf", &v2.i, &v2.j);

    struct vector2d vs = add(v1, v2);

    printf("v1(%lf, %lf) + v2(%lf, %lf) = vs(%lf, %lf)", v1.i, v1.j, v2.i, v2.j, vs.i, vs.j);
}
#endif

#if defined(structp)
typedef struct human {
    char name[10];
    int age;
    float power;
} human;

int main() {
    human ho[3] = {
        { "Gwangju", 22, 8.2 },
        { "Science", 28, 9.3 },
        { "Academy", 21, 7.6 }
    };

    human temp;
    
    temp = ho[0];
    ho[0] = ho[2];
    ho[2] = temp;

    for (int k = 0; k < 3; k++)
        printf("%d: %s %d %.1f\n", k, ho[k].name, ho[k].age, ho[k].power);

    return 0;
}
#endif

#if defined(linked_list)
typedef struct human {
    char name[10];
    struct human *next;
} human;

int main() {
    human h1 = { "Gwangju" }, h2 = { "Science" }, h3 = { "Academy" };
    human *sp;

    h1.next = &h2;
    h2.next = &h3;
    h3.next = NULL;

    sp = &h1;
    printf("%s\n", sp->name);
    printf("%s\n", sp->next->name);
    printf("%s\n", sp->next->next->name);

    return 0;
}
#endif

#define pointp
#if defined(pointp)
typedef struct point {
    int x;
    int y;
} point;

point translate(point p1, point p2) {
    point ret = { p1.x + p2.x, p1.y + p2.y };
    return ret;
}

int main() {
    point p1 = {2, 3};
    point p2 = {10, 10};
    point p3 = translate(p1, p2);

    printf("(%d, %d)\n", p3.x, p3.y);
}
#endif