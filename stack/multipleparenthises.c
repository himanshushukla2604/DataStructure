#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    int size;
    int top;
    char *a;
} stack;
stack *s1;

// void create(int size)
// {
//     stack->size = size;
//     stack->top = -1;
//     stack->a = (char *)malloc(size * sizeof(char));
// }
// ------------------------push---------------------------------

int full(stack *s1, int check)
{
    if (check >= s1->size)
    {
        return 0;
    }
    return 1;
}

void push(stack *s1, char val)
{
    if (full(s1, s1->top))
    {
        s1->top++;
        s1->a[s1->top] = val;
    }
    else
    {
        printf("Your Stack is full\n");
    }
}
// ------------------------pop----------------------------------
int empty(int check)
{
    if (check < 0)
    {
        return 1;
    }
    return 0;
}

char pop(stack *s1)
{
    char ch;

    if (!empty(s1->top))
    {
        ch = s1->a[s1->top];
        s1->top--;
        return ch;
    }
    else
    {
        printf("Stack is empty\n");
        return 0;
    }
}

// ------------------match---------------------------
int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }

    else if (a == '[' && b == ']')
    {
        return 1;
    }
    else if (a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}

// ----------------------parenthises matching--------------------------

int parenthesisMatch(char *exp)
{
    stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->a = (char *)malloc(sp->size * sizeof(char));

    char popped_ch;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (empty(sp->top))
            {
                return 0;
            }
            popped_ch = pop(sp);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (empty(sp->top))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// ---------------------------------------main-----------------------------------------
int main()
{
    char exp[20] = "{4-[8*(9)]}";

    char *c = exp;

    // for (int i = 0; i < sizeof(c); i++)
    // {
    //     if (c[i] == '(')
    //     {
    //         push(c[i]);
    //     }
    //     else if (c[i] == ')')
    //     {
    //         pop();
    //     }
    // }
    // if (stack->a[0] == '(' || empty(stack->top))
    // {
    //     printf("invalid statement\n");
    // }
    printf("it works\n");
    if (parenthesisMatch(c))
    {
        printf("The parentheses is matching\n");
    }
    else
    {
        printf("The parentheses is not matching\n");
    }
    return 0;
}