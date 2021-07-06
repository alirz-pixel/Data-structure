/*
testcase 1
15 11
0 1 0 0 0 1 1 0 0 0 1 1 1 1 1
1 0 0 0 1 1 0 1 1 1 0 0 1 1 1
0 1 1 0 0 0 0 1 1 1 1 0 0 1 1
1 1 0 1 1 1 1 0 1 1 0 1 1 0 0
1 1 0 1 0 0 1 0 1 1 1 1 1 1 1
0 0 1 1 0 1 1 1 0 1 0 0 1 0 1
0 0 1 1 0 1 1 1 0 1 0 0 1 0 1
0 1 1 1 1 0 0 1 1 1 1 1 1 1 1
1 1 0 0 0 1 1 0 1 1 0 0 0 0 0
0 0 1 1 1 1 1 0 0 0 1 1 1 1 0
0 1 0 0 1 1 1 1 1 0 1 1 1 1 0
���������� ���� ���� ����

tastcase 2
6 9
0 0 0 0 0 1
1 1 1 1 1 0
1 0 0 0 0 1
0 1 1 1 1 1
1 0 0 0 0 1
1 1 1 1 1 0
1 0 0 0 0 1
0 1 1 1 1 1
1 0 0 0 0 0

tastcase 3
6 5
0 1 1 1 0 0
0 1 1 0 0 0
0 1 0 0 1 0
0 1 0 0 1 0
0 0 0 1 1 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 200
#define MAXDIR 8

typedef struct _Stack{
    int y;
    int x; 
}stack;
stack st[MAXSIZE];
int top = -1;


typedef struct _Offsets{
    short int vert;
    short int horiz;
} offsets;
offsets move[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1},  {-1, -1} };



void DFS(short int** maze, int startX, int startY, int endX, int endY);
void BFS(short int** maze, int startX, int startY, int endX, int endY);
void printPath();
int main(void)
{
    int m, p;
    printf("�̷��� �ʺ�� ���̸� �����ּ��� : ");
    scanf("%d %d", &p, &m);

    short int** maze = (short int**)malloc(sizeof(short int*) * m);
    for (int y = 0; y < m; y++)
    {
        maze[y] = (short int*)malloc(sizeof(short int) * p);

        for (int x = 0; x < p; x++)
            scanf("%d", &maze[y][x]);
    }


    DFS(maze, 0, 0, p, m);
    printPath();
    return 0;
}



void DFS(short int** maze, int startX, int startY, int endX, int endY)
{
    short int** visited = (short int**)calloc(endY, sizeof(short int*));
    for (int y = 0; y < endY; y++)
        visited[y] = (short int*)calloc(endX, sizeof(short int));
    top = -1;

    
    bool print_findPath = false;
    printf("\n\n���� Ž�� ���� ��θ� ����Ͻðڽ��ϱ�?\n");
    printf("0. No   1. Yes\n");
    printf("---------------\n");
    printf("�Է� : ");
    scanf("%d", &print_findPath);
    if (print_findPath)
    {
        printf("\n------path------\n");
        printf("      %-2d  %-2d\n", startY, startX);
    }


    int nextRow, nextCol, row, col;
    bool success = false;

    visited[startY][startX] = 1;
    st[++top].x = startX;
    st[top].y = startY;
    while(top != -1)
    {
        row = st[top].y;
        col = st[top--].x;

        for (int dir = 0; dir < MAXDIR; dir++)
        {
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;

            if ((nextRow == endY - 1) && (nextCol == endX - 1))
            {
                if (print_findPath)  printf("----------------\n");
                printf("\n ����\n");
                success = true;
                break;
            }

            if (nextRow < 0 || nextRow >= endY || nextCol < 0 || nextCol >= endX)
                continue;
            
            if (!maze[nextRow][nextCol] && !visited[nextRow][nextCol])
            {
                if (print_findPath)  printf("      %-2d  %-2d\n", nextRow, nextCol);
                
                
                visited[nextRow][nextCol] = 1;

                st[++top].x = nextCol;
                st[top].y = nextRow;

                row = nextRow;
                col = nextCol;
                dir = 0;
            }
        }

        if (success)
            break;
    }

    if (!success)
        printf("����\n\n");
}


// void BFS(short int** maze, int startX, int startY, int endX, int endY)
// {
//     short int** visited = (short int**)malloc(sizeof(short int*) * endY);
//     for (int y = 0; y < endY; y++)
//         visited[y] = (short int*)malloc(sizeof(short int) * endX);
// }

void printPath()
{
    printf(" ����� ������ �� ��θ� ����ϰڽ��ϴ�.\n");
    for (int i = 0; i < top; i++)
        printf(" %-2d %-2d\n", st[i].y, st[i].x);
}