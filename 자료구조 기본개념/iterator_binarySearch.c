#include <stdio.h>

#define MAX 10
int arr[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int main(void)
{
    int key;
    scanf("%d", &key);


    int left, right, middle;

    left = 0;
    right = MAX - 1;

    while (left <= right)
    {
        middle = (left + right) / 2;

        if (arr[middle] < key)
            left = middle + 1;

        else if (arr[middle] > key)
            right = middle - 1;

        else
        {
            printf("키 값을 찾았습니다.\n");
            printf("인덱스 : %d\n\n", middle);
            return 1;
        }
    }

    printf("키 값을 찾지 못했습니다.\n\n");

    return -1;
}