// this is bubble sort
#include <stdio.h>
int main()
{
    int arr[6] = {45, 43, 6, 8, 2, 7};
    int size = 6;
    while (size != 1)
    {

        for (int i = 0; i < size; i++)
        {

            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        size--;
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}