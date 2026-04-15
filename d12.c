#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front_node = NULL;
struct node *rear = NULL;

void enqueue(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(rear == NULL)
    {
        front_node = rear = newnode;
        return;
    }

    rear->next = newnode;
    rear = newnode;
}

int front()
{
    if(front_node == NULL)
        return -1;

    return front_node->data;
}

int is_empty()
{
    if(front_node == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("%d\n", front());

    if(is_empty())
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");

    return 0;
}