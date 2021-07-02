#include <stdio.h>

#define MAX 10

int arr[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int binarysearch(int left, int right, int key);


int main(void)
{
    int findKey, result;
    scanf("%d", &findKey);

    result = binarysearch(0, MAX - 1, findKey);

    if (result == -1)
        printf("ã���ô� ���� �����ϴ�.\n");

    else
    {
        printf("�迭�� ã���ô� ���� �ֽ��ϴ�.\n");
        printf("�ε��� : %d", result);
    }


    return 0;
}


int binarysearch(int left, int right, int key)
{
    if (left <= right)
    {
        int middle = (left + right) / 2;

        if (arr[middle] > key)
            return binarysearch(left, middle - 1, key);

        else if (arr[middle] < key)
            return binarysearch(middle + 1, right, key);

        else
            return middle;
    }

    return -1;
}