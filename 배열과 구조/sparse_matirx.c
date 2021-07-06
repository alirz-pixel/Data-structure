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
#include <stdlib.h>
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
int  findMax(int a, int b);
void addMatrix();

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

                sparseMatrix[0].value++; // 희소행렬에 들어있는 값의 갯수를 구하기 위한 것
            }
        }

        
        else if (menu == 2)
            printMatrix(sparseMatrix);

        else if (menu == 3)
            Transpose();

        else if (menu == 4)
            addMatrix();
    } while(menu);

    return 0;
}


void waring()
{
    printf("\n행렬의 최대 '행과 열 + 0'을 입력해주신 후, (Ex. <행 열 0>\n");
    printf("<행 열 값> 순으로 입력해주세요\n");
    printf("입력을 종료하시려면 '0 0 0'을 입력해주세요\n\n");
}

void printMenu(int* menu)
{
    printf("\n\n==메뉴==\n");
    printf("0. 종료\n");
    printf("1. 희소행렬 입력하기\n");
    printf("2. 희소행렬 출력하기\n");
    printf("3. 전치 행렬 구하기\n");
    printf("4. 두 희소행렬 더하기\n");
    printf("========\n\n");

    printf("입력 : ");
    scanf("%d", menu);
}

void printMatrix(Matrix matrix[])
{
    for (int i = 0; i <= matrix[0].value; i++)
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
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

int findMax(int a, int b)
{
    if (a < b)
        return b;

    else
        return a;
}

void addMatrix()
{
    int aIndex = 1, bIndex = 1, tempIndex = 1;

    Matrix* add_Matrix = malloc(sizeof(Matrix) * MAX_MATRIX);

    add_Matrix[0].value = 0;
    add_Matrix[0].row = findMax(sparseMatrix[0].row, trans_Matrix[0].row);
    add_Matrix[0].col = findMax(sparseMatrix[0].col, trans_Matrix[0].col);
    while(aIndex <= sparseMatrix[0].value && bIndex <= trans_Matrix[0].value)
    {
        if (sparseMatrix[aIndex].row == trans_Matrix[bIndex].row)
        {
            add_Matrix[tempIndex].row = sparseMatrix[aIndex].row;

            if (sparseMatrix[aIndex].col == trans_Matrix[bIndex].col)
            {
                add_Matrix[tempIndex].col = sparseMatrix[aIndex].col;
                add_Matrix[tempIndex++].value = sparseMatrix[aIndex++].value + trans_Matrix[bIndex++].value;
            }

            else if (sparseMatrix[aIndex].col < trans_Matrix[bIndex].col)
            {
                add_Matrix[tempIndex].col = sparseMatrix[aIndex].col;
                add_Matrix[tempIndex++].value = sparseMatrix[aIndex++].value;
            }

            else
            {
                add_Matrix[tempIndex].col = trans_Matrix[bIndex].col;
                add_Matrix[tempIndex++].value = trans_Matrix[bIndex++].value;
            }
        }

        else if (sparseMatrix[aIndex].row < trans_Matrix[bIndex].row)
        {
            add_Matrix[tempIndex].row = sparseMatrix[aIndex].row;
            add_Matrix[tempIndex].col = sparseMatrix[aIndex].col;
            add_Matrix[tempIndex++].value = sparseMatrix[aIndex++].value;
        }

        else
        {
            add_Matrix[tempIndex].row = trans_Matrix[bIndex].row;
            add_Matrix[tempIndex].col = trans_Matrix[bIndex].col;
            add_Matrix[tempIndex++].value = trans_Matrix[bIndex++].value;
        }

        add_Matrix[0].value++;
    }

    // aIndex <= sparseMatrix[0].value && bIndex <= trans_Matrix[0].value;
    if (aIndex > sparseMatrix[0].value)
        while(bIndex <= trans_Matrix[0].value)
        {
            add_Matrix[tempIndex].row = trans_Matrix[bIndex].row;
            add_Matrix[tempIndex].col = trans_Matrix[bIndex].col;
            add_Matrix[tempIndex++].value = trans_Matrix[bIndex++].value;

            add_Matrix[0].value++;
        }

    else
        while(aIndex <= sparseMatrix[0].value)
        {
            add_Matrix[tempIndex].row = sparseMatrix[aIndex].row;
            add_Matrix[tempIndex].col = sparseMatrix[aIndex].col;
            add_Matrix[tempIndex++].value = sparseMatrix[aIndex++].value;

            add_Matrix[0].value++;
        }


    printMatrix(add_Matrix);
    free(add_Matrix);
}