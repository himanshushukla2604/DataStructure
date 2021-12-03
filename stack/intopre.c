#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
} stack;

// ---------full------------
int full(stack *sp)
{
    if (sp->top >= sp->size - 1)
    {
        return 1;
    }
    return 0;
}

// --------------push---------------
void push(stack *sp, char val)
{
    if (!full(sp))
    {
        sp->top++;
        sp->arr[sp->top] = val;
    }
    else
    {
        printf("the stack is full\n");
    }
}

// -----------Empty---------------
int empty(int top)
{
    if (top < 0)
    {
        return 1;
    }
    return 0;
}

// ---------------------pop-----------------------
char pop(stack *sp)
{
    if (!empty(sp->top))
    {
        char ch = sp->arr[sp->top];
        sp->top--;
        return ch;
    }
    else
    {
        printf("the stack is empty\n");
        return 0;
    }
}
// ---------------stacktop------------------
int stackTop(stack *sp)
{
    return sp->arr[sp->top];
}
// -------------------isoperator-----------------
int isoperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '(')
    {
        return 1;
    }
    return 0;
}

// ---------------presedence--------------------
int presedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    // else if (ch == '/')
    // {
    //     return 2;
    // }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}

char *intopre(char *infix)
{
    stack sp;
    sp.size = 10;
    sp.top = -1;
    sp.arr = (char *)malloc(sp.size * sizeof(char));

    char *prefix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    char *fix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    // int x = 0;
    // int y = 0;
    // while (infix[x] != '\0')
    // {
    //     if(infix[x] == '(' || infix[x] == '')
    //     fix[y] = infix[x];
    //     y++;
    //     x++;
    // }

    int i = strlen(infix) - 1;
    int j = strlen(infix);
    prefix[j] = '\0';
    j--;
    while (i >= 0)
    {
        if (!isoperator(infix[i]))
        {
            if (infix[i] == ')')
            {
                i--;
                prefix[j] = ' ';
                j--;
            }
            else
            {
                prefix[j] = infix[i];
                printf("prefix %d %c\n", j, prefix[j]);
                j--;
                i--;
            }
        }
        else
        {
            if (infix[i] == '(' && !empty(sp.top))
            {
                prefix[j] = pop(&sp);
                printf("prefix %d %c\n", j, prefix[j]);
                j--;
                prefix[j] = ' ';
                i--;
                j--;
            }
            else
            {

                // if (presedence(infix[i]) > presedence(stackTop(&sp)) && !empty(sp.top))
                // {
                //     prefix[j] = pop(&sp);
                //     printf("prefix %d %c\n", j, prefix[j]);
                //     j--;
                // }
                // else
                // {
                printf("two %c\n", infix[i]);
                push(&sp, infix[i]);
                i--;
                // }
            }
        }
    }
    while (!empty(sp.top))
    {
        prefix[j] = pop(&sp);
        printf("prefix %d %c\n", j, prefix[j]);
        j--;
    }
    printf("%s\n", prefix);
    return prefix;
}
int main()
{
    char *infix = "((A+B)*(C-D))";
    printf("%s", intopre(infix));
    return 0;
}