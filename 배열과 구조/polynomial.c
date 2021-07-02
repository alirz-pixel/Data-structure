#include <stdio.h>
#include <stdbool.h>
#define MAX_TERMS 100

typedef struct _Polynomial{
    float coef;
    int expon;
} polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;


void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD);

int main(void)
{
    // terms 배열이 MAX_TERMS를 넘는지에 대한 전처리가 필요할 듯

    bool trun = true;
    int startA, finishA, startB, finishB, startD, finishD;

    // 주의사항 출력
    printf("------------------주의사항--------------------\n");
    printf(  "모든 입력은 '계수 지수' 순으로 입력해주시고 \n");
    printf("        지수는 내림차순으로 입력해주세요\n");
    printf("----------------------------------------------\n\n");


    // 다항식 A 설정
    printf("다항식 A에 대해 '계수 지수'의 형태로 입력해주세요\n");
    printf("그리고 입력을 종료하시려면 '0 0'을 입력해주세요.\n");
    startA = avail;
    while(1) {
        scanf("%f %d", &terms[avail].coef, &terms[avail].expon);

        if (terms[avail].coef == 0 && terms[avail].expon == 0)
            break;

        avail++;
    }
    finishA = avail - 1;


    // 다항식 B 설정
    printf("\n다항식 B에 대해 '계수 지수'의 형태로 입력해주세요\n");
    printf("그리고 입력을 종료하시려면 '0 0'을 입력해주세요.\n");
    startB = avail;
    while(1) {
        scanf("%f %d", &terms[avail].coef, &terms[avail].expon);

        if (terms[avail].coef == 0 && terms[avail].expon == 0)
            break;

        avail++;
    }
    finishB = avail - 1;


    // 두 다항식 더하기
    padd(startA, finishA, startB, finishB, &startD, &finishD);

    for (int i = startD; i <= finishD; i++)
        printf("%f %d\n", terms[i].coef, terms[i].expon);

    return 0;
}

void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD)
{
    *startD = avail;
    while (startA <= finishA && startB <= finishB)
    {
        if (terms[startA].expon == terms[startB].expon)
        {
            terms[avail].expon = terms[startA].expon;
            terms[avail++].coef = terms[startA++].coef + terms[startB++].coef;
        }

        else if (terms[startA].expon > terms[startB].expon)
        {
            terms[avail].expon = terms[startA].expon;
            terms[avail++].coef = terms[startA++].coef;
        }

        else
        {
            terms[avail].expon = terms[startB].expon;
            terms[avail++].coef = terms[startB++].coef;
        }
    }

    if (startA > finishA) // 남은 B 전부 옮기기
        for (int index = startB; index <= finishB; index++)
        {
            terms[avail].expon = terms[index].expon;
            terms[avail++].coef = terms[index].coef;
        }

    else
        for (int index = startA; index <= finishA; index++)
        {
            terms[avail].expon = terms[index].expon;
            terms[avail++].coef = terms[index].coef;
        }
    *finishD = avail - 1;
}