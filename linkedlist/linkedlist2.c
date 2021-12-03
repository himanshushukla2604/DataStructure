#include <stdio.h>
#include <stdlib.h>
#define null NULL
typedef struct linkedlist2
{
    int data;
    struct linkedlist2 *next;
    struct linkedlist2 *prev;
} node;
node *first, *temp, *ttemp, *p, *q, *r;
void createFirst(int val)
{
    first = (node *)malloc(sizeof(node));
    first->data = val;
    first->next = null;
    first->prev = null;
}
// ---------------------add data--------------------------//
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
    temp->prev = ttemp;
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
    p->prev = temp;
    p->next = temp->next;
    temp->next = p;
}
// --------------------Display data----------------------//
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

int main()
{
    createFirst(34);
    addData(45);
    addData(56);
    addData(31);
    addData(98);
    addData(87);
    addafter(76, 45);
    display();
    return 0;
}