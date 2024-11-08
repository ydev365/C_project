#include <stdio.h>

int main(void)
{
    int i = 10;
    char c = 69;
    float f = 12.3;
    return 0;
}

int main(void)
{
    int i = 10;
    char c = 69;
    float f = 12.3;

    printf("i의 주소: %p\n", &i);
    printf("c의 주소: %p\n", &c);
    printf("f의 주소: %p\n", &f);

    return 0;
}

#include <stdio.h>

int main(void)
{
    int i = 10;
    double f = 12.3;
    int* pi = NULL;
    double* pf = NULL;

    pi = &i;
    pf = &f;

    printf("%p %p\n", pi, &i);
    printf("%p %p\n", pf, &f);

    return 0;
}

#include <stdio.h>

int main(void)
{
    int* pi = NULL;
    char* pc = NULL;
    double* pd = NULL;

    int num = 10;
    char val = 'A';
    double dnum = 10.5;

    pi = &num;
    pc = &val;
    pd = &dnum;

    printf("*pi = %d, num=%d \n", *pi, num);
    printf("*pc = %c, val=%c \n", *pc, val);
    printf("*pd = %lf, dnum=%lf \n", *pd, dnum);

    return 0;
}

int main(void)
{
    int i = 3000;
    int* p = NULL;

    p = &i;
    printf("p = %p\n", p);
    printf("&i = %p\n", &i);
    printf("i = %d\n", i);
    printf("*p = %d\n", *p);

    return 0;
}

int main(void)
{
    int x = 10, y = 20;
    int* p;
    p = &x;
    printf("p = %p\n", p);
    printf("*p = %u\n\n", *p);
    p = &y;
    printf("p = %p\n", p);
    printf("*p = %u\n", *p);
    return 0;
}

int main(void)
{
    int i = 10;
    int* p;
    p = &i;
    printf("i = %d\n", i);
    *p = 20;
    printf("i = %d\n", i);
    return 0;
}

int main(void)
{
    char* pc;
    int* pi;
    double* pd;

    pc = (char*)10000;
    pi = (int*)10000;
    pd = (double*)10000;

    printf("pc=%u, pc+1=%u, pc+2=%u\n", pc, pc + 1, pc + 2);
    printf("pi=%u, pi+1=%u, pi+2=%u\n", pi, pi + 1, pi + 2);
    printf("pd=%u, pd+1=%u, pd+2=%u\n", pd, pd + 1, pd + 2);

    return 0;
}

int main(void)
{
    int i = 10;
    int* pi = &i;

    printf("i = %d, pi = %p\n", i, pi);

    (*pi)++;
    printf("i = %d, pi = %p\n", i, pi);

    *pi++;
    printf("i = %d, pi = %p\n", i, pi);

    return 0;
}

int main(void)
{
    int data = 0x0A0B0C0D;
    char* pc;
    int i;
    pc = (char*)&data;
    for (i = 0; i < 4; i++) {
        printf("*(pc + %d) = %02X \n", i, *(pc + i));
    }
    return 0;
}



void swap(int x, int y);

int main(void)
{
    int a = 100, b = 200;
    printf("a=%d b=%d\n", a, b);

    swap(a, b);

    printf("a=%d b=%d\n", a, b);
    return 0;
}

void swap(int x, int y)
{
    int tmp;
    printf("x=%d y=%d\n", x, y);

    tmp = x;
    x = y;
    y = tmp;

    printf("x=%d y=%d\n", x, y);
}



void swap(int* px, int* py);

int main(void)
{
    int a = 100, b = 200;
    printf("a=%d b=%d\n", a, b);

    swap(&a, &b);

    printf("a=%d b=%d\n", a, b);
    return 0;
}

void swap(int* px, int* py)
{
    int tmp;

    tmp = *px;
    *px = *py;
    *py = tmp;
}

// 기울기와 y절편을 계산
int get_line_parameter(int x1, int y1, int x2, int y2, float* slope, float* yintercept)
{
    if (x1 == x2)
        return -1;
    else {
        *slope = (float)(y2 - y1) / (float)(x2 - x1);
        *yintercept = y1 - (*slope) * x1;
        return 0;
    }
}

int main(void)
{
    float s, y;
    if (get_line_parameter(3, 3, 6, 6, &s, &y) == -1)
        printf("에러\n");
    else
        printf("기울기는 %f, y절편은 %f\n", s, y);
    return 0;
}

int main(void)
{
    int a[] = { 10, 20, 30, 40, 50 };

    printf("&a[0] = %u\n", &a[0]);
    printf("&a[1] = %u\n", &a[1]);
    printf("&a[2] = %u\n", &a[2]);

    printf("a = %u\n", a);

    return 0;
}

int main(void)
{
    int a[] = { 10, 20, 30, 40, 50 };

    printf("a = %u\n", a);
    printf("a + 1 = %u\n", a + 1);
    printf("*a = %d\n", *a);
    printf("*(a + 1) = %d\n", *(a + 1));

    return 0;
}

int main(void)
{
    int a[] = { 10, 20, 30, 40, 50 };
    int* p;

    p = a;
    printf("a[0]=%d a[1]=%d a[2]=%d \n", a[0], a[1], a[2]);
    printf("p[0]=%d p[1]=%d p[2]=%d \n", p[0], p[1], p[2]);

    p[0] = 60;
    p[1] = 70;
    p[2] = 80;

    printf("a[0]=%d a[1]=%d a[2]=%d \n", a[0], a[1], a[2]);
    printf("p[0]=%d p[1]=%d p[2]=%d \n", p[0], p[1], p[2]);

    return 0;
}

#include <stdio.h>
#define SIZE 5
void print_image(int image[][SIZE])
{
    int r, c;
    for (r = 0; r < SIZE; r++) {
        for (c = 0; c < SIZE; c++) {
            printf("%03d ", image[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

void brighten_image(int image[][SIZE])
{
    int r, c;
    int* p;
    p = &image[0][0];
    for (r = 0; r < SIZE; r++) {
        for (c = 0; c < SIZE; c++) {
            *p += 10;
            p++;
        }
    }
}

int main(void)
{
    int image[5][5] = {
    { 10, 20, 30, 40, 50},
    { 10, 20, 30, 40, 50},
    { 10, 20, 30, 40, 50},
    { 10, 20, 30, 40, 50},
    { 10, 20, 30, 40, 50} };
    print_image(image);
    brighten_image(image);
    print_image(image);
    return 0;
}
