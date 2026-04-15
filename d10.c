#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1;
int capacity = 100;

void push(int data)
{
    if(top == capacity - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = data;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    int x = stack[top];
    top--;
    return x;
}

int peek()
{
    if(top == -1)
        return -1;

    return stack[top];
}

int empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    push(10);
    push(20);
    push(30);

    printf("%d\n", pop());
    printf("%d\n", peek());

    if(empty())
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");

    return 0;
}