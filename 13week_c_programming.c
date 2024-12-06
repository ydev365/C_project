#include
<stdio.h>
int main(void)
{
int i = 100;
int* p = &i;
int** q = &p;
*p = 200;
printf("i=%d\n",i);
**q = 300;
printf("i=%d\n",i);
return 0;
}

#include <stdio.h>
void set_pointer(char** q);
int main(void){
char* p;
set_pointer(&p);
printf("오늘의 격언: %s \n", p);
return 0;
}
void set_pointer(char** q){
*q = "All that glisters is not gold.";
}

#include <stdio.h>
int main(void)
{
int i, n;
char *fruits[ ] = {
"apple",
"blueberry",
"orange",
"melon"
};
n = sizeof(fruits)/sizeof(fruits[0]); // 배열 원소 개수 계산
for(i = 0; i < n; i++)
printf("%s \n", fruits[i]);
return 0;
}

#include <stdio.h>
int main(void)
{
int a[5] = { 1, 2, 3, 4, 5 };
int (*pa)[5];
int i;
pa = &a;
for(i=0 ; i<5 ; i++)
printf("%d \n", (*pa)[i]);
return 0;
}

int add(int, int); // 함수 원형 정의
int (*pf)(int, int); // 함수 포인터 정의
...
pf = add; // 함수의 이름을 함수 포인터에 대입
result = pf( 10, 20); // 함수 포인터를 통하여 함수 호출

#include <stdio.h>
// 함수 원형 정의
int add(int, int);
int sub(int, int);
int main(void)
{
int result;
int (*pf)(int, int); // 함수 포인터 정의
pf = add; // 함수 포인터에 함수 add()의 주소 대입
result = pf(10, 20); // 함수 포인터를 통한 함수 add() 호출
printf("10+20은 %d\n", result);
pf = sub; // 함수 포인터에 함수 sub()의 주소 대입
result = pf(10, 20); // 함수 포인터를 통한 함수 sub() 호출
printf("10-20은 %d\n", result);
return 0;
}

int add(int x, int y)
{
return x+y;
}
int sub(int x, int y)
{
return x-y;
}

// 함수 포인터 배열
#include <stdio.h>
// 함수 원형 정의
void menu(void);
int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div(int x, int y);
void menu(void)
{
printf("=====================\n");
printf("0. 덧셈\n");
printf("1. 뺄셈\n");
printf("2. 곱셈\n");
printf("3. 나눗셈\n");
printf("4. 종료\n");
printf("=====================\n");
}



수int
{
main( 포인터void) 배열
int choice, result, x, y;
// 함수 포인터 배열을 선언하고 초기화한다.
int (*pf[4])(int, int) = { add, sub, mul, div };
while(1)
{
menu();
printf("메뉴를 선택하시오:");
scanf("%d", &choice);
if( choice < 0 || choice >=4 )
break;
printf("2개의 정수를 입력하시오:");
scanf("%d %d", &x, &y);
result = pf[choice](x, y); // 함수 포인터를 이용한 함수 호출
printf("연산 결과 = %d\n",result);
}
return 0;
}

int add(int x, int y) {
return x + y;
}
int sub(int x, int y) {
return x
- y;
}
int mul
(int x, int y)
{
return x * y;
}
int div(int x, int y) {
return x / y;
}

#include <stdio.h>
#include <math.h>
double f1(double k);
double f2(double k);
double formula(double (*pf)(double), int n);
int main(void)
{
printf("%f\n", formula(f1, 10));
printf("%f\n", formula(f2, 10));
}
double formula(double (*pf)(double), int n)
{
int i;
double sum = 0.0;
for(i = 1; i < n; i++)
sum += pf(i) * pf(i) + pf(i) + 1;
return sum;
}

double f1(double k)
{
return 1.0 / k;
}
double f2(double k)
{
return cos(k);
}

#include <stdio.h>
int main(void)
{
int m[3][3] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
printf("m = %p\n", m);
printf("m[0] = %p\n", m[0]);
printf("m[1] = %p\n", m[1]);
printf("m[2] = %p\n", m[2]);
printf("&m[0][0] = %p\n", &m[0][0]);
printf("&m[1][0] = %p\n", &m[1][0]);
printf("&m[2][0] = %p\n", &m[2][0]);
return 0;
}

double get_row_avg(int m[][COLS], int r)
{
int *p, *endp;
double sum = 0.0;
p = &m[r][0];
endp = &m[r][COLS];
while( p < endp )
sum += *p++;
sum /= COLS;
return sum;
}

double get_total_avg(int m[][COLS])
{
int *p, *endp;
double sum = 0.0;
p = &m[0][0];
endp = &m[ROWS-1][COLS];
while( p < endp )
sum += *p++;
sum /= ROWS * COLS;
return sum;
}

#include <stdio.h>
int main(void)
{
char s[] = "Barking dogs seldom bite.";
char t[] = "A bad workman blames his tools";
const char * p=s;
char * const q=s;
//p[3] = 'a';
p = t;
q[3] = 'a‘;
//q = t;
return 0;
}

#include <stdio.h>
int main(int argc, char *argv[])
{
int i = 0;
for(i = 0;i < argc; i++)
printf("명령어 라인에서 %d번째 문자열 = %s\n", i, argv[i]);
return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
double mile, km;
if( argc != 2 ){
printf("사용 방법: mile2km 거리\n");
return 1;
}
mile = atof(argv[1]);
km = 1.609 * mile;
printf("입력된 거리는 %f km입니다. \n", km);
return 0;
}

#include <stdio.h>
#include <stdlib.h>
int values[] = { 98, 23, 99, 37, 16 };
int compare(const void* a, const void* b)
{
return (*(int*)a - *(int*)b);
}
int main()
{
int n;
qsort(values, 5, sizeof(int), compare);
printf("정렬한 후 배열: ");
for (n = 0; n < 5; n++)
printf("%d ", values[n]);
printf("\n");
return(0);
}

#include<stdio.h>
#include <math.h>
#define EPSILON 0.0001
double func(double x)
{
return x * x * x - x * x + 2;
}
void bisection(double a, double b)
{
if (func(a) * func(b) >= 0) {
printf("적절한 a와 b가 아님\n");
return;
}
double c = a;
while ((b - a) >= EPSILON)
{
c = (a + b) / 2;
if (func(c) * func(a) < 0) {
b = c;
}
else {
a = c;
}
}
printf("최종 근 = %lf\n", c);
}

int main(void)
{
double a = -200, b = 200;
bisection(a, b);
return 0;
}
