#include <stdio.h>
#include <stdlib.h>
// #define max 5
typedef struct stack
{
    int size;
    int top;
    int *a;
} s;
s S1;
s *temp = &S1;

// S1.top is same as temp->top

void init(int size)
{
    // S1.size = size;
    // S1.top = -1;
    // S1.a = (int *)malloc(size * sizeof(int));
    temp->size = size;
    temp->top = -1;
    temp->a = (int *)malloc(size * sizeof(int));
}
// ------------------------push---------------------------------
int full(int check)
{
    check++;
    if (check < temp->size)
    {
        return 0;
    }
    return 1;
}
void push(int x)
{
    if (!full(temp->top))
    {
        temp->top++;
        temp->a[temp->top] = x;
    }
    else
    {
        printf("Stack is full !!!\n");
    }
}
// ------------------------pop----------------------------------
void pop()
{
    if (temp->top >= 0)
    {
        printf("%d ", S1.a[S1.top]);
        S1.top--;
    }
    else
    {
        printf("Deletion failed!!\n");
    }
}
// -----------------------peak operation-------------------------
// (i) position of peak (we are strating the position from 1 we can also start from zero)

// position  array index   top = 2   (position = top - i + 1)
// 1           2
// 2           1
// 3           0
// peak operation help us to which elements are present is  stack (whitout poping out the elements )

void peak(int i)
{
    if ((S1.top - i + 1) < 0)
    {
        printf("Not a valid position\n");
        return;
    }
    else
    {
        // return S1.arr
        printf("the data at peak at position %d is %d \n", i, S1.a[(S1.top - i + 1)]);
    }
}

void stackTop()
{
    printf("The top of the stack is %d\n", S1.a[S1.top]);
}

void stackBOttum()
{
    printf("The top of the stack is %d\n", S1.a[0]);
}

int main()
{
    int x;
    init(9);
    push(23);
    push(45);
    push(55);
    push(65);
    push(75);
    push(85);
    push(83);
    push(73);
    push(53);
    push(56);
    push(37);
    // =======================peak operation=====================
    stackTop();
    stackBOttum();
    for (int j = 1; j <= (S1.top + 1); j++) // "+ 1 " because we have started peak from one and index of stack is form 0
    {
        peak(j);
    }
    // push(23);
    // pop();
    // pop();
    // pop();
    // pop(); 
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();

    push(93);
    pop();
    return 0;
}