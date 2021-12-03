#include <stdio.h>
void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int partition(int *arr, int low, int high)
{
    int temp;
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {

        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);// when j will be smaller than i

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}
void quicksort(int *arr, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {

        partitionIndex = partition(arr, low, high);
        quicksort(arr, low, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    int arr[] = {3, 5, 2, 13, 12};
    int n = 5;
    printarray(arr, n);
    quicksort(arr, 0, n - 1);
    printarray(arr, n);
    return 0;
}