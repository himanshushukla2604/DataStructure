#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cqueue
{
    int size;
    int front;
    int rare;
    int *arr;
};
struct cqueue queue;
void init(int size)
{
    queue.size = size;
    queue.front = -1;
    queue.rare = -1;
    queue.arr = (int *)malloc(size * sizeof(int));
}

// ======================full===========================//

int full()
{
    if ((queue.rare + 1) % queue.size == queue.front)
    {
        return 1;
    }
    return 0;
}

// =====================enque===========================//

void enque(int val)
{
    if (!full())
    {
        queue.rare = (queue.rare + 1) % queue.size;
        queue.arr[queue.rare] = val;
    }
    else
    {
        printf("overflow!!!\n");
    }
}

// =====================empty===========================//
int empty()
{
    if (queue.rare == queue.front)
    {
        return 1;
    }
    return 0;
}

// =====================dqueue==========================//
void deque()
{
    if (!empty())
    {
        queue.front = (queue.front + 1) % queue.size;
        printf("%d\n", queue.arr[queue.front]);
    }
    else
    {
        printf("The queue is empty\n");
    }
}
int main(void)
{
    init(10);

    enque(45);
    enque(34);
    enque(89);
    enque(78);
    enque(23);
    enque(45);
    enque(34);
    enque(89);
    enque(78);
    enque(23);

    deque();
    deque();
    deque();
    deque();
    deque();
    deque();
    deque();
    deque();
    deque();
    deque();

    deque();
    enque(98);
    deque();
}