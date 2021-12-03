#include <stdio.h>
void selectionsort(int *arr, int n)
{
    int min;
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];

        arr[min] = temp;
    }
}
int main()
{
    int n;
    printf("Enter the number of element in the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the values in array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    selectionsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}