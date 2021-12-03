#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;
} queue;

queue *f, *r, *q, *temp, *ttemp;

void init()
{
    q = (queue *)malloc(sizeof(queue));
    f = r = q;
    f = NULL;
    r = NULL;
}

void enqueue(int val)
{
    temp = (queue *)malloc(sizeof(queue));
    if (temp != NULL)
    {
        temp->data = val;
        temp->next = NULL;
        if (f == NULL)
        {
            f = r = temp;
        }
        else
        {
            r->next = temp;
            r = temp;
        }
    }
    else
    {
        printf("The queue is full\n");
    }
}

void dequeue()
{
    temp = f;
    if (f != NULL)
    {
        printf("%d\n", f->data);
        f = temp->next;
        free(temp);
    }
    else
    {
        printf("The queue is empty\n");
    }
}

int main()
{
    enqueue(34);
    enqueue(56);
    enqueue(89);
    enqueue(12);

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}