#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int size;
    int rare;
    int front;
    int *arr;
} queue;
queue q;

void init(int size)
{
    q.size = size;
    q.rare = -1;
    q.front = -1;
    q.arr = (int *)malloc(size * sizeof(int));
}

void enqueuer(int val)
{
    if (q.rare < (q.size - 1))
    {
        q.rare++;
        q.arr[q.rare] = val;
    }
    else
    {
        printf("Queue is full\n");
    }
}

void enqueuef(int val)
{
    if (q.front >= 0)
    {
        q.front--;
        q.arr[q.front] = val;
    }
    else
    {
        printf("Queue is full\n");
    }
}

int dequeuef()
{
    if (q.front <= q.rare)
    {
        q.front++;
        int val = q.arr[q.front];

        return val;
    }
    else
    {
        printf("queue is empty\n");
        return -1;
    }
}

int dequeuer()
{
    if (q.rare >= q.front)
    {
        int val = q.arr[q.rare];
        q.rare--;
        return val;
    }
    else
    {
        printf("queue is empty\n");
        return -1;
    }
}
int main()
{
    init(6);
    enqueuer(45);
    enqueuer(67);
    enqueuer(89);
    enqueuer(57);
    enqueuer(87);
    printf("%d\n", dequeuef());
    printf("%d\n", dequeuef());
    enqueuef(23);
    enqueuef(56);
    printf("%d\n", dequeuer());
    return 0;
}