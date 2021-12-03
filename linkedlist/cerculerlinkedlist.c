#include <stdio.h>
#include <stdlib.h>
typedef struct linkedlist
{
    int data;
    struct linkedlist *next;
} node;

node *first, *temp, *ttemp, *p, *r;

void creatfirst(int val)
{
    first = (node *)malloc(sizeof(node));
    first->data = val;
    first->next = first;
}
//----------------add at first---------------------------------
void addAtFirst(int val)
{
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = first;
    first = temp;
}

//----------------add at the end-------------------------------
void addData(int val)
{
    temp = first;
    while (temp->next != first)
        temp = temp->next;
    ttemp = (node *)malloc(sizeof(node));
    ttemp->data = val;
    ttemp->data = first;
    temp->next = ttemp;
}
//---------------add by index----------------------------------
void addByIndex(int val, int index)
{
    if (index == 0)
    {
        addAtFirst(val);
        return;
    }
    temp = first->next;
    int i = 1;
    while (i != index)
    {
        temp = temp->next;
        i++;
    }

    ttemp = (node *)malloc(sizeof(node));
    ttemp->data = val;
    ttemp->next = temp->next;
    temp->next = ttemp;
}
//---------------deletion at the end------------------------------------
void deletionAtEnd()
{
    ttemp = temp = first;
    while (temp->next != first)
    {
        ttemp = temp;
        temp = temp->next;
    }
    if (temp != first)
    { // in this condetion it will not delete the head node
        ttemp = first;
        free(temp);
    }
    else
    {
        printf("\nDeletion failed!!!   You are trying to delete the head\n");
    }
}

void deletefirst()
{
    temp = first;
    if (first->next != first)
    {
        first = first->next;
        free(temp);
    }
    else
    {
        printf("This is the only node present in your linked list.");
        char del;
        printf("For deleting press y");
        scanf("%c", &del);
        if (del == 'y')
        {
            free(first);
        }
        else
        {
            printf("not deleted");
        }
    }
}

void deleteByIndex(int index)
{
    temp = first;
    if (index == 0)
    {
        deletefirst();
        return;
    }
    p = temp = first->next;
    int i = 1;
    do
    {
        p = temp;
        temp = temp->next;
        i++;
    } while (i != index);

    p = temp->next;
    free(temp);
}

int main()
{

    return 0;
}