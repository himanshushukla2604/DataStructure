#include <stdio.h>
#include <stdlib.h>
#define max 5
typedef struct stack
{
    int data;
    struct stack *next;
} stack;
stack *p, *top, s;
int i = 0;
void init()
{
    // top = (stack*) malloc(sizeof(stack));
    top = NULL;
}
void push(int val)
{
    if (i >= max)
    {
        printf("The stack is full!!\n");
        return;
    }
    p = (stack *)malloc(sizeof(stack));
    p->data = val;
    p->next = top;
    i++;
    top = p;
}
void pop()
{
    if (top == NULL)
    {
        printf("The stack is empty!\n");
        return;
    }
    printf("%d ", top->data);
    top = top->next;
    i--;
    free(p);
    p = top;
}

void peak(stack *temp, int i)
{
    if (temp == NULL)
    {
        printf("Not a valid position\n");
        return;
    }
    else
    {
        printf("The data at %d is %d.\n", i, temp->data);
    }
}

void stackTop()
{
    printf("The top is %d\n", top->data);
}

void stackBottum()
{
    stack *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    printf("The bottum of the stack is %d\n", ptr->data);
}

int main()
{
    push(34);
    push(56);
    push(90);
    push(43);
    push(12);

    stack *temp = top; // to pass the duplicate of the top of the stack to peak and to access all the data of the stack without poping
    for (int i = 1; i <= max; i++)
    {
        peak(temp, i);
        temp = temp->next;
    }
    stackTop();
    stackBottum();
    pop();
    pop();
    pop();
    pop();
    push(67);
    pop();
    pop();
    return 0;
}