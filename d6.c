#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if(head == NULL)
    {
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->prev = NULL;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insert_at_end(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    struct node *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}

void insert_after_key(int key, int data)
{
    struct node *temp = head;

    while(temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Key not found\n");
        return;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
    {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
}

void traverse_forward()
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    insert_at_beginning(10);
    insert_at_beginning(20);
    insert_at_beginning(30);

    insert_at_end(40);
    insert_after_key(20, 25);

    traverse_forward();

    return 0;
}