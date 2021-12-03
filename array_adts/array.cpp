#include <iostream>
#include <cstdlib>
using namespace std;

class myArray
{
    int total_size;
    int used_size;
    int *ptr; // when we request mamory in heap it returns a pointer (so this will store the pointer of memory location)

public:
    myArray(myArray *a, int tSize, int uSize)
    {
        // (*a).total_size = tSize;
        // (*a).used_size = uSize;
        // (*a).ptr = (int *)malloc(tSize * sizeof(int));//allocate tSize number of mamory of size int
        a->total_size = tSize;
        a->used_size = uSize;
        // a->ptr = (int *)malloc(tSize * sizeof(int));
        a->ptr = new int[total_size]; // to allocate the memory of "total_size" number of element and of size int.
    }

    // ----------------------set value------------------------------------//

    void setValue(myArray *a)
    {
        int n;
        for (int i = 0; i < a->used_size; i++)
        {
            printf("Enter the elements %d: ", i);
            scanf("%d", &(a->ptr)[i]);
            // (a->ptr)[i] = n;
        }
    }

    // ----------------------insertion ------------------------------------//

    int shortedinsertion(myArray *a, int element, int index)
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

    int shortedDeletion(myArray *a, int index)
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

    void show(myArray *a)
    {
        for (int i = 0; i < a->used_size; i++)
        {
            printf("%d ", (a->ptr)[i]);
        }
        cout << endl;
    }
};

int main()
{
    myArray marks(&marks, 100, 10);
    printf("We are running setValue now\n");

    // ----------------------set value------------------------------------//
    marks.setValue(&marks);
    printf("We are running show now\n");

    //------------------------display-------------------------------------//
    marks.show(&marks);

    // ----------------------insertion -----------------------------------//
    int index = 3;
    int element = 34;
    int cheak = marks.shortedinsertion(&marks, element, index);
    if (cheak)
        marks.show(&marks);
    else
        printf("The insertion failed!!!");

    // ----------------------deletion ------------------------------------//
    index = 4;
    cheak = marks.shortedDeletion(&marks, index);
    if (cheak)
        marks.show(&marks);
    else
    {
        printf("The deletion failed!!!");
    }
    return 0;
}