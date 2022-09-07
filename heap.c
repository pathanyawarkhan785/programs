#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

int insert(int arr[], int arrSize, int val)
{
    arrSize = arrSize + 1; // arrSize = 6
    arr[arrSize] = val;    // arr[6] = 27 (user Input val)
    int i = arrSize;       // i = 6
    while (i > 1)          // (6 > 1)
    {
        int parent = i / 2;
        if (arr[parent] < arr[arrSize])
        {
            swap(arr[parent], arr[arrSize]);
        }
        else
        {
            return;
        }
        return 0;
    }
}

void main()
{
    int arr[] = {50, 30, 40, 10, 5, 20, 30}, val;
    printf("Enter value you want to insert : ");
    scanf("%d", &val);
    int arrSize = sizeof arr / sizeof arr[0];
    insert(arr, arrSize, val);
}