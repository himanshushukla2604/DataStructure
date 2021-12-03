// infix to postfix using stack

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
typedef struct stack
{
    int size;
    int top;
    char *a;
} stack;

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
// ---------------------stack top-------------------
int stackTop(stack *sp)
{
    return sp->a[sp->top];
}

// -----------precedence------------------
int precedence(char c)
{
    if (c == '*' || c == '/')
    {
        return 3;
    }
    else if (c == '+' || c == '-')
    {
        return 2;
    }

    return 0;
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 1;
    }
    return 0;
}
char *infixtopostfix(char *infix)
{
    stack *sp = (stack *)malloc(sizeof(stack)); // memory allocated for sp
    sp->size = 10;
    sp->top = -1;
    sp->a = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char)); // here we store the postfix
    int i = 0;                                                          //track infix traversal
    int j = 0;                                                          // track postyfix addition

    while (infix[i] != '\0') // traverse i
    {
        if (!isOperator(infix[i]))
        {

            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {

            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++; // here we will push till we did not get the higher precedence operator so we will only itrater through infix expression
            }
            else
            {
                postfix[j] = pop(sp);
                j++; // we are adding to postfix so we will increase j
            }
        }
    }
    while (!empty(sp->top))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0'; // here we are adding '\0' at the end so that it become a valid string and we can access it by using %s
    return postfix;
}

int main()
{
    char *infix = "a-b+t/6";
    printf("postfix expression is %s", infixtopostfix(infix));
    return 0;
}