#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class stack
{
private:
    int size;
    int top;
    char *a;

public:
    stack(int size)
    {
        size = size;
        top = -1;
        a = (char *)malloc(size * sizeof(char));
    }
    int full();
    void push(char ch);
    int empty();
    char pop();
    char stackTop();
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
// ---------------stack top--------------------------------------
char stack::stackTop()
{
    return a[top];
}

class intopost
{
private:
    /* data */
public:
    char *intopos(char *infix)
    {
        stack sp(20);
        char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
        int i = 0;
        int j = 0;
        while (infix[i] != '\0')
        {
            if (!isOperator(infix[i]))
            {
                postfix[j] = infix[i];
                cout << "hua1\n";
                i++;
                j++;
            }
            else
            {
                cout << sp.stackTop() << endl;
                if ((precedence(infix[i]) > precedence(sp.stackTop())))
                {
                    sp.push(infix[i]);
                    cout << "hua2\n";
                    i++;
                }
                else
                {
                    postfix[j] = sp.pop();
                    cout << postfix[j] << endl;
                    printf("added %d\n", j);
                    j++;
                }
            }
        }

        while (!sp.empty())
        {
            postfix[j] = sp.pop();
            cout << postfix[j];
            printf("added %d\n", j);
            j++;
        }
        postfix[j] = '\0';
        return postfix;
    }

    int precedence(char ch)
    {
        if (ch == '*' || ch == '/')
        {
            return 3;
        }
        else if (ch == '+' || ch == '-')
        {
            return 2;
        }
        return 1;
    }

    int isOperator(char ch)
    {
        if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    char st[20] = "a-b+t/6";
    intopost p;
    cout << p.intopos(st);
    return 0;
}