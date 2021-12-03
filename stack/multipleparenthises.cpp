#include <iostream>
#include <cstdlib>
using namespace std;
class stack
{
private:
    int size;
    int top;
    char *a;
public:
    stack(int size, char *ch)
    {
        size = size;
        top = -1;
        a = (char *)malloc(size * sizeof(char));
        a = ch;
    }
    int full();
    void push(char ch);
    int empty();
    char pop();
};
int stack::full()
{
    if (top >= size)
    {
        return 1;
    }
    return 0;
}
void stack::push(char ch)
{
    if (!full())
    {
        top++;
        a[top] = ch;
    }
    else
    {
        cout << "The stack is full!!!" << endl;
    }
}

int stack::empty()
{
    if (top < 0)
    {
        return 1;
    }
    return 0;
}

char stack::pop()
{
    if (!empty())
    {
        char ch = a[top];
        top--;
        return ch;
    }
    else
    {
        cout << "The stack is empty" << endl;
        return 0;
    }
}
class pmatch
{
private:
    /* data */
public:
    pmatch(char *exp)
    {
        char popped_ch;
        stack sp(45, exp);

        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            {
                sp.push(exp[i]);
            }
            else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if (sp.empty())
                {
                    printf("The parenthesis is not matching\n");
                    return;
                }
                popped_ch = sp.pop();
                if (!match(popped_ch, exp[i]))
                {
                    printf("The parenthesis is not matching\n");
                    return;
                }
            }
        }
        if (sp.empty())
        {
            printf("The parenthesis is matching\n");
            return;
        }
        else
        {
            printf("The parenthesis is not matching\n");
        }
    }

    int match(char poped_ch, char exp)
    {
        if (exp == ')' && poped_ch == '(')
        {
            return 1;
        }
        else if (exp == '}' && poped_ch == '{')
        {
            return 1;
        }
        else if (exp == ']' && poped_ch == '[')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    char exp[10] = "(8*(9)/t)";
    char *a = exp;
    pmatch p(a);
    return 0;
}