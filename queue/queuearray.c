#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct queue
{
    int size;
    int front;
    int rare;
    int *arr;
} queue;

queue q;
// -------------------into-------------------------------
void into(int size)
{
    q.size = 10;
    q.front = -1;
    q.rare = -1;
    q.arr = (int *)malloc(size * sizeof(int));
}

// --------------------------full-----------------------------

int full()
{
    if (q.rare == q.size)
    {
        return 1;
    }
    return 0;
}

// ------------------------------enque----------------------------
void enque(int val)
{
    if (!full())
    {
        q.rare++;
        q.arr[q.rare] = val;
    }
    else
    {
        printf("The array is full");
        printf("\nOperation enque failed!!!\n");
    }
}

// ----------------------------empty-----------------------------------
int empty()
{
    if (q.rare == q.front)
    {
        return 1;
    }
    return 0;
}

// ------------------------------deque----------------------------------
void deque()
{
    if (!empty())
    {
        q.front++;
        printf("%d ", q.arr[q.front]);
        // if(q.front == q.rare){
        //     q.front = q.rare = -1;
        // }
    }
    else
    {
        printf("The queue is empty\n");
    }
}

int main()
{
    into(10);
    enque(20);
    enque(42);
    enque(12);
    enque(56);
    deque();
    deque();
    deque();
    deque();
    deque();
    return 0;
}