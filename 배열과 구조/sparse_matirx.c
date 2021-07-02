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

                sparseMatrix[0].value++; // 희소행렬에 들어있는 값의 갯수를 구하기 위한 것
            }
        }

        
        if (menu == 2)
            Transpose();

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
    printf("2. 전치 행렬 구하기\n");
    printf("========\n\n");

    printf("입력 : ");
    scanf("%d", menu);
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