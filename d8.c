#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if(head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        struct node *temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
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
    insert_at_beginning(10);
    insert_at_beginning(20);
    insert_at_beginning(30);

    traverse();

    return 0;
}