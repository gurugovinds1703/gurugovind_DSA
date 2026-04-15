#include <stdio.h>
#include <stdlib.h>

int arr[100];
int front = -1;
int rear = -1;
int capacity = 100;

void enqueue(int data)
{
    if((rear + 1) % capacity == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % capacity;
    }

    arr[rear] = data;
}

int dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int x = arr[front];

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % capacity;
    }

    return x;
}

int front_element()
{
    if(front == -1)
        return -1;

    return arr[front];
}

int is_empty()
{
    if(front == -1)
        return 1;
    else
        return 0;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("%d\n", front_element());
    printf("%d\n", dequeue());

    if(is_empty())
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");

    return 0;
}