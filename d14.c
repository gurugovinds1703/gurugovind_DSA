#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    if(root == NULL)
    {
        root = newnode;
        return;
    }

    struct node *temp = root;
    struct node *parent = NULL;

    while(temp != NULL)
    {
        parent = temp;

        if(data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(data < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;
}

void pre_order_traversal()
{
    struct node *temp = root;

    if(temp == NULL)
        return;


    struct node *stack[100];
    int top = -1;

    stack[++top] = temp;

    while(top != -1)
    {
        struct node *curr = stack[top--];
printf("%d->",curr->data);
        if(curr->right)
            stack[++top] = curr->right;

        if(curr->left)
            stack[++top] = curr->left;
    }
}

int main()
{
    insert(10);
    insert(5);
    insert(20);
    insert(3);
    insert(7);

    pre_order_traversal();

    return 0;
}