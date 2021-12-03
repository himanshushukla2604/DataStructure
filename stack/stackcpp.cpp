#include <iostream>
#include <stdlib.h>
// #define max 5
typedef class stack
{
public:
    int size;
    int top;
    int *a;

    stack(int sz)
    {
        size = sz;
        top = -1;
        a = (int *)malloc(size * sizeof(int));
    }
    int full(int check);
    void push(int x);
    void pop();
    void peak(int i);
    void stackTop();
    void stackBOttum();
} s;

// S1.top is same as temp->top

// void init(int size)
// {
//     // S1.size = size;
//     // S1.top = -1;
//     // S1.a = (int *)malloc(size * sizeof(int));
//     temp->size = size;
//     temp->top = -1;
//     temp->a = (int *)malloc(size * sizeof(int));
// }
// ------------------------push---------------------------------
int stack ::full(int check)
{
    check++;
    if (check < size)
    {
        return 0;
    }
    return 1;
}
void stack ::push(int x)
{
    if (!full(top))
    {
        top++;
        a[top] = x;
    }
    else
    {
        printf("Stack is full !!!\n");
    }
}
// ------------------------pop----------------------------------
void stack ::pop()
{
    if (top >= 0)
    {
        printf("%d ", a[top]);
        top--;
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

void stack ::peak(int i)
{
    if ((top - i + 1) < 0)
    {
        printf("Not a valid position\n");
        return;
    }
    else
    {
        // return S1.arr
        printf("the data at peak at position %d is %d \n", i, a[(top - i + 1)]);
    }
}

void stack ::stackTop()
{
    printf("The top of the stack is %d\n", a[top]);
}

void stack ::stackBOttum()
{
    printf("The top of the stack is %d\n", a[0]);
}

int main()
{
    stack s1(10);
    s1.push(45);
    s1.push(23);
    s1.push(55);
    s1.push(65);
    s1.push(75);
    s1.push(85);
    s1.push(83);
    s1.push(73);
    s1.push(53);
    s1.push(56);
    s1.push(37);
    // =======================peak operation=====================
    s1.stackTop();
    s1.stackBOttum();
    for (int j = 1; j <= (s1.top + 1); j++) // "+ 1 " because we have started peak from one and index of stack is form 0
    {
        s1.peak(j);
    }
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();

    s1.push(93);
    s1.pop();
    return 0;
}