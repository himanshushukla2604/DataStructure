#include <stdio.h>
#include <stdlib.h>
#define null NULL
// time comlexity of treversal is big O(n)
typedef struct linkedlist1
{
    int data;
    struct linkedlist1 *next;
} node;

node *first, *temp, *ttemp, *p, *q, *r;

void createFirst(int val)
{
    first = (node *)malloc(sizeof(node));
    first->data = val;
    first->next = null;
}
// -------------------ADD OPERATION --------------------------//
void addData(int val)
{
    ttemp = temp = first;
    
    while (temp != null)
    {
        ttemp = temp;
        temp = temp->next;
    }
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = null;
    ttemp->next = temp;
}

void addafter(int val, int num)
{
    ttemp = temp = first;
    while (temp->data != num)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = (node *)malloc(sizeof(node));
    p->data = val;
    p->next = temp->next;
    temp->next = p;
}

void addbefore(int val, int num)
{
    ttemp = temp = first;
    while (temp->data != num)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = (node *)malloc(sizeof(node));
    p->data = val;
    p->next = temp;
    ttemp->next = p;
}

// -------------------DEL OPERATION --------------------------//

void delData()// delete at the end
{
    ttemp = temp = first;
    while (temp->next != null)
    {
        ttemp = temp;
        temp = temp->next;
    }
    free(temp);
    ttemp->next = null;
}

void delafter(int val)
{
    ttemp = p = temp = first;
    while (temp->data != val)
    {
        // ttemp = temp;
        temp = temp->next;
    }
    p = temp->next;
    temp->next = p->next;
    free(p);
    // p->next = null;
}

void delbefore(int val)
{
    p = ttemp = temp = first;
    while (temp->next->data != val)
    {
        // p = ttemp;
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = temp->next;
    free(temp);
}

// -------------------SWAP OPERATION --------------------------//
void swap(int val, int num)
{
    p = q = ttemp = temp = first;
    while (temp->data != val)
    {
        ttemp = temp;
        temp = temp->next;
    }
    while (q->data != num)
    {
        p = q;
        q = q->next;
    }
    p->next = temp;
    r = temp->next;
    temp->next = q->next;
    ttemp->next = q;
    q->next = r;
}
void swapFirstLast()
{
    p = q = ttemp = temp = first;
    while (temp->next != null)
    {
        ttemp = temp;
        temp = temp->next;
    }
    first = temp;
    first->next = p->next;
    p->next = null;
    ttemp->next = p;
}

// -------------------DISPLAY OPERATION --------------------------//
void display()
{
    ttemp = temp = first;
    while (temp != null)
    {
        ttemp = temp;
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// -------------------MAIN FUNCTION --------------------------//

int main()
{
    int val;
    createFirst(45);
    addData(43);
    addData(89);
    addData(67);
    addData(23);
    // delData();
    // delafter(43);
    delbefore(89);
    addafter(43, 89);
    addbefore(56, 89);
    swap(56, 43);
    swapFirstLast();
    display();

    return 0;
}