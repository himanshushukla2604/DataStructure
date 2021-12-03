#include <stdio.h>
#include <stdlib.h>
typedef struct myArray
{
    int total_size; // total size of array
    int used_size;  // used size of array
    int *ptr;       // when we request mamory in heap it returns a pointer (so this will store the pointer of memory location)
} arr;

void createArray(arr *a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));//allocate tSize number of mamory of size int
    a->total_size = tSize;                       // set the total size of array
    a->used_size = uSize;                        // set the used size of array
    a->ptr = (int *)malloc(tSize * sizeof(int)); // make the array
}
// ----------------------set value------------------------------------//

void setValue(arr *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the elements %d: ", i);
        scanf("%d", &(a->ptr)[i]);
    }
}
// ----------------------insertion ------------------------------------//
int shortedinsertion(arr *a, int element, int index)
{
    if (a->used_size >= a->total_size)
    {
        return 0;
    }
    for (int i = a->used_size; i >= index; i--)
    {
        (a->ptr)[i + 1] = (a->ptr)[i];
    }
    (a->ptr)[index] = element;
    a->used_size++;
    return 1;
}

// ----------------------deletion ------------------------------------//

int shortedDeletion(arr *a, int index)
{
    if (a->used_size == 0)
    {
        return 0;
    }
    for (int i = index; i < a->used_size; i++)
    {
        (a->ptr)[i] = (a->ptr)[i + 1];
    }
    a->used_size--;
    return 1;
}

//------------------------display---------------------------------------//

void show(arr *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ", (a->ptr)[i]);
    }
    printf("\n");
}

int main()
{
    arr marks;
    createArray(&marks, 100, 10);

    // ----------------------deletion ------------------------------------//
    printf("We are running setValue now\n");
    setValue(&marks);

    //------------------------display---------------------------------------//
    printf("We are running show now\n");
    show(&marks);

    int index = 3;
    int element = 34;

    // ----------------------insertion ------------------------------------//
    int cheak = shortedinsertion(&marks, element, index);
    if (cheak)
        show(&marks);
    else
    {
        printf("The insertion failed!!!");
    }

    // ----------------------deletion ------------------------------------//
    index = 4;
    cheak = shortedDeletion(&marks, index);
    if (cheak)
        show(&marks);
    else
    {
        printf("The deletion failed!!!");
    }
    return 0;
}