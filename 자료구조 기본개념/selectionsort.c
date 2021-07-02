#include <stdio.h>

#define MAX 5

void swap(int *a, int *b);


int main(void)
{
    int arr[MAX] = { 4, 2, 1, 3, 5 };
    int min, min_Index;


    for (int i = 0; i < MAX; i++)
    {
        min = arr[i];
        min_Index = i;

        for (int j = i + 1; j < MAX; j++)
            if (arr[j] < min)
            {
                min = arr[j];
                min_Index = j;
            }

        swap(&arr[i], &arr[min_Index]);
    }


    for (int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
}


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}