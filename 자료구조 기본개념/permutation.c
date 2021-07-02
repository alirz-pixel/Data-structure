#include <stdio.h>
#include <stdlib.h>


void swap(char* a, char* b);
void permutation(char* arr, int i, int n);

int cnt = 0;
int main(void)
{
    int n;
    scanf("%d", &n);

    char* arr = malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++)
        arr[i] = 'A' + i;

    permutation(arr, 0, n);
    printf("%d!  %d", n, cnt);

    free(arr);
    return 0;
}


void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


void permutation(char* arr, int i, int n)
{
    if (i == n)
    {
        for (int j = 0; j < n; j++)
            printf("%c", arr[j]);
        printf("\n");

        cnt++;
    }

    else
        for (int j = i; j < n; j++)
        {
            swap(&arr[i], &arr[j]);
            permutation(arr, i+1, n);
            swap(&arr[i], &arr[j]);
        }
}