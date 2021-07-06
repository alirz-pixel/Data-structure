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
도착점으로 가는 길이 없음

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
    printf("미로의 너비와 높이를 정해주세요 : ");
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
    printf("\n\n현재 탐색 중인 경로를 출력하시겠습니까?\n");
    printf("0. No   1. Yes\n");
    printf("---------------\n");
    printf("입력 : ");
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
                printf("\n 성공\n");
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
        printf("실패\n\n");
}


// void BFS(short int** maze, int startX, int startY, int endX, int endY)
// {
//     short int** visited = (short int**)malloc(sizeof(short int*) * endY);
//     for (int y = 0; y < endY; y++)
//         visited[y] = (short int*)malloc(sizeof(short int) * endX);
// }

void printPath()
{
    printf(" 결과가 나오게 된 경로를 출력하겠습니다.\n");
    for (int i = 0; i < top; i++)
        printf(" %-2d %-2d\n", st[i].y, st[i].x);
}