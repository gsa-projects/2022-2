#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define p5

#ifdef p1
int main() {
    char gsa[3][8] = { "Gwangju", "Science", "Academy" };
    char** pp_gsa[3];
    char** p_gsa;

    pp_gsa[0] = gsa[0];
    pp_gsa[1] = gsa[1];
    pp_gsa[2] = gsa[2];

    p_gsa = pp_gsa;

    printf("%s %s %s\n", *pp_gsa, *(pp_gsa + 1), gsa[2] + 1);
    printf("%c %c %c\n", *p_gsa[0], **(pp_gsa + 1), gsa[2][0]);

    return 0;
}
#endif

#ifdef p2
struct student {
    int number;
    char name[10];
    double grade;
};

int create() {
    struct student s;
    scanf("%d %s %lf", &s.number, s.name, &s.grade);
    return s;
}

int main() {
    struct student a[2];
    for (int i = 0; i < 2; i++)
        a[i] = create();
    for (int i = 0; i < 2; i++)
        printf("%d %s %lf\n", a[i].number, a[i].name, a[i].grade);
    return 0;
}
#endif

#ifdef p3
struct tel_number {
    char name[10];
    int age;
    char tel[50];
    char nation[20];
};

int main() {
    struct tel_number member[5] = {
        {"g", 23, "010-9584-0109", "대한민국"},
        {"h", 22, "010-4174-9955", "미국"},
        {"h2", 17, "010-5051-0315", "대한민국"},
        {"sa", 25, "010-7154-9551", "일본"},
        {"ka", 45, "010-9668-4410", "일본"}
    };

    char name[10];
    printf("검색할 이름을 입력하시오: ");
    scanf("%s", name);

    for (int i = 0; i < 5; i++) {
        if (strcmp(member[i].name, name) == 0) {
            printf("이름: %s, 나이: %d, 번호: %s, 국적: %s",
                member[i].name, member[i].age, member[i].tel, member[i].nation);
            return 0;
        }
    }
    printf("검색에 실패했습니다.");
    return 0;
}
#endif

#ifdef p4
typedef struct MENU {
    char name[10];
    int price;
    int count;
} MENU;

void festival_sum(MENU data[]);

int main() {
    MENU data[5] = {
        {"water", 1000, 2},
        {"milk", 2000, 1},
        {"salad", 5000, 2},
        {"egg", 1700, 3},
        {"coke", 2000, 3},
    };
    festival_sum(data);

    return 0;
}

void festival_sum(MENU data[]) {
    int total = 0;

    for (int i = 0; i < 5; i++) {
        printf("%-10s%2d%7d%10d\n", data[i].name, data[i].count, data[i].price, data[i].count * data[i].price);
        total += data[i].count * data[i].price;
    }
    printf("총액:%d", total);
}
#endif

#ifdef p5
#define HEIGHT 10
#define WIDTH 8

void pixel_print(int pixel[][WIDTH]);
void to_binarization(int pixel[][WIDTH]);
void to_reverse(int pixel[][WIDTH]);

int main() {
    int pixel[HEIGHT][WIDTH] = {
        {0,0,3,195,220,3,0,0},
        {0,5,186,199,211,175,0,0},
        {7,168,188,8,9,189,183,0},
        {9,195,3,0,0,0,178,0},
        {0,8,0,0,7,189,172,5},
        {0,0,0,8,188,168,2,0},
        {0,0,8,186,170,7,0,0},
        {0,7,189,177,8,9,7,0},
        {8,175,185,214,202,189,125,8},
        {2,212,215,221,211,198,175,9} };

    printf(" ------ '2' 픽셀 원본 출력 ------\n");
    pixel_print(pixel);

    printf("\n ------ '2' 픽셀 이진화 출력 ------\n");
    to_binarization(pixel);
    pixel_print(pixel);

    printf("\n ------ '2' 픽셀 반전 출력 ------\n");
    to_reverse(pixel);
    pixel_print(pixel);
}

void pixel_print(int pixel[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%3d ", pixel[i][j]);
        }
        printf("\n");
    }
}

void to_binarization(int pixel[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixel[i][j] = (pixel[i][j] >= 5) ? 255 : 0;
        }
    }
}

void to_reverse(int pixel[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixel[i][j] = (pixel[i][j] == 255) ? 0 : 255;
        }
    }
}
#endif

#ifdef p6
#endif

#ifdef p7
#endif