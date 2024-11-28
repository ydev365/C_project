#include <stdio.h>

int main(void)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        int temp = 1;
        printf("temp = %d\n", temp);
        temp++;
    }
    return 0;
}



int all_files;         // Global variable with external linkage
static int this_file;  // Static variable with internal linkage
extern void sub();     // Declaration of a function defined in another file

int main(void)
{
    sub();  // Call the function from another file
    printf("%d\n", all_files); // Print the value of `all_files` modified by `sub`
    return 0;
}


extern int all_files; // Declaration of the global variable from `linkage1.c`

void sub(void)
{
    all_files = 10; // Modify the global variable
}


#define SEED 17
int MULT = 25173;
int INC = 13849;
int MOD = 65536;

static unsigned int seed = SEED; // 난수 생성 시드값

// 정수 난수 생성 함수
unsigned random_i(void)
{
    seed = (MULT * seed + INC) % MOD; // 난수의 시드값 설정
    return seed;
}

// 실수 난수 생성 함수
double random_f(void)
{
    seed = (MULT * seed + INC) % MOD; // 난수의 시드값 설정
    return seed / (double)MOD; // 0.0에서 1.0 사이로 제한
}



extern unsigned random_i(void);
extern double random_f(void);

extern int MOD;

int main(void)
{
    int i;

    MOD = 32767; // MOD 값을 변경
    for (i = 0; i < 10; i++)
        printf("%d ", random_i());

    return 0;
}
