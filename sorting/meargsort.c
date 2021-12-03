#include <stdio.h>
void merge(int *a, int mid, int low, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[high];
    while (i < mid && j < high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while(i <= mid){
        b[k] = a[i];
        i++;
        k++;
    }
    while (j < high){
        b[k] = a[j];
        j++;
        k++;
    }
    for(int i = low; i <= high; i++){
        a[i] = b[i];
    }
}
int main()
{
    
    return 0;
}