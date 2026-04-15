#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    newnode->next = top;
    top = newnode;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct node *temp = top;
    int x = temp->data;

    top = top->next;
    free(temp);

    return x;
}

int peek()
{
    if(top == NULL)
        return -1;

    return top->data;
}

int empty()
{
    if(top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    push(10);
    push(30);
    push(40);

    printf("%d\n", pop());
    printf("%d\n", peek());

    if(empty())
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");

    return 0;
}