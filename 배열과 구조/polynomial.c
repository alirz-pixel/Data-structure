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
    // terms �迭�� MAX_TERMS�� �Ѵ����� ���� ��ó���� �ʿ��� ��

    bool trun = true;
    int startA, finishA, startB, finishB, startD, finishD;

    // ���ǻ��� ���
    printf("------------------���ǻ���--------------------\n");
    printf(  "��� �Է��� '��� ����' ������ �Է����ֽð� \n");
    printf("        ������ ������������ �Է����ּ���\n");
    printf("----------------------------------------------\n\n");


    // ���׽� A ����
    printf("���׽� A�� ���� '��� ����'�� ���·� �Է����ּ���\n");
    printf("�׸��� �Է��� �����Ͻ÷��� '0 0'�� �Է����ּ���.\n");
    startA = avail;
    while(1) {
        scanf("%f %d", &terms[avail].coef, &terms[avail].expon);

        if (terms[avail].coef == 0 && terms[avail].expon == 0)
            break;

        avail++;
    }
    finishA = avail - 1;


    // ���׽� B ����
    printf("\n���׽� B�� ���� '��� ����'�� ���·� �Է����ּ���\n");
    printf("�׸��� �Է��� �����Ͻ÷��� '0 0'�� �Է����ּ���.\n");
    startB = avail;
    while(1) {
        scanf("%f %d", &terms[avail].coef, &terms[avail].expon);

        if (terms[avail].coef == 0 && terms[avail].expon == 0)
            break;

        avail++;
    }
    finishB = avail - 1;


    // �� ���׽� ���ϱ�
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

    if (startA > finishA) // ���� B ���� �ű��
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