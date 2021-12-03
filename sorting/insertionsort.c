#include <stdio.h>
void insertionSort(int *a, int n)
{
    int key;
    int j;
    for (int i = 1; i <= n - 1; i++)
    {

        key = a[i];
        j = i - 1;
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[5] = {12, 4, 56, 10, 6};
    int n = 5;
    printarray(arr, n);
    insertionSort(arr, n);
    printarray(arr, n);

    return 0;
}