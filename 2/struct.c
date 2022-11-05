#include <stdio.h>
#include <string.h>
#include <math.h>

#define vector

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

#if defined(vector)
struct vector2d {
    double i;
    double j;
};

struct vector3d {
    double i;
    double j;
    double k;
};

struct vector2d add(struct vector2d v1, struct vector2d v2) {
    struct vector2d vr = { v1.i + v2.i, v1.j + v2.j };
    return vr;
}

double dot(struct vector2d v1, struct vector2d v2) {
    return v1.i * v2.i + v1.j * v2.j;
}
enum enom {enom='a', yeaki=53};

int main() {
    // struct vector2d v1, v2;
    
    // printf("v1: ");
    // scanf("%lf %lf", &v1.i, &v1.j);

    // printf("v2: ");
    // scanf("%lf %lf", &v2.i, &v2.j);

    // struct vector2d vs = add(v1, v2);

    // printf("v1(%lf, %lf) + v2(%lf, %lf) = vs(%lf, %lf)", v1.i, v1.j, v2.i, v2.j, vs.i, vs.j);
    printf("%c %d\n", enom, yeaki);
}
#endif