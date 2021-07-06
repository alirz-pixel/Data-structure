/*
test case

6 6 0
0 0 15
0 3 22
0 5 -15
1 1 11
1 2 3
2 3 -6
4 0 91
5 2 28
0 0 0
*/

#include <stdio.h>
#define MAX_MATRIX 100

typedef struct {
    int row;
    int col;
    int value;
} Matrix;

Matrix sparseMatrix[MAX_MATRIX];
Matrix trans_Matrix[MAX_MATRIX];


void waring();
void printMenu(int* menu);
void printMatrix();
void Transpose();

int main(void)
{   
    int menu;


    do
    {
        printMenu(&menu);

        
        if (menu == 1)
        {
            waring();

            scanf("%d %d %d", &sparseMatrix[0].col, &sparseMatrix[0].row, &sparseMatrix[0].value);
            for (int i = 1; i < MAX_MATRIX; i++)
            {
                scanf("%d %d %d", &sparseMatrix[i].row, &sparseMatrix[i].col, &sparseMatrix[i].value);

                if (!sparseMatrix[i].col && !sparseMatrix[i].row && !sparseMatrix[i].value)
                    break;

                sparseMatrix[0].value++; // �����Ŀ� ����ִ� ���� ������ ���ϱ� ���� ��
            }
        }

        
        else if (menu == 2)
            printMatrix();

        else if (menu == 3)
            Transpose();

    } while(menu);

    return 0;
}


void waring()
{
    printf("\n����� �ִ� '��� �� + 0'�� �Է����ֽ� ��, (Ex. <�� �� 0>\n");
    printf("<�� �� ��> ������ �Է����ּ���\n");
    printf("�Է��� �����Ͻ÷��� '0 0 0'�� �Է����ּ���\n\n");
}

void printMenu(int* menu)
{
    printf("\n\n==�޴�==\n");
    printf("0. ����\n");
    printf("1. ������ �Է��ϱ�\n");
    printf("2. ������ ����ϱ�\n");
    printf("3. ��ġ ��� ���ϱ�\n");
    printf("========\n\n");

    printf("�Է� : ");
    scanf("%d", menu);
}

void printMatrix()
{
    for (int i = 0; i <= sparseMatrix[0].value; i++)
        printf("%d %d %d\n", sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
}

void Transpose()
{
    int size = sparseMatrix[0].value;

    trans_Matrix[0].row = sparseMatrix[0].col;
    trans_Matrix[0].col = sparseMatrix[0].row;
    trans_Matrix[0].value = size;

    int tempIndex = 1;
    for (int col = 0; col < sparseMatrix[0].col; col++)
        for (int i = 1; i <= sparseMatrix[0].value; i++)
            if (sparseMatrix[i].col == col)
            {
                trans_Matrix[tempIndex].col = sparseMatrix[i].row;
                trans_Matrix[tempIndex].row = sparseMatrix[i].col;
                trans_Matrix[tempIndex++].value = sparseMatrix[i].value;
            }


    for (int i = 0; i <= trans_Matrix[0].value; i++)
        printf("%d %d %d\n", trans_Matrix[i].row, trans_Matrix[i].col, trans_Matrix[i].value);
}