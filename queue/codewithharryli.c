#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int data;
    struct queue *next;
} queue;
queue *f = NULL;
queue *r = NULL;
void enqueue(int val)
{
    queue *n = (queue *)malloc(sizeof(queue));
    if (n == NULL)
    {
        printf("The queue is empty!!\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dqueue()
{
    queue *n = (queue *)malloc(sizeof(queue));

    if (f != r->next)
    {
        n = f;
        f = f->next;
        return n->data;
    }
    else
    {
        printf("the queue is empty\n");
        return -1;
    }
}

void linkedListTrevesal()
{
    queue *n = (queue *)malloc(sizeof(queue));
    n = f;

    while (n != NULL)
    {

        printf("%d\n", n->data);
        n = n->next;
    }
}
int main()
{

    enqueue(34);
    enqueue(56);
    enqueue(87);
    enqueue(12);
    printf("%d\n",dqueue());
    printf("%d\n",dqueue());
    printf("%d\n",dqueue());
    printf("%d\n",dqueue());
    enqueue(45);
    enqueue(65);
    enqueue(85);

    // linkedListTrevesal();
    return 0;
}