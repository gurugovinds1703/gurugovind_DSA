#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_end(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if(head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
        return;
    }

    struct node *temp = head;

    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
}

void delete_node(int data)
{
    if(head == NULL)
        return;

    struct node *temp = head;
    struct node *prev = NULL;

    if(head->data == data)
    {
        if(head->next == head)
        {
            free(head);
            head = NULL;
            return;
        }

        struct node *last = head;

        while(last->next != head)
        {
            last = last->next;
        }

        head = head->next;
        last->next = head;
        free(temp);
        return;
    }

    do
    {
        prev = temp;
        temp = temp->next;
    } while(temp != head && temp->data != data);

    if(temp->data != data)
    {
        printf("Data not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void traverse()
{
    if(head == NULL)
        return;

    struct node *temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("HEAD\n");
}

int main()
{
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);

    delete_node(20);

    traverse();

    return 0;
}